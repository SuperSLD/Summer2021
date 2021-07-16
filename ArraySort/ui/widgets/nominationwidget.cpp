#include "nominationwidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QSvgWidget>
#include <QList>
#include <stylecontainer.h>
using namespace styles;

NominationWidget::NominationWidget(QList<QString> nomination) {

    QVBoxLayout *mainLayout = new QVBoxLayout;

    // заголовок
    QLabel *bigText = new QLabel(nomination[0]);
    QHBoxLayout *container = new QHBoxLayout;
    bigText->setContentsMargins(16, 16, 16, 16);
    bigText->setMaximumWidth(874/2 - 16*2 - 8);
    QFont font = bigText->font();
    font.setPointSize(60);
    bigText->setFont(font);
    bigText->setForegroundRole(QPalette::Text);
    container->setAlignment(Qt::AlignLeft);
    mainLayout->addLayout(container);
    container->addWidget(bigText);
    // делаем градиент
    QPalette labelPal;
    bigText->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    QLinearGradient colorGradient = QLinearGradient(0, 0, bigText->width(), bigText->height());
    colorGradient.setSpread(QGradient::RepeatSpread);
    colorGradient.setColorAt(0, QColor("#F99272"));
    colorGradient.setColorAt(0.26, QColor("#72B8F9"));
    QBrush brush(colorGradient);
    labelPal.setBrush(QPalette::ColorRole::Text, brush);
    bigText->setWordWrap(true);
    bigText->setPalette(labelPal);

    // заголовок
    QLabel *title = new QLabel(nomination[1]);
    title->setStyleSheet(TITLE_LABLE);
    title->setContentsMargins(16, 16, 16, 16);
    title->setMaximumWidth(874/2 - 16*2 - 8);
    title->setWordWrap(true);
    mainLayout->addWidget(title);

    this->setLayout(mainLayout);
    this->setObjectName("sort_item");
    this->setMinimumHeight(mainLayout->geometry().height());
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
    this->setStyleSheet(SORT_ITEM_WIDGET);
}
