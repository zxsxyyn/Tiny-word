#include "DesignView.h"
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include <QDebug>
DesignView::DesignView(QWidget *parent)
	: QGraphicsView(parent)
{
	is_fullset = false;
	block_show = false;
	sence = new QGraphicsScene(this);
	this->setScene(sence);
}

DesignView::~DesignView()
{

}
//�趨������С
void DesignView::SetMapsize (int row, int colum)
{
	sence->setSceneRect(0, 0, colum * BLOCKSIZE, row * BLOCKSIZE);
	this->setSceneRect(sence->sceneRect());
	this->setGeometry(300, 50, colum * BLOCKSIZE, row * BLOCKSIZE);
	for (int i = 0; i < colum; i++) {
		for (int j = 0; j < row; j++) {
			QGraphicsRectItem* block = new QGraphicsRectItem;
			block->setPen(QPen(Qt::green, 2, Qt::SolidLine));
			block->setRect(i * BLOCKSIZE, j * BLOCKSIZE, BLOCKSIZE, BLOCKSIZE);
			sence->addItem(block);
		}
	}
}
//��ʾ��������
void DesignView::show_layout()
{
	block_show = !block_show;
	if (block_show) {
		for each (QGraphicsItem* item in sence->items())
		{
			item->setVisible(true);
		}
	}
	else {
		for each (QGraphicsItem * item in sence->items())
		{
			item->setVisible(false);
		}
	}
}

//�����λ�û���ͼԪ��
void DesignView::mousePressEvent(QMouseEvent* event)
{
	QPointF point = mapToScene(event->pos());
	int x=(point.x() / BLOCKSIZE);
	int y(point.y() / BLOCKSIZE);
	if (!currentitems.isEmpty()) {
		for each (QGraphicsPixmapItem* item in currentitems) {
			QPixmap* copy = new QPixmap(item->pixmap());
			QGraphicsPixmapItem* clickd_item = new QGraphicsPixmapItem(*copy);
			int relative_x = item->pos().x() - base.x();
			int relative_y= item->pos().y() - base.y();
			clickd_item->setPos(x * BLOCKSIZE+ relative_x, y * BLOCKSIZE+ relative_y);
			clickd_item->setVisible(true);
			sence->addItem(clickd_item);
		}
	}
	else {
		qDebug() << "null" << endl;
	}
}
//�ۺ������յ�ǰѡ����ͼԪ�б�
void DesignView::get_currentitem(QPointF start, QList<QGraphicsPixmapItem*> selectitems)
{
	base = start;
	currentitems = selectitems;
}

//�趨���
void DesignView::setfull()
{
	is_fullset = !is_fullset;
	if (is_fullset) {
		qDebug() << "Yes " ;
	}
	else {
		qDebug() << "no " ;
	}
}
