// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/ba3d/model/camera.h
//! @brief     Defines Camera class
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BA3D_CAMERA_H
#define BA3D_CAMERA_H

#include "../def.h"
#include <QColor>
#include <QMatrix4x4>
#include <QQuaternion>

namespace RealSpace {

class Canvas;
class Program;

class Camera : public QObject {
    Q_OBJECT
    friend class Canvas;
    friend class Program;
public:
    Camera();

    struct Position {

        Position();
        Position(const Vector3D& eye, const Vector3D& ctr, const Vector3D& up,
                 const QQuaternion& = QQuaternion());

        Vector3D eye, ctr, up;
        QQuaternion rot;

        Position interpolateTo(const Position&, float) const;
    };

    void lookAt(const Position&);

    const Position& getPos() const { return pos; }

    void set();

signals:
    void updated(Camera const&);

private:
    void setAspectRatio(float);

    // additional transformation
    void turnBy(QQuaternion const&);
    void zoomBy(float);
    void endTransform(bool keep);

    // camera setup
    Position pos;
    float zoom;
    float vertAngle, nearPlane, farPlane;

    // light
    Vector3D lightPos, lightPosRotated;

    // transformation
    QQuaternion addRot;        // rotation, additional rotation
    QMatrix4x4  matModel, matProj;
};

}  // namespace RealSpace
#endif  // BA3D_CAMERA_H
