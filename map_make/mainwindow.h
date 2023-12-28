#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QString>
#include <QMainWindow>
#include "tileview.h"
#include "DesignView.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void loadimage();

private:
    Ui::MainWindow *ui;
    TileView* select;
    DesignView* design;
    QString filename;
};
#endif // MAINWINDOW_H
