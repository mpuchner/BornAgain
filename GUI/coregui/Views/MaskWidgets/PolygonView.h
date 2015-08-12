#ifndef POLYGONVIEW_H
#define POLYGONVIEW_H

#include "IView.h"

class PolygonItem;
class QPainter;
class QGraphicsSceneMouseEvent;

class PolygonView : public IView
{
Q_OBJECT

public:
    enum {Type = UserType + 3};
    enum Color {INCLUDE, EXCLUDE};

    PolygonView();
    QRectF boundingRect() const;
    int type() const {return Type;}
    void setExclude();
    void setInclude();
    ParameterizedItem *getParameterizedItem();
    void setParameterizedItem(ParameterizedItem *item);


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);

private:
    bool m_changeCornerMode;
    int m_indexOfCurrentSelectedPoint;
    bool m_mouseIsOverFirstPoint;
    ParameterizedItem *m_item;

    QRectF getFirstPoint() const;
    QPointF getLastPoint() const;
    qreal calculateRotation(QGraphicsSceneMouseEvent *event);
    bool isCornerClicked(QGraphicsSceneMouseEvent *event);
    QRectF calculateBoundingRectangle() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};
#endif
