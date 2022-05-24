#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <vector>
#include <QDebug>
using std::vector;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    vector<double> get_coe();
    vector<double> get_index();
    double get_value();
    double get_precision();
    double iter_exp(double value);
    double newton();


private slots:
    void on_pushButton_clicked();



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
