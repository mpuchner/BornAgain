//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Device/InputOutput/OutputDataReader.cpp
//! @brief     Implements class OutputDataReader.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#include "Device/InputOutput/OutputDataReader.h"
#include "Base/Utils/FileSystemUtils.h"
#include "Device/Data/OutputData.h"
#include "Device/InputOutput/DataFormatUtils.h"

#ifdef _WIN32
#pragma warning(push)
#pragma warning(disable : 4244 4275)
#include "Device/InputOutput/boost_streams.h"
#pragma warning(pop)
#else
#include "Device/InputOutput/boost_streams.h"
#endif

#include <fstream>

namespace {

std::stringstream getFromFilteredStream(std::istream& input_stream, const std::string& fname) {
    boost::iostreams::filtering_streambuf<boost::iostreams::input> input_filtered;
    if (DataFormatUtils::isGZipped(fname))
        input_filtered.push(boost::iostreams::gzip_decompressor());
    else if (DataFormatUtils::isBZipped(fname))
        input_filtered.push(boost::iostreams::bzip2_decompressor());
    input_filtered.push(input_stream);
    // we use stringstream since it provides random access which is important for tiff files
    std::stringstream ret;
    boost::iostreams::copy(input_filtered, ret);
    return ret;
}

} // namespace

OutputDataReader::OutputDataReader(const std::string& file_name) : m_file_name(file_name) {}

OutputData<double>* OutputDataReader::getOutputData() {
    using namespace DataFormatUtils;
    if (!m_read_strategy)
        throw std::runtime_error(
            "OutputDataReader::getOutputData() -> Error! No read strategy defined");

    std::ifstream fin;
    std::ios_base::openmode openmode = std::ios::in;
    if (isTiffFile(m_file_name) || isCompressed(m_file_name))
        openmode = std::ios::in | std::ios_base::binary;

#ifdef _WIN32
    fin.open(FileSystemUtils::convert_utf8_to_utf16(m_file_name), openmode);
#else
    fin.open(m_file_name, openmode);
#endif

    if (!fin.is_open())
        throw std::runtime_error("OutputDataReader::getOutputData() -> Error. Can't open file '"
                                 + m_file_name + "' for reading.");
    if (!fin.good())
        throw std::runtime_error("OutputDataReader::getOutputData() -> Error! "
                                 "File is not good, probably it is a directory.");

    std::stringstream strstream = getFromFilteredStream(fin, m_file_name);

    OutputData<double>* result = m_read_strategy->readOutputData(strstream);

    return result;
}

void OutputDataReader::setStrategy(IOutputDataReadStrategy* read_strategy) {
    m_read_strategy.reset(read_strategy);
}
