// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Tools/CloneableVector.h
//! @brief     Defines and implements templated class CloneableVector.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BORNAGAIN_CORE_TOOLS_CLONEABLEVECTOR_H
#define BORNAGAIN_CORE_TOOLS_CLONEABLEVECTOR_H

#include <memory>
#include <vector>

//! A vector of unique pointers to objects that are cloneable.
//!
//! Equips vector<unique_ptr<T>> with copy constructor.
//! For use with polymorphic objects, or in pimpl idiom.
//!
//! @ingroup tools_internal

//! The objects pointed to must posses a clone() function.

template <class T> class CloneableVector : public std::vector<std::unique_ptr<T>>
{
    using super = std::vector<std::unique_ptr<T>>;

public:
    CloneableVector() : super() {}
    CloneableVector(const CloneableVector& other) : super()
    {
        super::reserve(other.size());
        for (const std::unique_ptr<T>& t : other)
            this->push_back(t->clone());
    }
    void push_back(T* t) { super::push_back(std::unique_ptr<T>(t)); }
};

#endif // BORNAGAIN_CORE_TOOLS_CLONEABLEVECTOR_H
