// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/ba3d/model/program.cpp
//! @brief     Implements Program class
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "program.h"
#include "camera.h"
#include <QMatrix4x4>

// The macro call has to be in the global namespace
inline void InitShaderResources() {
    Q_INIT_RESOURCE(shaders);
}

namespace RealSpace {

Program::Program()
{
    // make sure our resource file gets initialized
    InitShaderResources();

    needsInit();
}

void Program::needsInit() {
    doInit = true;
}

void Program::init() {
    if (!doInit)
        return;
    doInit = false;

    auto shader_found = addShaderFromSourceFile(QOpenGLShader::Vertex,
                                                ":/shaders/vertex_shader.vert");
    if (!shader_found)
        throw std::runtime_error("Vertex shader not loaded");
#ifdef Q_OS_OSX
    shader_found = addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragment_shader_OSX.frag");
#else
    shader_found = addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragment_shader.frag");
#endif
    if (!shader_found)
        throw std::runtime_error("Fragment shader not loaded");

    bindAttributeLocation("vertex", 0);
    bindAttributeLocation("normal", 1);

    link();

    bind();
    locMatProj   = uniformLocation("matProj");
    locMatModel  = uniformLocation("matModel");
    locMatObject = uniformLocation("matObject");
    locLightPos  = uniformLocation("lightPos");
    locColor     = uniformLocation("color");
    release();
}

void Program::set(Camera const& camera) {
    setUniformValue(locMatProj,  camera.matProj);
    setUniformValue(locMatModel, camera.matModel);
    setUniformValue(locLightPos, camera.lightPosRotated);
}

void Program::set(QColor const&color) {
    setUniformValue(locColor, color);
}

void Program::set(QMatrix4x4 const& mat) {
    setUniformValue(locMatObject, mat);
}

}  // namespace RealSpace
