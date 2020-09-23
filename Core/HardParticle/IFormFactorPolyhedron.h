// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/HardParticle/IFormFactorPolyhedron.h
//! @brief     Defines class IFormFactorPolyhedron.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BORNAGAIN_CORE_HARDPARTICLE_FORMFACTORPOLYHEDRON_H
#define BORNAGAIN_CORE_HARDPARTICLE_FORMFACTORPOLYHEDRON_H

#include "Core/HardParticle/PolyhedralComponents.h"
#include "Core/HardParticle/PolyhedralTopology.h"
#include "Core/Scattering/IFormFactorBorn.h"
#include <memory>

//! A polyhedron, implementation class for use in IFormFactorPolyhedron

class Polyhedron
{
public:
    Polyhedron(const PolyhedralTopology& topology, double z_bottom,
               const std::vector<kvector_t>& vertices);
    void assert_platonic() const;
    double volume() const;
    double radius() const;
    const std::vector<kvector_t>& vertices(); //! needed for topZ, bottomZ computation
    complex_t evaluate_for_q(const cvector_t& q) const;
    complex_t evaluate_centered(const cvector_t& q) const;

private:
    double m_z_bottom;
    bool m_sym_Ci; //!< if true, then faces obtainable by inversion are not provided

    std::vector<PolyhedralFace> m_faces;
    double m_radius;
    double m_volume;
    std::vector<kvector_t> m_vertices; //! for topZ, bottomZ computation only
};

//! A polyhedron, for form factor computation.

class BA_CORE_API_ IFormFactorPolyhedron : public IFormFactorBorn
{
public:
#ifdef POLYHEDRAL_DIAGNOSTIC
    static void setLimits(double _q, int _n);
#endif

    IFormFactorPolyhedron() {}
    IFormFactorPolyhedron(const NodeMeta& meta, const std::vector<double>& PValues);

    double bottomZ(const IRotation& rotation) const override final;
    double topZ(const IRotation& rotation) const override final;

    complex_t evaluate_for_q(cvector_t q) const override final;
    complex_t evaluate_centered(cvector_t q) const;

    double volume() const override final;
    double radialExtension() const override final;
    void assert_platonic() const;

protected:
    void setPolyhedron(const PolyhedralTopology& topology, double z_bottom,
                       const std::vector<kvector_t>& vertices);

private:
    std::unique_ptr<Polyhedron> pimpl;
};

#endif // BORNAGAIN_CORE_HARDPARTICLE_FORMFACTORPOLYHEDRON_H
