#include "filterfragment.h"

#include <ui/widgets/toolbarwidget.h>

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

#include <sort/sortfactory.h>

using namespace screens;
using namespace styles;
FilterFragment::FilterFragment() {
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    QVBoxLayout *mainVLayout = new QVBoxLayout;

    // заголовок экрана
    ToolbarWidget *toolbar = new ToolbarWidget("Фильтр для поиска", true);
    connect(toolbar, &ToolbarWidget::onBackPressed, this, &FilterFragment::onBack);
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

    // короткое описание
    QLabel *shortDesk = new QLabel("Выберите набор фильтров для того, чтобы облегчить поиск нужной вас сортировки. Укажите необходимые маркеры и нажмите кнопку “Готово”.");
    shortDesk->setStyleSheet(HINT_LABLE);
    shortDesk->setContentsMargins(0, 0, 0, 8);
    shortDesk->setMaximumWidth(874);
    shortDesk->setWordWrap(true);
    itemsContainer->addWidget(shortDesk);

    // элементы фильтра
    BaseSort *sort = new BaseSort;
    QList<QList<QString>> markers = sort->getAllMarkers();
    for (int i = 0; i < markers.size(); i++) {
        FilterItemWidget *filterItem = new FilterItemWidget(markers[i]);
        this->list.append(filterItem);
        itemsContainer->addWidget(filterItem);
    }

    // кнопка в конце
    QHBoxLayout *buttonContainer = new QHBoxLayout();
    // готово
    QPushButton *selectButton = new QPushButton("Готово");
    selectButton->setStyleSheet(BUTTON_SOLID);
    selectButton->setMinimumWidth(169);
    connect(selectButton, &QPushButton::clicked, this, &FilterFragment::onFinish);
    // отчистить
    QPushButton *clearButton = new QPushButton("Отчистить фильтр");
    clearButton->setStyleSheet(BUTTON_EMPTY);
    clearButton->setMinimumWidth(169);
    connect(clearButton, &QPushButton::clicked, this, &FilterFragment::clearFilter);
    buttonContainer->setAlignment(Qt::AlignLeft);
    buttonContainer->addWidget(selectButton);
    buttonContainer->addWidget(clearButton);
    itemsContainer->addLayout(buttonContainer);

    this->setLayout(mainHLayout);
    this->setObjectName("fragment");
}

FilterFragment::~FilterFragment() {

}

void FilterFragment::bindData(BaseModel *model) {
    FilterModel *filterModel = dynamic_cast<FilterModel*>(model);
    for (int i = 0; i < filterModel->markers.size(); i++) {
        for (int j = 0; j < list.size(); j++) {
            if (filterModel->markers[i][0] == list[j]->getMarker()[0]) {
                list[j]->setSelected(true);
            }
        }
    }
}

void FilterFragment::onBack() {
    emit back();
}

void FilterFragment::onFinish() {
    QList<QList<QString>> selectedMarkers;
    for (int i = 0; i < list.size(); i++) {
        if (list[i]->isSelected()) {
            selectedMarkers.append(list[i]->getMarker());
        }
    }
    emit backWhithData(new FilterModel(selectedMarkers));
}

void FilterFragment::clearFilter() {
    QList<QList<QString>> emptyFilter;
    emit backWhithData(new FilterModel(emptyFilter));
}
