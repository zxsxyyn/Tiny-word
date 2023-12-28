#include "tileview.h"
#include <QDebug>
#include <QMouseEvent>


TileView::TileView(QWidget* parent):QGraphicsView(parent)
{
    sence=new QGraphicsScene(this);
    this->setScene(sence);
    isMousePressed=false;
    selectionRect=new QGraphicsRectItem;
    selectionRect->setPen(QPen(Qt::blue,5, Qt::DashLine));
    selectionRect->setRect(0,0,BLOCKSIZE,BLOCKSIZE);
    selectionRect->setVisible(false);
    sence->addItem(selectionRect);
    selectionRect->setZValue(1);
}
//把素材切成块
void TileView::split_cells(QPixmap& map){
    int row=map.height()/BLOCKSIZE;
    int colum=map.width()/BLOCKSIZE;
    for(int i=0;i<colum;i++){
        for(int j=0;j<row;j++){
            QRectF rect(i*BLOCKSIZE,j*BLOCKSIZE,BLOCKSIZE,BLOCKSIZE);
            QPixmap cell=map.copy(rect.toRect());
            QGraphicsPixmapItem* cell_item=new QGraphicsPixmapItem(cell);
            cell_item->setPos(i * BLOCKSIZE, j * BLOCKSIZE);
            sence->addItem(cell_item);
        }
    }
}
//检测到鼠标点击，确定下starpos，同时将选中图元上显示框框。
void TileView::mousePressEvent(QMouseEvent* event) {
    isMousePressed = true;
    QGraphicsItem* item = sence->itemAt(mapToScene(event->pos()), transform());
    if (item && item->type() == QGraphicsPixmapItem::Type) {
        QGraphicsPixmapItem* clickedItem = qgraphicsitem_cast<QGraphicsPixmapItem*>(item);
        startPos = clickedItem->scenePos();
        //确定出框要显示的位置。
        selectionRect->setRect(startPos.x(),startPos.y(),BLOCKSIZE,BLOCKSIZE);
        selectionRect->setVisible(true);
    } else {                                              //点击到了无效区
        selectionRect->setVisible(false);
        qDebug() << "Error: No QGraphicsPixmapItem clicked.";
    }
}

//鼠标离开时，框选出从startpos开始到鼠标离开时所有的图元块
void TileView::mouseReleaseEvent(QMouseEvent *event) {
    if (isMousePressed) {
        isMousePressed = false;
        QGraphicsItem* end;
        QList<QGraphicsItem*> items = sence->items(mapToScene(event->pos()));
        for each (QGraphicsItem * item in items) {
            //忽略掉最上层的框框图元
            if (item->type() == QGraphicsPixmapItem::Type)
                end = item;
        }
        if (end) {
            QPointF currentPos = end->scenePos();
            int check_Rnum = (currentPos.x() - startPos.x()) / BLOCKSIZE;
            int check_Dnum = (currentPos.y() - startPos.y()) / BLOCKSIZE;
            selectionRect->setRect(startPos.x(),startPos.y(),(1 + check_Rnum) * BLOCKSIZE, (1 + check_Dnum) * BLOCKSIZE);
            QRectF rect = selectionRect->rect();
            QList<QGraphicsItem*> checks = sence->items(rect);
            QList<QGraphicsPixmapItem*> pixmaps;
            for each(QGraphicsItem * item in checks) {
                if (item->type() == QGraphicsPixmapItem::Type) {
                    QGraphicsPixmapItem* pixmapItem = qgraphicsitem_cast<QGraphicsPixmapItem*>(item);
                    if (pixmapItem)
                        pixmaps.append(pixmapItem);
                }
            }
            //将当前选中的所有图元，包括起始地点打包发送给DesignView窗口以便在Design窗口中进行绘制。
            emit send(startPos,pixmaps);
        }  
    }
}

