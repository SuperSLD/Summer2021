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

#include <models/filtermodel.h>
#include <models/idcontainer.h>

using namespace screens;
using namespace styles;

CatalogFragment::CatalogFragment() {
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    QVBoxLayout *mainVLayout = new QVBoxLayout;

    // заголовок экрана
    ToolbarWidget *toolbar = new ToolbarWidget("Справочник", true, "filter");
    connect(toolbar, &ToolbarWidget::onBackPressed, this, &CatalogFragment::onBack);
    connect(toolbar, &ToolbarWidget::onButtinPressed, this, &CatalogFragment::onOpenFilter);
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

void CatalogFragment::bindData(BaseModel* model) {
    FilterModel *filterModel = dynamic_cast<FilterModel*>(model);
    this->markers = filterModel->markers;

    clearList(itemsContainer);
    if (filterModel->markers.size() > 0) {
        QHBoxLayout *cardsContainer = new QHBoxLayout();
        cardsContainer->setContentsMargins(6,6,6,6);
        cardsContainer->setAlignment(Qt::AlignLeft);
        itemsContainer->addLayout(cardsContainer);

        for (int i = 0; i < markers.size(); i++) {
            cardsContainer->addWidget(createFilterCard(markers[i]));
        }

        for (int key = 0; key <= factory->getMaxKey(); key++) {
            BaseSort *sort = factory->create(key);
            if (sort->containMarker(this->markers)) {
                SortItemWidget *sortWidget = new SortItemWidget(sort);
                connect(sortWidget, &SortItemWidget::selectSort, this, &CatalogFragment::onSelectSort);
                itemsContainer->addWidget(sortWidget);
            }
        }
    } else {
        for (int key = 0; key <= factory->getMaxKey(); key++) {
            SortItemWidget *sortWidget = new SortItemWidget(factory->create(key));
            connect(sortWidget, &SortItemWidget::selectSort, this, &CatalogFragment::onSelectSort);
            itemsContainer->addWidget(sortWidget);
        }
    }
}

void CatalogFragment::onBack() {
    emit back();
}

void CatalogFragment::onOpenFilter() {
    emit navigateWhithData(FILTER_TAG, new FilterModel(this->markers));
}

void CatalogFragment::onSelectSort(int key) {
    emit navigateWhithData(CATALOG_DETAIL_TAG, new IdContainer(key));
}

QLabel* CatalogFragment::createFilterCard(QList<QString> marker) {
    // название маркера
    QLabel *markerName = new QLabel(marker[0]);
    markerName->setStyleSheet(CARD_LABLE);

    // градиент для текста (ого он работает но почему там 0.1 хз)
    QPalette labelPal;
    QLinearGradient colorGradient = QLinearGradient(0, 0, markerName->width(), markerName->height());
    colorGradient.setSpread(QGradient::RepeatSpread);
    colorGradient.setColorAt(0, QColor("#F99272"));
    colorGradient.setColorAt(0.1, QColor("#72B8F9"));
    QBrush brush(colorGradient);
    labelPal.setBrush(QPalette::ColorRole::Text, brush);
    markerName->setForegroundRole(QPalette::Text);
    markerName->setWordWrap(true);
    markerName->setPalette(labelPal);

    return markerName;
}
