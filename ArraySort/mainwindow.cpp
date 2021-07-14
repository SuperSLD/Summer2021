#include "mainwindow.h"

#include <QDesktopWidget>
#include <implfragmentfactory.h>

#include <ui/widgets/slidingstackedwidget.h>
#include <stylecontainer.h>
using namespace styles;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    try {
        qDebug("create main window");
        container = new SlidingStackedWidget(this);
        container->setObjectName("ui");

        this->factory = new ImplFragmentFactory;
        this->navigator = new Navigator(
                    this->container,
                    this->factory
        );

        QString mainStyle = "QWidget#window {"
                            "background-color:"+COLOR_WINDOW_BACKGROUND+";"
                            "}";
        container->setStyleSheet(mainStyle);
        container->setObjectName("window");

        this->setWindowTitle("Справочник сортировок");
        this->setWindowIcon(QIcon(":/resc/resc/planet.svg"));
        this->resize(QDesktopWidget().availableGeometry(this).size() * 0.7);
        this->setCentralWidget(container);
    } catch (std::exception& e) {
        qDebug("%s", e.what());
    }
}

MainWindow::~MainWindow() {
    delete container;
    delete navigator;
    delete factory;
}

