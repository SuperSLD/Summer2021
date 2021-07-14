#include "sortitemwidget.h"

#include <qboxlayout.h>

#include <QPushButton>
#include <qlabel.h>
#include <stylecontainer.h>
using namespace styles;


SortItemWidget::SortItemWidget(BaseSort *sort, QString buttonText) {
    this->model = sort;

    QVBoxLayout *mainLayout = new QVBoxLayout;

    // заголовок
    QLabel *title = new QLabel(sort->getTitle());
    title->setStyleSheet(TITLE_LABLE);
    title->setContentsMargins(16, 16, 16, 12);
    title->setMaximumWidth(874 - 16 - 16);
    title->setWordWrap(true);
    mainLayout->addWidget(title);

    // короткое описание
    QLabel *shortDesk = new QLabel(sort->getShortDescription());
    shortDesk->setStyleSheet(HINT_LABLE);
    shortDesk->setContentsMargins(16, 0, 16, 8);
    shortDesk->setMaximumWidth(874 - 16 - 16);
    shortDesk->setWordWrap(true);
    mainLayout->addWidget(shortDesk);

    // надписи на карточках
    QLabel *stepExpression = new QLabel(sort->getStepString());
    QLabel *stepValue = new QLabel(sort->getStepValue());
    QHBoxLayout *cardsContainer = new QHBoxLayout();
    stepExpression->setStyleSheet(CARD_BLUE_LABLE);
    stepValue->setStyleSheet(CARD_RED_LABLE);
    cardsContainer->setContentsMargins(16,0,16,8);
    cardsContainer->addWidget(stepExpression);
    cardsContainer->addWidget(stepValue);
    cardsContainer->setAlignment(Qt::AlignLeft);
    mainLayout->addLayout(cardsContainer);

    // кнопка для выбора
    QHBoxLayout *buttonContainer = new QHBoxLayout();
    QPushButton *selectButton = new QPushButton(buttonText);
    selectButton->setStyleSheet(BUTTON_SOLID);
    selectButton->setMinimumWidth(169);
    connect(selectButton, &QPushButton::clicked, this, &SortItemWidget::onButtonClicl);
    buttonContainer->setAlignment(Qt::AlignRight);
    buttonContainer->addWidget(selectButton);
    mainLayout->addLayout(buttonContainer);

    this->setLayout(mainLayout);
    this->setObjectName("sort_item");
    this->setMinimumHeight(mainLayout->geometry().height());
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    this->setStyleSheet(SORT_ITEM_WIDGET);
}

void SortItemWidget::onButtonClicl() {
    emit selectSort(model->getFactoryKey());
}
