#ifndef TILEVIEW_H
#define TILEVIEW_H
#define BLOCKSIZE 32

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
//#include <QMouseEvent>


class TileView : public QGraphicsView
{
    Q_OBJECT
public:    
    TileView(QWidget* parent = nullptr);
    void split_cells(QPixmap&);
signals:
    void send(QPointF start,QList<QGraphicsPixmapItem*> items);
protected:
    void mousePressEvent(QMouseEvent* event)override;
    void mouseReleaseEvent(QMouseEvent *event) override;
   
private:
    QGraphicsRectItem* selectionRect;
    QGraphicsScene* sence;
    bool isMousePressed;
    QPointF startPos;
    QGraphicsPixmapItem* CURRENT_ITEM;
};

#endif // TILEVIEW_H
