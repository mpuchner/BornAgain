#include "DistributionEditor.h"

#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

class GraphicsProxyWidget : public QGraphicsProxyWidget
{
public:
    //! Type of this item
    enum { Type = UserType + 4 };

    //! returns the type of this item
    //! @return number of type
    int type() const
    {
        return Type;
    }

protected:
    //! manages mouse press events
    //! @param event from scene
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    //! manages mouse move events
    //! @param event from scene
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    //! manages mouse release events
    //! @param event from scene
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif