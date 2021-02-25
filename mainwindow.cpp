#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->spinScale->setValue(this->ui->renderArea->scale());
    this->ui->intervalScale->setValue(this->ui->renderArea->interval());
    this->ui->spinStep->setValue(this->ui->renderArea->stepCount());


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_ui(){
    this->ui->spinScale->setValue(this->ui->renderArea->scale());
    this->ui->intervalScale->setValue(this->ui->renderArea->interval());
    this->ui->spinStep->setValue(this->ui->renderArea->stepCount());

}

void MainWindow::on_btnAstroid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Astroid);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnCycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    this->ui->renderArea->repaint();
    update_ui();


}

void MainWindow::on_btnHuygencycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Huygenscycloid);
    this->ui->renderArea->repaint();
    update_ui();

}

void MainWindow::on_btnHypocycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Hypocycloid);
    this->ui->renderArea->setBackgroundColor(Qt::yellow);
    this->ui->renderArea->repaint();
    update_ui();

}

void MainWindow::on_spinScale_valueChanged(double scale)
{
 this->ui->renderArea->setScale(scale);
}

void MainWindow::on_intervalScale_valueChanged(double interval)
{
 this->ui->renderArea->setInteval(interval);
}

void MainWindow::on_spinStep_valueChanged(int count)
{
 this->ui->renderArea->setStepCount(count);
}
