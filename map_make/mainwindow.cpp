#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(100,100,1500,900);
    select=new TileView(this);
    design = new DesignView(this);
    select->setGeometry(0,50,256,800);
    design->SetMapsize(21,32);
    design->show();
    connect(ui->actionopen, &QAction::triggered, this, &MainWindow::loadimage);  //�󶨲˵������ļ�open��ͼƬ����
    connect(ui->full, &QAction::triggered, this->design, &DesignView::setfull);  //�󶨹������ѡ��
    connect(ui->block_view, &QPushButton::clicked, this->design, &DesignView::show_layout);  //�������ڵ���ʾ
    connect(select, &TileView::send, design, &DesignView::get_currentitem);                 //��ǰѡ��ͼԪ���زĴ��ں���ƴ���֮��Ĵ���
}
void MainWindow::loadimage()
{
    // �ۺ�����ʵ�֣�����ͼƬ
    filename = QFileDialog::getOpenFileName(this, "select", "D:\\RPG make\\Graphics", "Images (*.png *.jpg)");
    QPixmap map(filename);
    select->split_cells(map);
    select->show();
}
MainWindow::~MainWindow()
{
    delete ui;
}

