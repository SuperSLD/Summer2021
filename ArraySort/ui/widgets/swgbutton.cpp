#include "swgbutton.h"

#include <QSize>
#include <QString>
#include <QSvgWidget>
#include <QVBoxLayout>

SwgButton::SwgButton(QString path, QSize size) {
    QVBoxLayout *mainContainer = new QVBoxLayout;
    QSvgWidget *image = new QSvgWidget(path);
    image->setMaximumSize(size);
    image->setMinimumSize(size);
    mainContainer->addWidget(image);
    mainContainer->setContentsMargins(0,0,0,0);
    image->setStyleSheet("background-color:#00FFFFFF;");
    this->setStyleSheet("border:none; padding:0px; background-color:#00FFFFFF;");
    this->setMinimumSize(size);
    this->setMaximumSize(size);
    this->setLayout(mainContainer);

}

SwgButton::~SwgButton() {

}
