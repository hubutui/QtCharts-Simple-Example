#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionDraw_triggered()
{
    // 用于绘制 spline chart 的数据
    QSplineSeries *sp = new QSplineSeries();

    // 添加数据到 sp 中，这里取 y = sin(x), -pi < x < pi
    for (double x = -M_PI; x < M_PI; x += 0.01) {
        sp->append(x, sin(x));
    }

    // 用于绘制 line chart 的数据
    QLineSeries *line = new QLineSeries();
    // 添加数据 line 中，这里取 y = x^2 - 1, -3 < x < 3
    // 这里取步长为 0.5，这样可以方便看出来 line chart 和 spline chart 的区别
    for(double x = -3; x < 3; x += 0.5)
    {
        line->append(x, x*x - 1);
    }

    // 设置名称，会在图例中显示
    sp->setName(tr("y = sin(x)"));
    line->setName(tr("y = x^2 - 1"));
    // 使用 openGL 渲染，可以提速，但是对于这个简单的例子是没有什么区别的
    sp->setUseOpenGL(true);

    // QChart 类用于管理图表中各种元素，包括坐标点，风格，坐标轴和图例等，这个用于笛卡尔坐标
    // 另外有 QPolarChart 用于极坐标
    QChart *chart = new QChart();

    // 将 series 添加到图表中，可以添加多个
    chart->addSeries(sp);
    chart->addSeries(line);

    // 绘制默认的坐标轴
    chart->createDefaultAxes();

    // 设置图表的标题
    chart->setTitle(tr("简单的 Qt Charts 例子"));

    // 设置 x 轴的范围
    chart->axisX()->setRange(-4, 4);
    // 设置 y 轴的范围
    chart->axisY()->setRange(-1.2, 1.2);

    // 设置图表的主题，取值为枚举 QChart::ChartTheme
    chart->setTheme(QChart::ChartThemeBlueIcy);

    // 设置动画效果，取值为枚举 QChart::AnimationOption
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->legend()->setAlignment(Qt::AlignBottom);
    //chart->legend()->setVisible(true);

    // QChartView 是一个独立的 Qt widget，用来显示 QChart 的．
    // 这里 chartView 是界面里的一个 widget，它是从 Qt Widget 提升为 QChartView 得到的
    // Qt Creator 并没有单独的一个 widget 叫做 QChartView
    // **关键** 这里要用 setChart 方法将 chart 作为显示的图表
    // 这一句是将界面中的 QChartView 跟 QChart 联系起来的关键
    ui->chartView->setChart(chart);

    // 打开抗锯齿，提升显示效果
    ui->chartView->setRenderHint(QPainter::Antialiasing);
}
