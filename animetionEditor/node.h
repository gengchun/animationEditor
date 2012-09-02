#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <list>


class Edge;
class GraphWidget;
QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE



// TODO description
// x and y are stored in base class
class Node : public QGraphicsItem{
public:
    Node(GraphWidget *graphWidget);
    ~Node();

    void addEdge(Edge *edge);
    void removeEdge(Edge *edge);
    std::list<Edge *> edges() const;

    enum { Type = UserType + 1 };
    int type() const { return Type; }

    bool advance(); //TODO mb remove

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    
private:
    static const double ellipseSide = 15;
    QPointF newPos;
    GraphWidget *graph;
    std::list<Edge *> edgeList;
};

#endif