#include "catalogfragment.h"

#include <QLabel>

#include <stylecontainer.h>
#include <implfragmentfactory.h>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>
#include <QSettings>
#include <QSvgWidget>
#include <QVBoxLayout>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QJsonArray>
#include <QScrollArea>
#include <QScrollBar>
#include <QNetworkReply>
#include <QColor>

#include <ui/widgets/sortitemwidget.h>
#include <ui/widgets/swgbutton.h>
#include <ui/widgets/toolbarwidget.h>

#include <models/idcontainer.h>

using namespace screens;
using namespace styles;

CatalogFragment::CatalogFragment() {
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    QVBoxLayout *mainVLayout = new QVBoxLayout;

    // заголовок экрана
    ToolbarWidget *toolbar = new ToolbarWidget("Справочник", true);
    connect(toolbar, &ToolbarWidget::onBackPressed, this, &CatalogFragment::onBack);
    mainVLayout->addWidget(toolbar);

    // зона прокрутки
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setMinimumWidth(874);
    scrollArea->setMaximumWidth(874);
    scrollArea->setFrameShape(QFrame::NoFrame);
    QWidget *scrolContainer = new QWidget;
    scrolContainer->setObjectName("container");
    scrollArea->setStyleSheet(SCROL_BAR);
    QHBoxLayout *deskContainer = new QHBoxLayout;
    itemsContainer = new QVBoxLayout;
    itemsContainer->setAlignment(Qt::AlignTop);
    deskContainer->addLayout(itemsContainer);
    itemsContainer->setContentsMargins(0,0,0,0);
    scrolContainer->setLayout(deskContainer);
    scrollArea->setWidget(scrolContainer);
    scrollArea->setWidgetResizable(true);
    scrollArea->horizontalScrollBar()->setEnabled(false);
    scrollArea->verticalScrollBar()->hide();
    mainVLayout->addWidget(scrollArea);
    mainVLayout->setAlignment(Qt::AlignTop);
    mainHLayout->addLayout(mainVLayout);
    mainHLayout->setAlignment(Qt::AlignHCenter);

    // создаем сортировки через цикл по ключам и кидаем в список
    factory = new SortFactory();
    for (int key = 0; key <= factory->getMaxKey(); key++) {
        SortItemWidget *sortWidget = new SortItemWidget(factory->create(key));
        connect(sortWidget, &SortItemWidget::selectSort, this, &CatalogFragment::onSelectSort);
        itemsContainer->addWidget(sortWidget);
    }

    this->setLayout(mainHLayout);
    this->setObjectName("fragment");
}

CatalogFragment::~CatalogFragment() {
    delete factory;
    delete itemsContainer;
}

void CatalogFragment::onBack() {
    emit back();
}

void CatalogFragment::onSelectSort(int key) {
    emit navigateWhithData(CATALOG_DETAIL_TAG, new IdContainer(key));
}
