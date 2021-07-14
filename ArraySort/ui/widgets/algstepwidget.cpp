#include "algstepwidget.h"

#include <qboxlayout.h>
#include <QPushButton>
#include <qlabel.h>
#include <stylecontainer.h>
using namespace styles;

AlgStepWidget::AlgStepWidget(int position, QString text) {
    QVBoxLayout *mainLayout = new QVBoxLayout;


    // надписи на карточках
    QLabel *stepNumber = new QLabel(QString::number(position));
    QLabel *stepText = new QLabel(text);
    QHBoxLayout *cardsContainer = new QHBoxLayout();
    stepNumber->setStyleSheet(CARD_BLUE_LABLE);
    stepText->setStyleSheet(HINT_LABLE);
    cardsContainer->setContentsMargins(16,16,16,16);
    cardsContainer->addWidget(stepNumber);
    cardsContainer->addWidget(stepText);
    stepText->setWordWrap(true);
    stepText->setContentsMargins(0, 8, 0, 0);
    stepText->setMinimumWidth(750);
    stepText->setMaximumWidth(750);
    cardsContainer->setAlignment(stepNumber, Qt::AlignTop);
    cardsContainer->setAlignment(stepText, Qt::AlignTop);
    cardsContainer->setAlignment(Qt::AlignLeft);
    mainLayout->addLayout(cardsContainer);

    this->setLayout(mainLayout);
    this->setObjectName("sort_item");
    this->setMinimumHeight(mainLayout->geometry().height());
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    this->setStyleSheet(SORT_ITEM_WIDGET);
}
