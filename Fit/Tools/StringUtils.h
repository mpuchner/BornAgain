//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Fit/Tools/StringUtils.h
//! @brief     Defines a few helper functions
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#ifndef BORNAGAIN_FIT_TOOLS_STRINGUTILS_H
#define BORNAGAIN_FIT_TOOLS_STRINGUTILS_H

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

//! Utility functions to analyze or modify strings.

namespace mumufit::stringUtils {

//! Returns true if text matches pattern with wildcards '*' and '?'.
bool matchesPattern(const std::string& text, const std::string& wildcardPattern);

//! Split string into vector of string using delimeter.
std::vector<std::string> split(const std::string& text, const std::string& delimeter);

//! Removes multiple occurences of given substring from a string and returns result.
std::string removeSubstring(const std::string& text, const std::string& substr);

//! Returns scientific string representing given value of any numeric type.
template <typename T> std::string scientific(const T value, int n = 10);

//! Returns new string which is lower case of text.
std::string to_lower(std::string text);

template <typename T> std::string scientific(const T value, int n) {
    std::ostringstream out;
    out << std::scientific << std::setprecision(n) << value;
    return out.str();
}

} // namespace mumufit::stringUtils

#endif // BORNAGAIN_FIT_TOOLS_STRINGUTILS_H
