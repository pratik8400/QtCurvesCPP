#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_btnAstroid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Astroid);
    this->ui->renderArea->repaint();
}

void MainWindow::on_btnCycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    this->ui->renderArea->repaint();

}

void MainWindow::on_btnHuygencycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Huygenscycloid);
    this->ui->renderArea->repaint();


}

void MainWindow::on_btnHypocycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Hypocycloid);
    this->ui->renderArea->setBackgroundColor(Qt::yellow);
    this->ui->renderArea->repaint();


}
