# QtCharts-Simple-Example
这个 repo 给出简单但是也相对比较完整的使用 Qt Charts 绘制正弦曲线和折线图的例子．
代码都加入了相对详细的注释，直接阅读代码是可以迅速了解 Qt Charts 的使用方法的．

## 总体把握
[Qt Charts](http://doc.qt.io/qt-5/qtcharts-index.html) 是 Qt 的一个绘图组件，它使用的是 [Graphics View Framework](http://doc.qt.io/qt-5/graphicsview.html).
它的组件可以作为 [QWidget](http://doc.qt.io/qt-5/qwidget.html)、[QGraphicsWidget](http://doc.qt.io/qt-5/graphicsview.html#qgraphicswidget) 对象或者
QML 类型来使用．这里 repo 中的例子将 Qt Charts 组件作为 QWidget 来使用．

我们需要了解 Qt Charts 模块中的几个重要的类，以便从全局上来把握如何使用 Qt Charts:
* [QChartView](http://doc.qt.io/qt-5/qchartview.html) 是一个独立的 widget，用于界面显示，继承自 [QGraphicsView](http://doc.qt.io/qt-5/qgraphicsview.html).
其中的 `setChart` 方法可以在 QChartView 中添加一个 QChart.
* [QChart](http://doc.qt.io/qt-5/qchart.html) 提供颜色风格、动画效果风格、坐标轴控制、图例等图表中各元素表示，继承自 [QGraphicsWidget](http://doc.qt.io/qt-5/qgraphicswidget.html)．
* [QPolarChart](http://doc.qt.io/qt-5/qpolarchart.html) 与上面的 QChart 类似，只是它的坐标系是极坐标系的．
* [QAbstractSeries](http://doc.qt.io/qt-5/qabstractseries.html) 作为一系列图形类型的父类，包括 [QAbstractBarSeries](http://doc.qt.io/qt-5/qabstractbarseries.html) - 柱状图, [QAreaSeries](http://doc.qt.io/qt-5/qareaseries.html) - 面积图, [QBoxPlotSeries](http://doc.qt.io/qt-5/qboxplotseries.html) - 箱线图, [QCandlestickSeries](http://doc.qt.io/qt-5/qcandlestickseries.html) - K 线图, [QPieSeries](http://doc.qt.io/qt-5/qpieseries.html) - 饼图和 [QXYSeries](http://doc.qt.io/qt-5/qxyseries.html) - 散点图、折线图和曲线图的基类，均提供了append等函数用于添加每一项数据．QXYSeries 还会派生处子类 [QLineSeries](http://doc.qt.io/qt-5/qlineseries.html) 和 [QScatterSeries](http://doc.qt.io/qt-5/qscatterseries.html) 等．一般是根据需要使用对应的派生子类，而不是直接使用基类．
* [QAbstractAxis](http://doc.qt.io/qt-5/qabstractaxis.html) 是坐标轴的基类，派生出子类 [QBarCategoryAxis](http://doc.qt.io/qt-5/qbarcategoryaxis.html), [QDateTimeAxis](http://doc.qt.io/qt-5/qdatetimeaxis.html), [QLogValueAxis](http://doc.qt.io/qt-5/qlogvalueaxis.html) 以及 [QValueAxis](http://doc.qt.io/qt-5/qvalueaxis.html) 等不同的子类，用于不同的坐标轴．常用的 x, y 轴用 QValueAxis 类即可．
* [QLegend](http://doc.qt.io/qt-5/qlegend.html) 显然就是用于图例的类
* [QLegendMarker](http://doc.qt.io/qt-5/qlegendmarker.html) 为图例标记 ，QLegend 提供的是图例框，里面的每一项应该用 QLegendMarker．

Qt 的文档相对来说是写得比较优秀的，用户可以很容易地根据自己的需要去了解不同的类的使用方法．

## Step by Step
你当然可以直接 `git clone https://github.com/hubutui/QtCharts-Simple-Example.git`，然后用 Qt Creator 打开项目中的工程文件，然后编译运行．但是这样子会漏掉一些重要的信息，个人建议是自己新建一个项目来做．

1. 打开 Qt Creator 新建一个 Qt Widgets Application 项目
2. 创建好项目之后，打开界面文件，即 `.ui` 文件，添加一个 Widget 到界面上来．
3. 在添加好的 Widget 上点击右键->Promote to..., Promoted class name 写上 `QChartView`，Header file 写上 `QChartView` 或者 `QtCharts/QChartView`，这取决于你的系统是如何安装 Qt Charts 模块以及编译器如何查找头文件．
4. 这个 repo 在界面上添加的 QChartView 的对象名为 `chartView`，如果你也使用这个名字，其他部分的代码应该就可以照抄了．
5. 使用 Qt Charts 模块需要包含对应的头文件．显然 ui 文件会用到 Qt Charts，但是我们无法直接编辑 ui 文件，但是它生成的源码会自动包含它自己的头文件．因此我们只需将头文件包含语句写到 ui 文件对应的头文件即可．在这个 repo 中就是 `mainwindow.h` 文件，详细信息请看代码．

特别提示：与网上常见的例子中直接在构造函数中写代码绘制图表不同，这个 repo 是在主程序窗口上加了个菜单，然后在菜单的槽函数里绘制的，这一点应该也很容易从代码中看出来．

我想我已经说的够多的了，更多的信息就请直接看代码吧．

# 额外的收获
去年在看 [Graphics View Framework](http://doc.qt.io/qt-5/graphicsview.html) 中各个类的关系的时候总是没弄明白，反而这次从 Qt Charts 的继承关系中更加容易理解了．

# 打赏
如果您觉的本文很有帮助，不妨给 [eGuideDog Linux](http://www.eguidedog.net/cn/support-us-cn.php) 项目打赏支持．感谢您的支持．
