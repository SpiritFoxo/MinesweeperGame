#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "logichandler.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_easyButton_clicked()
{
    QGraphicsScene* scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    LogicHandler* lh = new LogicHandler();
    lh->BuildScene(ui->graphicsView->scene(), 9,9);

}


void MainWindow::on_mediumButton_clicked()
{
    QGraphicsScene* scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    LogicHandler* lh = new LogicHandler();
    lh->BuildScene(ui->graphicsView->scene(), 18,18);
    delete lh;
}


void MainWindow::on_hardButton_clicked()
{
    QGraphicsScene* scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    LogicHandler* lh = new LogicHandler();
    lh->BuildScene(ui->graphicsView->scene(), 36,36);
    delete lh;

}

void MainWindow::UpdateScene(QGraphicsScene *scene){
    scene->clear();
    ui->graphicsView->viewport()->update();
}

