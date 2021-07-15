#include "nominationwidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QSvgWidget>
#include <QList>
#include <stylecontainer.h>
using namespace styles;

NominationWidget::NominationWidget(QList<QString> nomination) {

    QVBoxLayout *mainLayout = new QVBoxLayout;

    // картинка
    QHBoxLayout *imageContainer = new QHBoxLayout;
    QSvgWidget *mainImage = new QSvgWidget(":/resc/resc/"+nomination[0]+".svg");
    mainImage->setMinimumSize(QSize(300, 70));
    mainImage->setMaximumSize(QSize(300, 70));
    mainImage->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    mainImage->setContentsMargins(16, 16, 0, 16);
    imageContainer->setAlignment(Qt::AlignLeft);
    imageContainer->addWidget(mainImage);
    mainLayout->addLayout(imageContainer);

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
