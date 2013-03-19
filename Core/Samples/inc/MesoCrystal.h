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
//! @file      Samples/MesoCrystal.h 
//! @brief     Defines class MesoCrystal.
//
// ************************************************************************** //

#ifndef MESOCRYSTAL_H_
#define MESOCRYSTAL_H_

#include "IClusteredParticles.h"
#include "IFormFactor.h"
#include "Particle.h"

//! A particle with an internal structure of smaller particles

class MesoCrystal : public Particle
{
public:
    MesoCrystal(IClusteredParticles *p_particle_structure, IFormFactor *p_form_factor);
    MesoCrystal(const IClusteredParticles &particle_structure, IFormFactor &form_factor);

    virtual ~MesoCrystal();
    virtual MesoCrystal *clone() const;

    virtual void setAmbientRefractiveIndex(complex_t refractive_index)
    {
        mp_particle_structure->setAmbientRefractiveIndex(refractive_index);
    }

    virtual IFormFactor* createFormFactor() const
    {
        return mp_particle_structure->createTotalFormFactor(*mp_meso_form_factor, m_ambient_refractive_index);
    }

    virtual void setSimpleFormFactor(IFormFactor* p_form_factor)
    {
        if (p_form_factor != mp_meso_form_factor) {
            delete mp_meso_form_factor;
            mp_meso_form_factor = p_form_factor;
        }
    }

    virtual const IFormFactor *getSimpleFormFactor() const { return mp_meso_form_factor;}

    //! @brief get the internal structure, which is in principle unbounded in space (eg.  an infinite crystal)
    const IClusteredParticles *getClusteredParticles() const {return mp_particle_structure; }

    virtual std::vector<DiffuseParticleInfo *> *createDiffuseParticleInfo(const ParticleInfo &parent_info) const;

private:
    IClusteredParticles *mp_particle_structure;
    IFormFactor *mp_meso_form_factor;
};

#endif /* MESOCRYSTAL_H_ */
