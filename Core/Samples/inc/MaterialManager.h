// ************************************************************************** //
//                                                                           
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @copyright Forschungszentrum Jülich GmbH 2013
//             
//  Homepage:  apps.jcns.fz-juelich.de/BornAgain
//  License:   GNU General Public License v3 or higher (see COPYING)
//
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke 
//
//! @file      Samples/MaterialManager.h 
//! @brief     Defines class MaterialManager.
//
// ************************************************************************** //

#ifndef MATERIALMANAGER_H
#define MATERIALMANAGER_H

#include <iostream>
#include <string>
#include <map>
#include "Exceptions.h"
#include "IMaterial.h"
#include "ISingleton.h"
#include "HomogeneousMaterial.h"

//! Manager of materials used in simulation.
//!
//! It is a singleton which provides common and unique interface for
//! material creation and access. No thread safety.

class MaterialManager: public ISingleton<MaterialManager>
{
public:
    virtual ~MaterialManager() { clear(); }

    //! definition of materials container
    typedef std::map<std::string, IMaterial *> materials_t;

    //! return material from database
    const IMaterial *getMaterial(const std::string &name);

    //! add material to the database
    const IMaterial *addHomogeneousMaterial(const std::string &name, const complex_t &refractive_index);

    //! add material to the database
    const IMaterial *addHomogeneousMaterial(const std::string &name, double refractive_index_real, double refractive_index_imag);

    //! clean collection of material
    void clear();

    //! print material class
    friend std::ostream &operator<<(std::ostream &ostr, const MaterialManager &m) { m.print(ostr); return ostr; }

protected:
    MaterialManager(){}
    friend class ISingleton<MaterialManager >;

    //! print material class
    virtual void print(std::ostream &ostr) const;

    materials_t m_materials; //! container with defined materials
};

#endif // MATERIALMANAGER_H
