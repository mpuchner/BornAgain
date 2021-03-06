//  ************************************************************************************************
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Export/SampleLabelHandler.cpp
//! @brief     Implement class SampleLabelHandler.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
//  ************************************************************************************************

#include "Core/Export/SampleLabelHandler.h"
#include "Sample/Aggregate/IInterferenceFunction.h"
#include "Sample/Multilayer/MultiLayer.h"
#include "Sample/Particle/MesoCrystal.h"
#include "Sample/Particle/Particle.h"
#include "Sample/Particle/ParticleComposition.h"
#include "Sample/Particle/ParticleCoreShell.h"
#include "Sample/Particle/ParticleDistribution.h"
#include "Sample/Slice/LayerRoughness.h"
#include <set>

std::string SampleLabelHandler::labelCrystal(const Crystal* cr) {
    return m_CrystalLabel[cr];
}

std::string SampleLabelHandler::labelFormFactor(const IFormFactor* ff) {
    return m_FormFactorLabel[ff];
}

std::string SampleLabelHandler::labelInterferenceFunction(const IInterferenceFunction* iff) {
    return m_InterferenceFunctionLabel[iff];
}

std::string SampleLabelHandler::labelLayer(const Layer* layer) {
    return m_LayerLabel[layer];
}

std::string SampleLabelHandler::labelLayout(const ParticleLayout* layout) {
    return m_ParticleLayoutLabel[layout];
}

std::string SampleLabelHandler::labelMaterial(const Material* mat) {
    return m_MaterialLabel[mat];
}

std::string SampleLabelHandler::labelLattice2D(const Lattice2D* lat) {
    return m_Lattice2DLabel[lat];
}

std::string SampleLabelHandler::labelLattice3D(const Lattice3D* lat) {
    return m_Lattice3DLabel[lat];
}

std::string SampleLabelHandler::labelMultiLayer(const MultiLayer* ml) {
    return m_MultiLayerLabel[ml];
}

std::string SampleLabelHandler::labelParticle(const IAbstractParticle* absparticle) {
    if (const auto core_shell_particle = dynamic_cast<const ParticleCoreShell*>(absparticle))
        return m_ParticleCoreShellLabel[core_shell_particle];
    if (const auto particle = dynamic_cast<const Particle*>(absparticle))
        return m_ParticleLabel[particle];
    if (const auto particle = dynamic_cast<const ParticleDistribution*>(absparticle))
        return m_ParticleDistributionLabel[particle];
    if (const auto lattice_basis = dynamic_cast<const ParticleComposition*>(absparticle))
        return m_ParticleCompositionLabel[lattice_basis];
    if (const auto mesocrystal = dynamic_cast<const MesoCrystal*>(absparticle))
        return m_MesoCrystalLabel[mesocrystal];
    throw std::runtime_error("SampleLabelHandler::getLabel: called for unknown IParticle type");
}

std::string SampleLabelHandler::labelRotation(const IRotation* rot) {
    return m_RotationsLabel[rot];
}

std::string SampleLabelHandler::labelRoughness(const LayerRoughness* roughness) {
    return m_LayerRoughnessLabel[roughness];
}

void SampleLabelHandler::insertCrystal(const Crystal* sample) {
    std::string label = "crystal_" + std::to_string(m_CrystalLabel.size() + 1);
    m_CrystalLabel.insert(sample, label);
}

void SampleLabelHandler::insertFormFactor(const IFormFactor* sample) {
    std::string label = "formFactor_" + std::to_string(m_FormFactorLabel.size() + 1);
    m_FormFactorLabel.insert(sample, label);
}

void SampleLabelHandler::insertInterferenceFunction(const IInterferenceFunction* sample) {
    std::string label = "interference_" + std::to_string(m_InterferenceFunctionLabel.size() + 1);
    m_InterferenceFunctionLabel.insert(sample, label);
}

void SampleLabelHandler::insertLattice2D(const Lattice2D* sample) {
    std::string label = "lattice2D_" + std::to_string(m_Lattice2DLabel.size() + 1);
    m_Lattice2DLabel.insert(sample, label);
}

void SampleLabelHandler::insertLattice3D(const Lattice3D* sample) {
    std::string label = "lattice3D_" + std::to_string(m_Lattice3DLabel.size() + 1);
    m_Lattice3DLabel.insert(sample, label);
}

void SampleLabelHandler::insertLayer(const Layer* sample) {
    std::string label = "layer_" + std::to_string(m_LayerLabel.size() + 1);
    m_LayerLabel.insert(sample, label);
}

void SampleLabelHandler::insertLayout(const ParticleLayout* sample) {
    std::string label = "layout_" + std::to_string(m_ParticleLayoutLabel.size() + 1);
    m_ParticleLayoutLabel.insert(sample, label);
}

void SampleLabelHandler::insertMaterial(const Material* mat) {
    for (auto it = m_MaterialLabel.begin(); it != m_MaterialLabel.end(); ++it) {
        if (*(it->first) == *mat) {
            m_MaterialLabel.insert(mat, it->second);
            return;
        }
    }
    // material not found => create new label
    std::set<std::string> unique_labels;
    for (auto it = m_MaterialLabel.begin(); it != m_MaterialLabel.end(); ++it)
        unique_labels.insert(it->second);

    std::string label = "material_" + std::to_string(unique_labels.size() + 1);
    m_MaterialLabel.insert(mat, label);
}

void SampleLabelHandler::insertMesoCrystal(const MesoCrystal* sample) {
    std::string label = "mesocrystal_" + std::to_string(m_MesoCrystalLabel.size() + 1);
    m_MesoCrystalLabel.insert(sample, label);
}

void SampleLabelHandler::insertMultiLayer(const MultiLayer* sample) {
    std::string label = "multiLayer_" + std::to_string(m_MultiLayerLabel.size() + 1);
    m_MultiLayerLabel.insert(sample, label);
}

void SampleLabelHandler::insertParticleComposition(const ParticleComposition* sample) {
    std::string label =
        "particleComposition_" + std::to_string(m_ParticleCompositionLabel.size() + 1);
    m_ParticleCompositionLabel.insert(sample, label);
}

void SampleLabelHandler::insertParticleDistribution(const ParticleDistribution* sample) {
    std::string label =
        "particleDistribution_" + std::to_string(m_ParticleDistributionLabel.size() + 1);
    m_ParticleDistributionLabel.insert(sample, label);
}

void SampleLabelHandler::insertParticle(const Particle* sample) {
    std::string label = "particle_" + std::to_string(m_ParticleLabel.size() + 1);
    m_ParticleLabel.insert(sample, label);
}

void SampleLabelHandler::insertParticleCoreShell(const ParticleCoreShell* sample) {
    std::string label = "particleCoreShell_" + std::to_string(m_ParticleCoreShellLabel.size() + 1);
    m_ParticleCoreShellLabel.insert(sample, label);
}

void SampleLabelHandler::insertRotation(const IRotation* sample) {
    std::string label = "rotation_" + std::to_string(m_RotationsLabel.size() + 1);
    m_RotationsLabel.insert(sample, label);
}

void SampleLabelHandler::insertRoughness(const LayerRoughness* sample) {
    if (sample->getSigma() != 0 && sample->getHurstParameter() != 0
        && sample->getLatteralCorrLength() != 0) {
        std::string label = "layerRoughness_" + std::to_string(m_LayerRoughnessLabel.size() + 1);
        m_LayerRoughnessLabel.insert(sample, label);
    }
}
