//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tests/Functional/Std/StandardTests.h
//! @brief     Provides TEST_F stances that define the BornAgain standard tests.
//!
//!            Each of these stances runs one standard test.
//!            The function run, defined in file Run.cpp, is the same for Core/Py/GUI std tests.
//!            It calls a function checkSimulation that is different for those three test suites.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_TESTS_FUNCTIONAL_STD_STANDARDTESTS_H
#define BORNAGAIN_TESTS_FUNCTIONAL_STD_STANDARDTESTS_H

#include "Tests/GTestWrapper/google_test.h"

class Std : public ::testing::Test {};

TEST_F(Std, FormFactors) {
    EXPECT_TRUE(run("FormFactors", "MiniGISAS", "ParticleInVacuumBuilder", 2e-10));
}

TEST_F(Std, GISASAbsorptiveSLDLayers) {
    EXPECT_TRUE(
        run("GISASAbsorptiveSLDLayers", "MiniGISAS", "LayersWithAbsorptionBySLDBuilder", 2e-10));
}

TEST_F(Std, CylindersAndPrisms) {
    EXPECT_TRUE(run("CylindersAndPrisms", "MiniGISAS", "CylindersAndPrismsBuilder", 2e-10));
}

TEST_F(Std, RadialParaCrystal) {
    EXPECT_TRUE(run("RadialParaCrystal", "MiniGISAS", "RadialParaCrystalBuilder", 2e-10));
}

TEST_F(Std, HardDisk) {
    EXPECT_TRUE(run("HardDisk", "MiniGISAS", "HardDiskBuilder", 2e-10));
}

TEST_F(Std, Basic2DParaCrystal) {
    EXPECT_TRUE(run("Basic2DParaCrystal", "MiniGISAS", "Basic2DParaCrystalBuilder", 2e-10));
}

TEST_F(Std, HexParaCrystal) {
    EXPECT_TRUE(run("HexParaCrystal", "MiniGISAS", "HexParaCrystalBuilder", 2e-10));
}

TEST_F(Std, Lattice1D) {
    EXPECT_TRUE(run("Lattice1D", "MiniGISAS", "Lattice1DBuilder", 2e-10));
}

TEST_F(Std, RectParaCrystal) {
    // TODO: investigate numeric integration, which has become problematic under Windows
    //       after moving code from Core/Tools to Base/Utils
    EXPECT_TRUE(run("RectParaCrystal", "MiniGISAS", "RectParaCrystalBuilder", 1e-9));
}

TEST_F(Std, CoreShellParticle) {
    EXPECT_TRUE(run("CoreShellParticle", "MiniGISAS", "CoreShellParticleBuilder", 2e-10));
}

TEST_F(Std, CoreShellBoxRotateZandY) {
    EXPECT_TRUE(
        run("CoreShellBoxRotateZandY", "MiniGISAS", "CoreShellBoxRotateZandYBuilder", 2e-10));
}

TEST_F(Std, MultiLayerWithRoughness) {
    EXPECT_TRUE(
        run("MultiLayerWithRoughness", "MiniGISAS", "MultiLayerWithRoughnessBuilder", 2e-10));
}

TEST_F(Std, SquareLattice2D) {
    EXPECT_TRUE(run("SquareLattice2D", "MiniGISAS", "SquareLattice2DBuilder", 2e-10));
}

TEST_F(Std, CenteredSquareLattice2D) {
    EXPECT_TRUE(
        run("CenteredSquareLattice2D", "MiniGISAS", "CenteredSquareLattice2DBuilder", 2e-10));
}

TEST_F(Std, RotatedSquareLattice2D) {
    EXPECT_TRUE(run("RotatedSquareLattice2D", "MiniGISAS", "RotatedSquareLattice2DBuilder", 2e-10));
}

TEST_F(Std, FiniteSquareLattice2D) {
    EXPECT_TRUE(run("FiniteSquareLattice2D", "MiniGISAS", "FiniteSquareLattice2DBuilder", 2e-10));
}

TEST_F(Std, RotatedPyramids) {
    EXPECT_TRUE(run("RotatedPyramids", "MiniGISAS", "RotatedPyramidsBuilder", 2e-10));
}

TEST_F(Std, ThickAbsorptiveSampleWithRoughness) {
    EXPECT_TRUE(run("ThickAbsorptiveSampleWithRoughness", "ExtraLongWavelengthGISAS",
                    "ThickAbsorptiveSampleBuilder", 2e-10));
}

TEST_F(Std, ParticleComposition) {
    EXPECT_TRUE(run("ParticleComposition", "MiniGISAS", "ParticleCompositionBuilder", 2e-10));
}

TEST_F(Std, BoxCompositionRotateX) {
    EXPECT_TRUE(run("BoxCompositionRotateX", "MiniGISAS", "BoxCompositionRotateXBuilder", 2e-10));
}

TEST_F(Std, BoxCompositionRotateY) {
    EXPECT_TRUE(run("BoxCompositionRotateY", "MiniGISAS", "BoxCompositionRotateYBuilder", 2e-10));
}

TEST_F(Std, BoxCompositionRotateZ) {
    EXPECT_TRUE(run("BoxCompositionRotateZ", "MiniGISAS", "BoxCompositionRotateZBuilder", 2e-10));
}

TEST_F(Std, BoxCompositionRotateZandY) {
    EXPECT_TRUE(
        run("BoxCompositionRotateZandY", "MiniGISAS", "BoxCompositionRotateZandYBuilder", 2e-10));
}

TEST_F(Std, BoxStackComposition) {
    EXPECT_TRUE(run("BoxStackComposition", "MiniGISAS", "BoxStackCompositionBuilder", 2e-10));
}

TEST_F(Std, CylindersWithSizeDistribution) {
    EXPECT_TRUE(run("CylindersWithSizeDistribution", "MiniGISAS",
                    "CylindersWithSizeDistributionBuilder", 2e-10));
}

TEST_F(Std, TwoTypesCylindersDistribution) {
    EXPECT_TRUE(run("TwoTypesCylindersDistribution", "MiniGISAS",
                    "TwoTypesCylindersDistributionBuilder", 2e-10));
}

TEST_F(Std, RotatedPyramidsDistribution) {
    EXPECT_TRUE(run("RotatedPyramidsDistribution", "MiniGISAS",
                    "RotatedPyramidsDistributionBuilder", 2e-10));
}

TEST_F(Std, SpheresWithLimitsDistribution) {
    EXPECT_TRUE(run("SpheresWithLimitsDistribution", "MiniGISAS",
                    "SpheresWithLimitsDistributionBuilder", 2e-10));
}

TEST_F(Std, ConesWithLimitsDistribution) {
    EXPECT_TRUE(run("ConesWithLimitsDistribution", "MiniGISAS",
                    "ConesWithLimitsDistributionBuilder", 2e-10));
}

TEST_F(Std, LinkedBoxDistribution) {
    EXPECT_TRUE(run("LinkedBoxDistribution", "MiniGISAS", "LinkedBoxDistributionBuilder", 2e-10));
}

TEST_F(Std, BeamDivergence) {
    EXPECT_TRUE(run("BeamDivergence", "MiniGISASBeamDivergence", "CylindersInBABuilder", 2e-10));
}

TEST_F(Std, DetectorResolution) {
    EXPECT_TRUE(
        run("DetectorResolution", "MiniGISASDetectorResolution", "CylindersInBABuilder", 2e-10));
}

TEST_F(Std, MultipleLayout) {
    EXPECT_TRUE(run("MultipleLayout", "MiniGISAS", "MultipleLayoutBuilder", 2e-10));
}

TEST_F(Std, ApproximationDA) {
    EXPECT_TRUE(run("ApproximationDA", "MiniGISAS", "SizeDistributionDAModelBuilder", 2e-10));
}

TEST_F(Std, ApproximationLMA) {
    EXPECT_TRUE(run("ApproximationLMA", "MiniGISAS", "SizeDistributionLMAModelBuilder", 2e-10));
}

TEST_F(Std, ApproximationSSCA) {
    EXPECT_TRUE(run("ApproximationSSCA", "MiniGISAS", "SizeDistributionSSCAModelBuilder", 2e-10));
}

TEST_F(Std, CylindersInSSCA) {
    EXPECT_TRUE(run("CylindersInSSCA", "MiniGISAS", "CylindersInSSCABuilder", 2e-10));
}

TEST_F(Std, CosineRipple) {
    EXPECT_TRUE(run("CosineRipple", "MiniGISAS", "CosineRippleBuilder", 2e-10));
}

TEST_F(Std, TriangularRipple) {
    EXPECT_TRUE(run("TriangularRipple", "MiniGISAS", "TriangularRippleBuilder", 2e-10));
}

TEST_F(Std, AsymRipple) {
    EXPECT_TRUE(run("AsymRipple", "MiniGISAS", "AsymRippleBuilder", 2e-10));
}

TEST_F(Std, MesoCrystal) {
    EXPECT_TRUE(run("MesoCrystal", "MiniGISAS", "MesoCrystalBuilder", 2e-10));
}

TEST_F(Std, CustomMorphology) {
    EXPECT_TRUE(run("CustomMorphology", "MiniGISAS", "CustomMorphologyBuilder", 2e-10));
}

TEST_F(Std, TransformBox) {
    EXPECT_TRUE(run("TransformBox", "MiniGISAS", "TransformBoxBuilder", 1e-10));
}

TEST_F(Std, MagneticParticleZeroField) {
    EXPECT_TRUE(
        run("MagneticParticleZeroField", "MiniGISAS", "MagneticParticleZeroFieldBuilder", 2e-10));
}

TEST_F(Std, MagneticSubstrateZeroField) {
    EXPECT_TRUE(run("MagneticSubstrateZeroField", "MiniGISASPolarizationPP",
                    "MagneticSubstrateZeroFieldBuilder", 2e-10));
}

TEST_F(Std, MagneticRotation) {
    EXPECT_TRUE(
        run("MagneticRotation", "MiniGISASPolarizationPM", "MagneticRotationBuilder", 2e-10));
}

TEST_F(Std, MagneticSpheres) {
    EXPECT_TRUE(run("MagneticSpheres", "MiniGISASPolarizationPM", "MagneticSpheresBuilder", 2e-10));
}

TEST_F(Std, MagneticCylindersPP) {
    EXPECT_TRUE(
        run("MagneticCylindersPP", "MiniGISASPolarizationPP", "MagneticCylindersBuilder", 2e-10));
}

TEST_F(Std, MagneticCylindersPM) {
    EXPECT_TRUE(
        run("MagneticCylindersPM", "MiniGISASPolarizationPM", "MagneticCylindersBuilder", 2e-10));
}

TEST_F(Std, MagneticCylindersMP) {
    EXPECT_TRUE(
        run("MagneticCylindersMP", "MiniGISASPolarizationMP", "MagneticCylindersBuilder", 2e-10));
}

TEST_F(Std, MagneticCylindersMM) {
    EXPECT_TRUE(
        run("MagneticCylindersMM", "MiniGISASPolarizationMM", "MagneticCylindersBuilder", 2e-10));
}

TEST_F(Std, MagneticSpheresInMagLayerPP) {
    EXPECT_TRUE(run("MagneticSpheresInMagLayerPP", "MiniGISASPolarizationPP",
                    "MagneticLayerBuilder", 2e-10));
}

TEST_F(Std, MagneticSpheresInMagLayerMP) {
    EXPECT_TRUE(run("MagneticSpheresInMagLayerMP", "MiniGISASPolarizationMP",
                    "MagneticLayerBuilder", 2e-10));
}

TEST_F(Std, SimulationWithMasks) {
    EXPECT_TRUE(run("SimulationWithMasks", "GISASWithMasks", "CylindersAndPrismsBuilder", 1e-10));
}

TEST_F(Std, RectDetectorGeneric) {
    EXPECT_TRUE(run("RectDetectorGeneric", "RectDetectorGeneric", "CylindersInBABuilder", 1e-10));
}

TEST_F(Std, RectDetectorPerpToSample) {
    EXPECT_TRUE(
        run("RectDetectorPerpToSample", "RectDetectorPerpToSample", "CylindersInBABuilder", 1e-10));
}

TEST_F(Std, RectDetectorPerpToDirectBeam) {
    EXPECT_TRUE(run("RectDetectorPerpToDirectBeam", "RectDetectorPerpToDirectBeam",
                    "CylindersInBABuilder", 1e-10));
}

TEST_F(Std, RectDetectorPerpToReflectedBeam) {
    EXPECT_TRUE(run("RectDetectorPerpToReflectedBeam", "RectDetectorPerpToReflectedBeam",
                    "CylindersInBABuilder", 1e-10));
}

TEST_F(Std, RectDetectorPerpToReflectedBeamDpos) {
    EXPECT_TRUE(run("RectDetectorPerpToReflectedBeamDpos", "RectDetectorPerpToReflectedBeamDpos",
                    "CylindersInBABuilder", 1e-10));
}

TEST_F(Std, LargeCylindersMonteCarlo) {
    EXPECT_TRUE(run("LargeCylindersMonteCarlo", "MiniGISASMonteCarlo",
                    "LargeCylindersInDWBABuilder", 5e-1));
}

TEST_F(Std, SphericalDetWithRoi) {
    EXPECT_TRUE(
        run("SphericalDetWithRoi", "SphericalDetWithRoi", "CylindersAndPrismsBuilder", 1e-10));
}

TEST_F(Std, RectDetWithRoi) {
    EXPECT_TRUE(run("RectDetWithRoi", "RectDetWithRoi", "CylindersAndPrismsBuilder", 1e-10));
}

TEST_F(Std, BoxesWithSpecular) {
    EXPECT_TRUE(
        run("BoxesWithSpecular", "MiniGISASSpecular", "BoxesSquareLattice2DBuilder", 1e-10));
}

TEST_F(Std, RotatedCylinder) {
    EXPECT_TRUE(run("RotatedCylinder", "MiniGISAS", "RotatedCylindersBuilder", 1e-10));
}

TEST_F(Std, SlicedComposition) {
    EXPECT_TRUE(run("SlicedComposition", "MiniGISAS", "SlicedCompositionBuilder", 1e-10));
}

TEST_F(Std, ConstantBackground) {
    EXPECT_TRUE(run("ConstantBackground", "ConstantBackground", "CylindersInBABuilder", 1e-10));
}

TEST_F(Std, HomogeneousTiNiSample) {
    EXPECT_TRUE(
        run("HomogeneousTiNiSample", "BasicSpecular", "HomogeneousMultilayerBuilder", 1e-10));
}

TEST_F(Std, HomogeneousTiNiSampleWithAbsorption) {
    EXPECT_TRUE(run("HomogeneousTiNiSampleWithAbsorption", "BasicSpecular",
                    "PlainMultiLayerBySLDBuilder", 1e-10));
}

TEST_F(Std, RoughnessInSpecular) {
    EXPECT_TRUE(
        run("RoughnessInSpecular", "BasicSpecular", "MultiLayerWithRoughnessBuilder", 2e-9));
}

TEST_F(Std, GaussianBeamFootprint) {
    EXPECT_TRUE(run("GaussianBeamFootprint", "SpecularWithGaussianBeam",
                    "HomogeneousMultilayerBuilder", 1e-10));
}

TEST_F(Std, SquareBeamFootprint) {
    EXPECT_TRUE(run("SquareBeamFootprint", "SpecularWithSquareBeam", "HomogeneousMultilayerBuilder",
                    1e-10));
}

TEST_F(Std, SpecularDivergentBeam) {
    EXPECT_TRUE(run("SpecularDivergentBeam", "SpecularDivergentBeam",
                    "HomogeneousMultilayerBuilder", 1e-10));
}

//  ************************************************************************************************
//  TODO: broken under GUI
//  ************************************************************************************************

#ifndef GUI_STD_TEST

TEST_F(Std, RelativeResolutionTOF) {
    EXPECT_TRUE(run("RelativeResolutionTOF", "TOFRWithRelativeResolution",
                    "PlainMultiLayerBySLDBuilder", 1e-10));
}

#endif // GUI_STD_TEST

//  ************************************************************************************************
//  TODO: broken under Python
//  ************************************************************************************************

#ifndef PYTHON_STD_TEST

TEST_F(Std, OffSpecularResonator) {
    EXPECT_TRUE(run("OffSpecularResonator", "OffSpecMini", "ResonatorBuilder", 1e-10));
}

TEST_F(Std, FormFactorsWithAbsorption) {
    EXPECT_TRUE(
        run("FormFactorsWithAbsorption", "MiniGISAS_v2", "LayersWithAbsorptionBuilder", 2e-10));
}
#endif // PYTHON_STD_TEST

//  ************************************************************************************************
//  TODO: broken under GUI and Python
//  ************************************************************************************************

#ifndef PYTHON_STD_TEST
#ifndef GUI_STD_TEST

TEST_F(Std, NCRoughnessInSpecular) {
    EXPECT_TRUE(
        run("NCRoughnessInSpecular", "BasicSpecular", "MultiLayerWithNCRoughnessBuilder", 2e-9));
}

TEST_F(Std, SuperLattice) {
    EXPECT_TRUE(run("SuperLattice", "MiniGISAS", "SuperLatticeBuilder", 2e-10));
}

TEST_F(Std, SpecularWithSlicing) {
    EXPECT_TRUE(run("SpecularWithSlicing_01", "BasicSpecular", "SlicedCylindersBuilder", 1e-10));
    EXPECT_TRUE(run("SpecularWithSlicing_02", "BasicSpecular", "SLDSlicedCylindersBuilder", 1e-10));
    EXPECT_TRUE(
        run("SpecularWithSlicing_03", "BasicSpecular", "AveragedSlicedCylindersBuilder", 1e-10));
    EXPECT_TRUE(
        run("SpecularWithSlicing_Q2", "BasicSpecularQ", "SLDSlicedCylindersBuilder", 1e-10));
}

TEST_F(Std, InstrumentDefinitionComparison) {
    EXPECT_TRUE(run("InstrumentDefinitionComparison_0", "BasicSpecular",
                    "PlainMultiLayerBySLDBuilder", 1e-10));
    EXPECT_TRUE(run("InstrumentDefinitionComparison_Q", "BasicSpecularQ",
                    "PlainMultiLayerBySLDBuilder", 1e-10));
}

TEST_F(Std, TOFResolutionComparison) {
    EXPECT_TRUE(run("TOFResolutionComparison_TR", "TOFRWithRelativeResolution",
                    "PlainMultiLayerBySLDBuilder", 1e-10));
    EXPECT_TRUE(run("TOFResolutionComparison_TP", "TOFRWithPointwiseResolution",
                    "PlainMultiLayerBySLDBuilder", 1e-10));
}

TEST_F(Std, BasicSpecularPP) {
    EXPECT_TRUE(run("BasicSpecularPP", "BasicSpecularPP", "SimpleMagneticLayerBuilder", 1e-10));
}

TEST_F(Std, BasicSpecularMM) {
    EXPECT_TRUE(run("BasicSpecularMM", "BasicSpecularMM", "SimpleMagneticLayerBuilder", 1e-10));
}

TEST_F(Std, PolarizedQAngleReflectivityPP) {
    EXPECT_TRUE(run("PolarizedQAngleReflectivityPP_0", "BasicSpecularPP",
                    "SimpleMagneticLayerBuilder", 1e-10));
    EXPECT_TRUE(run("PolarizedQAngleReflectivityPP_Q", "BasicQSpecularPP",
                    "SimpleMagneticLayerBuilder", 1e-10));
}

TEST_F(Std, PolarizedQAngleReflectivityMM) {
    EXPECT_TRUE(run("PolarizedQAngleReflectivityMM_0", "BasicSpecularMM",
                    "SimpleMagneticLayerBuilder", 1e-10));
    EXPECT_TRUE(run("PolarizedQAngleReflectivityMM_Q", "BasicQSpecularMM",
                    "SimpleMagneticLayerBuilder", 1e-10));
}

TEST_F(Std, MagneticRotationReflectivity) {
    EXPECT_TRUE(run("MagneticRotationReflectivityPP", "BasicSpecularPP",
                    "SimpleMagneticRotationBuilder", 1e-10));
    EXPECT_TRUE(run("MagneticRotationReflectivityMM", "BasicSpecularMM",
                    "SimpleMagneticRotationBuilder", 1e-10));
    EXPECT_TRUE(run("MagneticRotationReflectivityPM", "BasicSpecularPM",
                    "SimpleMagneticRotationBuilder", 1e-10));
    EXPECT_TRUE(run("MagneticRotationReflectivityMP", "BasicSpecularMP",
                    "SimpleMagneticRotationBuilder", 1e-10));
}

TEST_F(Std, PolarizedFeNiBilayerPP) {
    EXPECT_TRUE(run("PolarizedFeNiBilayerPP", "BasicSpecularPP", "FeNiBilayerBuilder", 1e-7));
    EXPECT_TRUE(run("PolarizedFeNiBilayerPP_Q", "BasicQSpecularPP", "FeNiBilayerBuilder", 1e-7));
}

TEST_F(Std, PolarizedFeNiBilayerMM) {
    EXPECT_TRUE(run("PolarizedFeNiBilayerMM", "BasicSpecularMM", "FeNiBilayerBuilder", 1e-7));
    EXPECT_TRUE(run("PolarizedFeNiBilayerMM_Q", "BasicQSpecularMM", "FeNiBilayerBuilder", 1e-7));
}

TEST_F(Std, PolarizedFeNiBilayerTanhPP) {
    EXPECT_TRUE(
        run("PolarizedFeNiBilayerTanhPP", "BasicSpecularPP", "FeNiBilayerTanhBuilder", 1e-7));
    EXPECT_TRUE(
        run("PolarizedFeNiBilayerTanhPP_Q", "BasicQSpecularPP", "FeNiBilayerTanhBuilder", 1e-7));
}

TEST_F(Std, PolarizedFeNiBilayerTanhMM) {
    EXPECT_TRUE(
        run("PolarizedFeNiBilayerTanhMM", "BasicSpecularMM", "FeNiBilayerTanhBuilder", 1e-7));
    EXPECT_TRUE(
        run("PolarizedFeNiBilayerTanhMM_Q", "BasicQSpecularMM", "FeNiBilayerTanhBuilder", 1e-7));
}

TEST_F(Std, PolarizedFeNiBilayerNCPP) {
    EXPECT_TRUE(run("PolarizedFeNiBilayerNCPP", "BasicSpecularPP", "FeNiBilayerNCBuilder", 1e-7));
    EXPECT_TRUE(
        run("PolarizedFeNiBilayerNCPP_Q", "BasicQSpecularPP", "FeNiBilayerNCBuilder", 1e-7));
}

TEST_F(Std, PolarizedFeNiBilayerNCMM) {
    EXPECT_TRUE(run("PolarizedFeNiBilayerNCMM", "BasicSpecularMM", "FeNiBilayerTanhBuilder", 1e-7));
    EXPECT_TRUE(
        run("PolarizedFeNiBilayerNCMM_Q", "BasicQSpecularMM", "FeNiBilayerNCBuilder", 1e-7));
}

TEST_F(Std, PolarizedFeNiBilayerSpinFlipPP) {
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipPP", "BasicSpecularPP",
                    "FeNiBilayerSpinFlipBuilder", 1e-7));
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipPP_Q", "BasicQSpecularPP",
                    "FeNiBilayerSpinFlipBuilder", 1e-7));
}

TEST_F(Std, PolarizedFeNiBilayerSpinFlipMM) {
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipMM", "BasicSpecularMM",
                    "FeNiBilayerSpinFlipBuilder", 1e-7));
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipMM_Q", "BasicQSpecularMM",
                    "FeNiBilayerSpinFlipBuilder", 1e-7));
}

TEST_F(Std, PolarizedFeNiBilayerSpinFlipPM) {
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipPM", "BasicSpecularPM",
                    "FeNiBilayerSpinFlipBuilder", 1e-7));
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipPM_Q", "BasicQSpecularPM",
                    "FeNiBilayerSpinFlipBuilder", 1e-7));
}

TEST_F(Std, PolarizedFeNiBilayerSpinFlipMP) {
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipMP", "BasicSpecularMP",
                    "FeNiBilayerSpinFlipBuilder", 1e-7));
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipMP_Q", "BasicQSpecularMP",
                    "FeNiBilayerSpinFlipBuilder", 1e-7));
}

TEST_F(Std, PolarizedFeNiBilayerSpinFlipTanhPP) {
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipTanhPP", "BasicSpecularPP",
                    "FeNiBilayerSpinFlipTanhBuilder", 1e-7));
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipTanhPP_Q", "BasicQSpecularPP",
                    "FeNiBilayerSpinFlipTanhBuilder", 1e-7));
}

TEST_F(Std, PolarizedFeNiBilayerSpinFlipTanhMM) {
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipTanhMM", "BasicSpecularMM",
                    "FeNiBilayerSpinFlipTanhBuilder", 1e-7));
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipTanhMM_Q", "BasicQSpecularMM",
                    "FeNiBilayerSpinFlipTanhBuilder", 1e-7));
}

TEST_F(Std, PolarizedFeNiBilayerSpinFlipTanhPM) {
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipTanhPM", "BasicSpecularPM",
                    "FeNiBilayerSpinFlipTanhBuilder", 1e-7));
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipTanhPM_Q", "BasicQSpecularPM",
                    "FeNiBilayerSpinFlipTanhBuilder", 1e-7));
}

TEST_F(Std, PolarizedFeNiBilayerSpinFlipTanhMP) {
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipTanhMP", "BasicSpecularMP",
                    "FeNiBilayerSpinFlipTanhBuilder", 1e-7));
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipTanhMP_Q", "BasicQSpecularMP",
                    "FeNiBilayerSpinFlipTanhBuilder", 1e-7));
}

TEST_F(Std, PolarizedFeNiBilayerSpinFlipNCPP) {
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipNCPP", "BasicSpecularPP",
                    "FeNiBilayerSpinFlipNCBuilder", 1e-7));
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipNCPP_Q", "BasicQSpecularPP",
                    "FeNiBilayerSpinFlipNCBuilder", 1e-7));
}

TEST_F(Std, PolarizedFeNiBilayerSpinFlipNCMM) {
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipNCMM", "BasicSpecularMM",
                    "FeNiBilayerSpinFlipNCBuilder", 1e-7));
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipNCMM_Q", "BasicQSpecularMM",
                    "FeNiBilayerSpinFlipNCBuilder", 1e-7));
}

TEST_F(Std, PolarizedFeNiBilayerSpinFlipNCPM) {
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipNCPM", "BasicSpecularPM",
                    "FeNiBilayerSpinFlipNCBuilder", 1e-7));
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipNCPM_Q", "BasicQSpecularPM",
                    "FeNiBilayerSpinFlipNCBuilder", 1e-7));
}

TEST_F(Std, PolarizedFeNiBilayerSpinFlipNCMP) {
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipNCMP", "BasicSpecularMP",
                    "FeNiBilayerSpinFlipNCBuilder", 1e-7));
    EXPECT_TRUE(run("PolarizedFeNiBilayerSpinFlipNCMP_Q", "BasicQSpecularMP",
                    "FeNiBilayerSpinFlipNCBuilder", 1e-7));
}

TEST_F(Std, DepthProbeTest) {
    EXPECT_TRUE(run("DepthProbeTest", "BasicDepthProbe", "HomogeneousMultilayerBuilder", 1e-10));
}

#endif // GUI_STD_TEST
#endif // PYTHON_STD_TEST

#endif // BORNAGAIN_TESTS_FUNCTIONAL_STD_STANDARDTESTS_H
