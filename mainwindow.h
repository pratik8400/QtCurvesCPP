#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAstroid_clicked();

    void on_btnCycloid_clicked();

    void on_btnHuygencycloid_clicked();

    void on_btnHypocycloid_clicked();

    void on_spinScale_valueChanged(double arg1);

    void on_intervalScale_valueChanged(double arg1);

    void on_spinStep_valueChanged(int arg1);

    void on_btnBackground_clicked();

    void on_btnLineColor_clicked();

private:
    void update_ui();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
