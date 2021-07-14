#include "selectsecondfragment.h"

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

SelectSecondFragment::SelectSecondFragment() {
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    QVBoxLayout *mainVLayout = new QVBoxLayout;

    // заголовок экрана
    ToolbarWidget *toolbar = new ToolbarWidget("Вторая сортировка", true);
    connect(toolbar, &ToolbarWidget::onBackPressed, this, &SelectSecondFragment::onBack);
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
        SortItemWidget *sortWidget = new SortItemWidget(factory->create(key), "Сравнить");
        connect(sortWidget, &SortItemWidget::selectSort, this, &SelectSecondFragment::onSelectSort);
        itemsContainer->addWidget(sortWidget);
    }

    this->setLayout(mainHLayout);
    this->setObjectName("fragment");
}

SelectSecondFragment::~SelectSecondFragment() {
    delete factory;
    delete itemsContainer;
}

void SelectSecondFragment::bindData(BaseModel *model) {
    this->firstSelection = dynamic_cast<ComparisonModel*>(model);
}

void SelectSecondFragment::onBack() {
    emit back();
}

void SelectSecondFragment::onSelectSort(int key) {
    if (this->firstSelection->firstId >= 0) {
        this->firstSelection->secondId = key;
        emit replaceWhithData(VS_DETAIL_TAG, this->firstSelection);
    }
}
