#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include <common/navigator.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    SlidingStackedWidget *container;
    Navigator *navigator;
    BaseFragmentFactory *factory;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
