#include "swgbutton.h"
#include "toolbarwidget.h"

#include <QSvgWidget>
#include <QHBoxLayout>
#include <qlabel.h>

#include <stylecontainer.h>
using namespace styles;

ToolbarWidget::ToolbarWidget(QString title, bool showBack, QString icon) {
    QHBoxLayout *titleContainer = new QHBoxLayout;
    SwgButton *backButton = new SwgButton(":/resc/resc/arrow_back.svg", QSize(24,24));
    QLabel *titleLabel = new QLabel(title);
    titleLabel->setStyleSheet(TITLE_LABLE);
    connect(backButton, &SwgButton::clicked, this, &ToolbarWidget::onBackPressed);
    if (showBack) {
        titleContainer->addWidget(backButton);
    }
    titleContainer->addWidget(titleLabel);
    titleContainer->setContentsMargins(0,24,0,16);
    titleLabel->setContentsMargins(16,0,0,0);

    if (icon.length() > 0) {
        // кнопка справа тулбара
        QFrame *buttonContainer = new QFrame;
        QVBoxLayout *buttonLayout = new QVBoxLayout;
        SwgButton *buttonIcon = new SwgButton(":/resc/resc/"+icon+".svg", QSize(32,32));

        buttonContainer->setLayout(buttonLayout);
        buttonContainer->setObjectName("sort_item");
        buttonContainer->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        buttonContainer->setStyleSheet(SORT_ITEM_WIDGET);
        buttonContainer->setMaximumSize(QSize(38, 38));
        buttonContainer->setMinimumSize(QSize(38, 38));
        buttonIcon->setContentsMargins(0,0,0,0);
        buttonLayout->setContentsMargins(0, 0, 0, 0);
        buttonContainer->setContentsMargins(0,0,0,0);
        buttonLayout->setAlignment(Qt::AlignCenter);
        buttonLayout->addWidget(buttonIcon);

        titleContainer->addWidget(buttonContainer);
        connect(buttonIcon, &SwgButton::clicked, this, &ToolbarWidget::onButtinPressed);
    }

    this->title = title;
    this->setLayout(titleContainer);
}

ToolbarWidget::~ToolbarWidget() {}
