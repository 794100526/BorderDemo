#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //关闭QT边框
    setWindowFlag(Qt::FramelessWindowHint);
    setMouseTracking(true);
    //创建边框类容器
    myBorderContainer = new MyBorderContainer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
