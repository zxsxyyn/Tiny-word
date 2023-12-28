#pragma once

#include <QGraphicsView>
#include "tileview.h"
class DesignView  : public QGraphicsView
{
	Q_OBJECT

public:
	DesignView(QWidget* parent);
	~DesignView();
	
	void SetMapsize(int row,int colum);
	void show_layout();
protected:
	void mousePressEvent(QMouseEvent* event)override;

public slots:
	void setfull();
public slots:
	void get_currentitem(QPointF start,QList<QGraphicsPixmapItem*> selectitems);
private:
	QGraphicsScene* sence;
	QList<QGraphicsPixmapItem*> currentitems;
	QPointF base;
	QVector<QGraphicsRectItem*> layout;
	bool is_fullset;
	bool block_show;
};
