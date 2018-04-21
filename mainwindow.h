#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// 包含 QtCharts，ui 文件是不能直接编辑的，ui 文件生成的代码会用到 QtCharts
// 而 mainwindow 对应的 ui 文件生成的代码会包含头文件 mainwindow.h
// 因此可以将 QtCharts 的头文件包含写在这里
#include <QtCharts>
// 下面两句是等价的
// using namespace QtCharts
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionDraw_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
