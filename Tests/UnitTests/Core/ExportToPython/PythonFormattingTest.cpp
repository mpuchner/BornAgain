#include "Core/Export/PythonFormatting.h"
#include "Core/Binning/FixedBinAxis.h"
#include "Core/Binning/PointwiseAxis.h"
#include "Core/Parametrization/Distributions.h"
#include "Core/Parametrization/ParameterDistribution.h"
#include "Core/Parametrization/Units.h"
#include "Fit/Tools/RealLimits.h"
#include "Tests/UnitTests/utilities/google_test.h"

class PythonFormattingTest : public ::testing::Test
{
};

TEST_F(PythonFormattingTest, ValueTimesUnits)
{
    EXPECT_EQ("2.0*nm", PythonFormatting::printValue(2.0, "nm"));
    EXPECT_EQ("2.0*deg", PythonFormatting::printValue(2.0 * Units::deg, "rad"));
    EXPECT_EQ("2.0", PythonFormatting::printValue(2.0, ""));
}

TEST_F(PythonFormattingTest, RealLimits)
{
    EXPECT_EQ("RealLimits.positive()", PythonFormatting::printRealLimits(RealLimits::positive()));

    EXPECT_EQ("RealLimits.nonnegative()",
              PythonFormatting::printRealLimits(RealLimits::nonnegative()));

    EXPECT_EQ("RealLimits.lowerLimited(1.0)",
              PythonFormatting::printRealLimits(RealLimits::lowerLimited(1.0)));
    EXPECT_EQ("RealLimits.lowerLimited(1.0*nm)",
              PythonFormatting::printRealLimits(RealLimits::lowerLimited(1.0), "nm"));
    EXPECT_EQ("RealLimits.lowerLimited(1.0*deg)",
              PythonFormatting::printRealLimits(RealLimits::lowerLimited(1.0 * Units::deg),
                                                "rad"));

    EXPECT_EQ("RealLimits.upperLimited(1.0)",
              PythonFormatting::printRealLimits(RealLimits::upperLimited(1.0)));
    EXPECT_EQ("RealLimits.upperLimited(1.0*nm)",
              PythonFormatting::printRealLimits(RealLimits::upperLimited(1.0), "nm"));
    EXPECT_EQ("RealLimits.upperLimited(1.0*deg)",
              PythonFormatting::printRealLimits(RealLimits::upperLimited(1.0 * Units::deg),
                                                "rad"));

    EXPECT_EQ("RealLimits.limited(1.0, 2.0)",
              PythonFormatting::printRealLimits(RealLimits::limited(1.0, 2.0)));
    EXPECT_EQ("RealLimits.limited(1.0*nm, 2.0*nm)",
              PythonFormatting::printRealLimits(RealLimits::limited(1.0, 2.0), "nm"));
    EXPECT_EQ("RealLimits.limited(1.0*deg, 2.0*deg)",
              PythonFormatting::printRealLimits(
                  RealLimits::limited(1.0 * Units::deg, 2.0 * Units::deg), "rad"));

    // testing printing of real limits in the context of ParameterDistribution and similar
    EXPECT_EQ(", ba.RealLimits.limited(1.0*deg, 2.0*deg)",
              PythonFormatting::printRealLimitsArg(
                  RealLimits::limited(1.0 * Units::deg, 2.0 * Units::deg), "rad"));

    EXPECT_EQ("", PythonFormatting::printRealLimitsArg(RealLimits::limitless()));
}

TEST_F(PythonFormattingTest, printDistribution)
{
    EXPECT_EQ(PythonFormatting::printDistribution(DistributionGate(1.0, 2.0)),
              "ba.DistributionGate(1.0, 2.0)");

    EXPECT_EQ(PythonFormatting::printDistribution(DistributionGate(1.0, 2.0), "nm"),
              "ba.DistributionGate(1.0*nm, 2.0*nm)");

    EXPECT_EQ(PythonFormatting::printDistribution(
                  DistributionGate(1.0 * Units::deg, 2.0 * Units::deg), "rad"),
              "ba.DistributionGate(1.0*deg, 2.0*deg)");

    EXPECT_EQ(PythonFormatting::printDistribution(DistributionLogNormal(1.0 * Units::deg, 0.01),
                                                  "rad"),
              "ba.DistributionLogNormal(1.0*deg, 0.01)");
}

TEST_F(PythonFormattingTest, printParameterDistribution)
{

    DistributionGate gate(1.0, 2.0);
    ParameterDistribution dist("ParName", gate, 5, 2.0);

    // No RealLimits defined
    EXPECT_EQ(PythonFormatting::printParameterDistribution(dist, "distr_1"),
              "ba.ParameterDistribution(\"ParName\", distr_1, 5, 2.0)");

    // RealLimits defined, units unknown
    ParameterDistribution dist2("ParName", gate, 5, 2.0, RealLimits::limited(1.0, 2.0));
    EXPECT_EQ(PythonFormatting::printParameterDistribution(dist2, "distr_1"),
              "ba.ParameterDistribution(\"ParName\", distr_1, "
              "5, 2.0, ba.RealLimits.limited(1.0, 2.0))");

    // RealLimits defined, units explicetely set
    ParameterDistribution dist3("ParName", gate, 5, 2.0, RealLimits::limited(1.0, 2.0));
    EXPECT_EQ(PythonFormatting::printParameterDistribution(dist3, "distr_1", "nm"),
              "ba.ParameterDistribution(\"ParName\", distr_1, "
              "5, 2.0, ba.RealLimits.limited(1.0*nm, 2.0*nm))");

    // RealLimits defined, checking that method guess radians units correctly
    ParameterDistribution dist4("/Particle/ZRotation/Angle", gate, 5, 2.0,
                                RealLimits::limited(1.0 * Units::deg, 2.0 * Units::deg));
    EXPECT_EQ(PythonFormatting::printParameterDistribution(dist4, "distr_1", "rad"),
              "ba.ParameterDistribution(\"/Particle/ZRotation/Angle\", "
              "distr_1, 5, 2.0, ba.RealLimits.limited(1.0*deg, 2.0*deg))");
}

TEST_F(PythonFormattingTest, printAxis)
{
    FixedBinAxis axis1("axis0", 10, -1.0, 2.0);
    EXPECT_EQ(PythonFormatting::printAxis(axis1, "", 0),
              "ba.FixedBinAxis(\"axis0\", 10, -1.0, 2.0)");

    FixedBinAxis axis2("axis0", 10, -1.0 * Units::deg, 2.0 * Units::deg);
    EXPECT_EQ(PythonFormatting::printAxis(axis2, "rad", 0),
              "ba.FixedBinAxis(\"axis0\", 10, -1.0*deg, 2.0*deg)");

    PointwiseAxis axis3("axis3",
                        std::vector<double>{1.0 * Units::deg, 2.0 * Units::deg, 3.0 * Units::deg});
    EXPECT_EQ(PythonFormatting::printAxis(axis3, "rad", 0),
              "numpy.asarray([1.0*deg,\n"
              "               2.0*deg,\n"
              "               3.0*deg])");
}
