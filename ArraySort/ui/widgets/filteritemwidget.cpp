#include "filteritemwidget.h"

#include <QPushButton>
#include <qboxlayout.h>
#include <qlabel.h>
#include <stylecontainer.h>
using namespace styles;


FilterItemWidget::FilterItemWidget(QList<QString> marker) {
    this->marker = marker;
    QHBoxLayout *mainLayout = new QHBoxLayout;

    // название маркера
    QLabel *markerName = new QLabel(marker[0]);
    QHBoxLayout *cardsContainer = new QHBoxLayout();
    markerName->setStyleSheet(CARD_LABLE);
    cardsContainer->setContentsMargins(6,6,6,6);
    cardsContainer->addWidget(markerName);
    cardsContainer->setAlignment(Qt::AlignLeft);
    mainLayout->addLayout(cardsContainer);

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

    // кнопка в конце
    QHBoxLayout *buttonContainer = new QHBoxLayout();
    selectButton = new QPushButton("Выбрвть");
    selectButton->setStyleSheet(BUTTON_SOLID);
    selectButton->setMinimumWidth(169);
    connect(selectButton, &QPushButton::clicked, this, &FilterItemWidget::changeState);
    buttonContainer->setAlignment(Qt::AlignRight);
    buttonContainer->addWidget(selectButton);
    mainLayout->addLayout(buttonContainer);

    // просто инициализация виджета
    this->setLayout(mainLayout);
    this->setObjectName("sort_item");
    this->setMinimumHeight(mainLayout->geometry().height());
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    this->setStyleSheet(SORT_ITEM_WIDGET);
}

void FilterItemWidget::changeState() {
    selected = not selected;
    drawState();
}

void FilterItemWidget::drawState() {
    if (!selected) {
        selectButton->setText("Выбрвть");
        selectButton->setStyleSheet(BUTTON_SOLID);
    } else {
        selectButton->setText("Отменить");
        selectButton->setStyleSheet(BUTTON_EMPTY);
    }
}

bool FilterItemWidget::isSelected() {
    return this->selected;
}

QList<QString> FilterItemWidget::getMarker() {
    return this->marker;
}

void FilterItemWidget::setSelected(bool selected) {
    this->selected = selected;
    drawState();
}
