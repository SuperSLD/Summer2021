#include "swgbutton.h"
#include "toolbarwidget.h"

#include <QHBoxLayout>
#include <qlabel.h>

#include <stylecontainer.h>
using namespace styles;

ToolbarWidget::ToolbarWidget(QString title, bool showBack) {
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

    this->title = title;
    this->setLayout(titleContainer);
}

ToolbarWidget::~ToolbarWidget() {}
