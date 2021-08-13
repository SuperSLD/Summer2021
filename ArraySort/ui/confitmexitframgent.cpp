#include "confitmexitframgent.h"

#include <QCoreApplication>

#include <QSvgWidget>
#include <qlabel.h>
#include <qpushbutton.h>

#include <stylecontainer.h>
#include <implfragmentfactory.h>
using namespace screens;
using namespace styles;

ConfitmExitFramgent::ConfitmExitFramgent() {
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    QFrame *centerConainer = new QFrame;

    QVBoxLayout *startMainLayout = new QVBoxLayout;
    QHBoxLayout *startContent = new QHBoxLayout;

    QVBoxLayout *startVerticalContent = new QVBoxLayout;
    QLabel *title = new QLabel("Закрыть приложение?");
    QLabel *subtitle = new QLabel("Вы точно уверены что хотите выйти из приложения?");

    QVBoxLayout *buttonContainer = new QVBoxLayout;

    QPushButton *loginButton = new QPushButton("Отмена");
    QPushButton *regButton = new QPushButton("Закрыть");

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

    loginButton->setStyleSheet(BUTTON_SOLID);
    connect(loginButton, &QPushButton::clicked, this, &ConfitmExitFramgent::cancel);
    regButton->setStyleSheet(BUTTON_EMPTY);
    connect(regButton, &QPushButton::clicked, this, &ConfitmExitFramgent::closeGame);
    buttonContainer->addWidget(loginButton);
    buttonContainer->addWidget(regButton);

    startContent->setContentsMargins(46,46,46,46);

    centerConainer->setStyleSheet(FRAME_8PX_WHITE);
    centerConainer->setLayout(startContent);
    startContent->addLayout(startMainLayout);

    mainHLayout->addWidget(centerConainer);
    mainHLayout->setAlignment(Qt::AlignCenter);
    mainVLayout->addLayout(mainHLayout);
    mainVLayout->setAlignment(Qt::AlignCenter);

    this->setLayout(mainVLayout);
}

ConfitmExitFramgent::~ConfitmExitFramgent() {

}

void ConfitmExitFramgent::cancel() {
    emit back();
}

void ConfitmExitFramgent::closeGame() {
    QCoreApplication::quit();
}
