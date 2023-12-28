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
    connect(ui->actionopen, &QAction::triggered, this, &MainWindow::loadimage);  //绑定菜单栏的文件open和图片加载
    connect(ui->full, &QAction::triggered, this->design, &DesignView::setfull);  //绑定工具填充选项
    connect(ui->block_view, &QPushButton::clicked, this->design, &DesignView::show_layout);  //辅助窗口的显示
    connect(select, &TileView::send, design, &DesignView::get_currentitem);                 //当前选中图元在素材窗口和设计窗口之间的传递
}
void MainWindow::loadimage()
{
    // 槽函数的实现：加载图片
    filename = QFileDialog::getOpenFileName(this, "select", "D:\\RPG make\\Graphics", "Images (*.png *.jpg)");
    QPixmap map(filename);
    select->split_cells(map);
    select->show();
}
MainWindow::~MainWindow()
{
    delete ui;
}

