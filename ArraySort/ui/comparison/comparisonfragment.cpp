#include "comparisonfragment.h"

#include <stylecontainer.h>
#include <implfragmentfactory.h>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>
#include <QSettings>
#include <QSvgWidget>
#include <QVBoxLayout>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QJsonArray>
#include <QScrollArea>
#include <QScrollBar>
#include <QNetworkReply>
#include <QColor>
#include <QTimer>

#include <ui/widgets/sortitemwidget.h>
#include <ui/widgets/sortstepwidget.h>
#include <ui/widgets/swgbutton.h>
#include <ui/widgets/toolbarwidget.h>

#include <models/comparisonmodel.h>
#include <models/idcontainer.h>

using namespace screens;
using namespace styles;

ComparisonFragment::ComparisonFragment() {
    //данные для отображения появятся при бинде
    //по этому на конструктор пофиг
}

ComparisonFragment::~ComparisonFragment() {
    delete factory;
    delete itemsContainer;
    delete firstIlustration;
    delete secondIlustration;
}

void ComparisonFragment::bindData(BaseModel *model) {
    ComparisonModel *selection = dynamic_cast<ComparisonModel*>(model);
    factory = new SortFactory();

    firstSort = factory->create(selection->firstId);
    secondSort = factory->create(selection->secondId);

    QHBoxLayout *mainHLayout = new QHBoxLayout;
    QVBoxLayout *mainVLayout = new QVBoxLayout;

    // заголовок экрана
    ToolbarWidget *toolbar = new ToolbarWidget("Сравнение", true);
    connect(toolbar, &ToolbarWidget::onBackPressed, this, &ComparisonFragment::onBack);
    mainVLayout->addWidget(toolbar);

    int bigW = 900;//874;
    step = 0;

    // зона прокрутки
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setMinimumWidth(bigW);
    scrollArea->setMaximumWidth(bigW);
    scrollArea->setFrameShape(QFrame::NoFrame);
    QWidget *scrolContainer = new QWidget;
    scrolContainer->setObjectName("container");
    scrollArea->setStyleSheet(SCROL_BAR);
    QHBoxLayout *deskContainer = new QHBoxLayout;
    itemsContainer = new QVBoxLayout;
    itemsContainer->setAlignment(Qt::AlignTop);
    deskContainer->addLayout(itemsContainer);
    itemsContainer->setContentsMargins(0,0,0,0);
    scrolContainer->setLayout(deskContainer);
    scrollArea->setWidget(scrolContainer);
    scrollArea->setWidgetResizable(true);
    scrollArea->horizontalScrollBar()->setEnabled(false);
    scrollArea->verticalScrollBar()->hide();
    mainVLayout->addWidget(scrollArea);
    mainVLayout->setAlignment(Qt::AlignTop);
    mainHLayout->addLayout(mainVLayout);
    mainHLayout->setAlignment(Qt::AlignHCenter);

    int space = 16;
    int w = bigW/2 - space;

    // два столбца для сравнения
    QHBoxLayout *comparisonContainer = new QHBoxLayout;
    firstContainer = new QVBoxLayout;
    secondContainer = new QVBoxLayout;
    comparisonContainer->setContentsMargins(0,0,0,0);
    firstContainer->setContentsMargins(0,0,space,0);
    secondContainer->setContentsMargins(space,0,0,0);
    firstContainer->setAlignment(Qt::AlignTop);
    secondContainer->setAlignment(Qt::AlignTop);
    comparisonContainer->addLayout(firstContainer);
    comparisonContainer->addLayout(secondContainer);
    itemsContainer->addLayout(comparisonContainer);

    //================================
    //первый столбец
    qDebug("first column");
    // иллюстрация сортировки
    firstIlustration = new SortStepWidget(252);
    QList<int> startArray = firstSort->generateStartArray(20);
    firstSteps = firstSort->sort(startArray);
    firstIlustration->drawStep(firstSteps[0]);
    firstContainer->addWidget(firstIlustration);

    // все остальное
    createLine(firstContainer, firstSort, w);

    firstProgress = new QLabel("Первая сортировка: 0%");
    firstProgress->setStyleSheet(CARD_RED_LABLE);
    firstProgress->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    firstProgress->setMaximumHeight(40);
    firstProgress->setMinimumHeight(40);
    firstContainer->addWidget(firstProgress);

    //================================
    //второй столбец
    qDebug("second column");
    // иллюстрация сортировки
    secondIlustration = new SortStepWidget(252);
    secondSteps = secondSort->sort(secondSort->cloneArray(startArray));
    secondIlustration->drawStep(secondSteps[0]);
    secondContainer->addWidget(secondIlustration);

    // все остальное
    createLine(secondContainer, secondSort, w);

    secondProgress = new QLabel("Вторая сортировка: 0%");
    secondProgress->setStyleSheet(CARD_RED_LABLE);
    secondProgress->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    secondProgress->setMaximumHeight(40);
    secondProgress->setMinimumHeight(40);
    secondContainer->addWidget(secondProgress);

    // запуск таймера для обновления картинки
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&ComparisonFragment::updateSortStep));
    timer->start(100);

    this->setLayout(mainHLayout);
    this->setObjectName("fragment");
}

void ComparisonFragment::onBack() {
    emit back();
}

void ComparisonFragment::createLine(QVBoxLayout *container, BaseSort *sort, int w) {
    // заголовок
    QLabel *title = new QLabel(sort->getTitle());
    title->setStyleSheet(BIG_TITLE_LABLE);
    title->setContentsMargins(0, 16, 0, 12);
    title->setMaximumWidth(w);
    title->setWordWrap(true);
    container->addWidget(title);

    // короткое описание
    QLabel *shortDesk = new QLabel(sort->getShortDescription());
    shortDesk->setStyleSheet(HINT_LABLE);
    shortDesk->setContentsMargins(0, 0, 0, 8);
    shortDesk->setMaximumWidth(w);
    shortDesk->setWordWrap(true);
    container->addWidget(shortDesk);

    // надписи на карточках
    QLabel *stepExpression = new QLabel(sort->getStepString());
    QLabel *stepValue = new QLabel(sort->getStepValue());
    QHBoxLayout *cardsContainer = new QHBoxLayout();
    stepExpression->setStyleSheet(CARD_BLUE_LABLE);
    stepValue->setStyleSheet(CARD_RED_LABLE);
    cardsContainer->setContentsMargins(0,0,0,8);
    stepExpression->setMaximumHeight(40);
    stepExpression->setMinimumHeight(40);
    stepValue->setMaximumHeight(40);
    stepValue->setMinimumHeight(40);
    stepExpression->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    stepValue->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    cardsContainer->addWidget(stepExpression);
    cardsContainer->addWidget(stepValue);
    cardsContainer->setAlignment(Qt::AlignLeft);
    container->addLayout(cardsContainer);

    // описание
    QLabel *description = new QLabel(sort->getDescription());
    description->setStyleSheet(HINT_LABLE);
    description->setContentsMargins(0, 8, 0, 8);
    description->setMaximumWidth(w);
    description->setWordWrap(true);
    container->addWidget(description);
}

void ComparisonFragment::updateSortStep() {
    step++;
    //qDebug("update state");
    //qDebug("step: " + QString::number(step).toLatin1()
    //       + "/ first: " + QString::number(firstSteps.size()).toLatin1()
    //       + "/ second: " + QString::number(secondSteps.size()).toLatin1());
    int maxStep = 0;
    if (firstSteps.length() >= secondSteps.length()) {
        maxStep = firstSteps.length();
    } else {
        maxStep = secondSteps.length();
    }
    if (step >= maxStep) {
        QList<int> startArray = firstSort->generateStartArray(20);
        firstSteps = firstSort->sort(startArray);
        secondSteps = secondSort->sort(startArray);
        step = 0;
    }
    if (step < firstSteps.size()) {
        firstIlustration->drawStep(firstSteps[step]);
    } else {
        firstIlustration->drawStep(firstSteps.last());
    }
    if (step < secondSteps.size()) {
        secondIlustration->drawStep(secondSteps[step]);
    } else {
        secondIlustration->drawStep(secondSteps.last());
    }

    int firstProgress = (float(step)/firstSteps.count()) * 100;
    if (firstProgress >= 100) {
        firstProgress = 100;
    }
    this->firstProgress->setText("Первая сортировка: "+QString::number(firstProgress)+"%");

    int secondProgress = (float(step)/secondSteps.count()) * 100;
    if (secondProgress >= 100) {
        secondProgress = 100;
    }
    this->secondProgress->setText("Первая сортировка: "+QString::number(secondProgress)+"%");

    if (secondProgress >= firstProgress) {
        if (secondProgress == firstProgress) {
            this->firstProgress->setStyleSheet(CARD_BLUE_LABLE);
            this->secondProgress->setStyleSheet(CARD_BLUE_LABLE);
        } else {
            this->firstProgress->setStyleSheet(CARD_RED_LABLE);
            this->secondProgress->setStyleSheet(CARD_BLUE_LABLE);
        }
    } else {
        this->firstProgress->setStyleSheet(CARD_BLUE_LABLE);
        this->secondProgress->setStyleSheet(CARD_RED_LABLE);
    }
}
