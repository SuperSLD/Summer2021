#include "menufragment.h"

#include <QSvgWidget>
#include <qlabel.h>
#include <qpushbutton.h>

#include <stylecontainer.h>
#include <implfragmentfactory.h>
#include <QCoreApplication>
using namespace screens;
using namespace styles;

MenuFragment::MenuFragment() {
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    QFrame *centerConainer = new QFrame;

    QVBoxLayout *startMainLayout = new QVBoxLayout;
    QHBoxLayout *startContent = new QHBoxLayout;
    QSvgWidget *mainImage = new QSvgWidget(":/resc/resc/splash.svg");

    QVBoxLayout *startVerticalContent = new QVBoxLayout;
    QLabel *title = new QLabel("Справочник сортировок");
    QLabel *subtitle = new QLabel("В этом справочнике можно посмотреть на разные виды сортировок и сравнить их между собой по парам.\nОт группы: Арцыбашева, Соляной");

    QVBoxLayout *buttonContainer = new QVBoxLayout;

    QPushButton *listButton = new QPushButton("Справочник");
    QPushButton *vsButton = new QPushButton("Сравнения сортировок");
    QPushButton *regButton = new QPushButton("Выйти");

    title->setStyleSheet(TITLE_LABLE);
    subtitle->setStyleSheet(HINT_LABLE);
    subtitle->setMaximumWidth(335);
    subtitle->setMinimumWidth(335);
    subtitle->setWordWrap(true);
    startVerticalContent->addWidget(title);
    startVerticalContent->addWidget(subtitle);
    startVerticalContent->setAlignment(Qt::AlignTop);
    buttonContainer->setAlignment(Qt::AlignBottom);

    startMainLayout->addLayout(startVerticalContent);
    startMainLayout->addLayout(buttonContainer);

    listButton->setStyleSheet(BUTTON_SOLID);
    connect(listButton, &QPushButton::clicked, this, &MenuFragment::openCatalog);
    vsButton->setStyleSheet(BUTTON_SOLID);
    connect(vsButton, &QPushButton::clicked, this, &MenuFragment::openVs);
    regButton->setStyleSheet(BUTTON_EMPTY);
    connect(regButton, &QPushButton::clicked, this, &MenuFragment::closeGame);
    buttonContainer->addWidget(listButton);
    buttonContainer->addWidget(vsButton);
    buttonContainer->addWidget(regButton);

    startContent->setContentsMargins(46,46,46,46);
    mainImage->setContentsMargins(24,0,56,0);

    centerConainer->setStyleSheet(FRAME_8PX_WHITE);
    centerConainer->setLayout(startContent);
    mainImage->setStyleSheet(START_ICON);
    mainImage->setMinimumSize(QSize(210, 210));
    mainImage->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    startContent->addWidget(mainImage);
    startContent->addLayout(startMainLayout);

    mainHLayout->addWidget(centerConainer);
    mainHLayout->setAlignment(Qt::AlignCenter);
    mainVLayout->addLayout(mainHLayout);
    mainVLayout->setAlignment(Qt::AlignCenter);

    this->setLayout(mainVLayout);
}

MenuFragment::~MenuFragment() {

}

void MenuFragment::openCatalog() {
    emit navigateTo(CATALOG_TAG);
}

void MenuFragment::openVs() {
    emit navigateTo(VS_FIRST_TAG);
}

void MenuFragment::closeGame() {
    emit navigateTo(CONFIRM_EXIT_TAG);
}
