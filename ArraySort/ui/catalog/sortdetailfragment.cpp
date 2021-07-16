#include "sortdetailfragment.h"

#include <ui/widgets/algstepwidget.h>
#include <ui/widgets/codeviewwidget.h>
#include <ui/widgets/nominationwidget.h>
#include <ui/widgets/sortstepwidget.h>
#include <ui/widgets/toolbarwidget.h>

#include <models/comparisonmodel.h>
#include <models/idcontainer.h>
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

using namespace screens;
using namespace styles;

SortDetailFragment::SortDetailFragment() {
    //все что нам нужно для отображения попадает на экран
    //в момент бинда так что там и проинициализируем верстку.
}

SortDetailFragment::~SortDetailFragment() {
    delete factory;
    delete itemsContainer;
    delete stepWidget;
}

void SortDetailFragment::bindData(BaseModel *model) {
    IdContainer *idContainer = dynamic_cast<IdContainer*>(model);
    factory = new SortFactory();
    BaseSort *sort = factory->create(idContainer->id);
    qDebug("bind data for detail");
    currentSort = sort;


    // главный контейнер
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    mainVLayout->setAlignment(Qt::AlignTop);
    mainHLayout->addLayout(mainVLayout);
    mainHLayout->setAlignment(Qt::AlignHCenter);

    // заголовок экрана
    ToolbarWidget *toolbar = new ToolbarWidget(sort->getTitle(), true);
    connect(toolbar, &ToolbarWidget::onBackPressed, this, &SortDetailFragment::onBack);
    mainVLayout->addWidget(toolbar);

    // зона прокрутки
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setMinimumWidth(874);
    scrollArea->setMaximumWidth(874);
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

    // иллюстрация сортировки
    stepWidget = new SortStepWidget(252);
    steps = sort->sort(sort->generateStartArray(20));
    stepWidget->drawStep(steps[0]);
    itemsContainer->addWidget(stepWidget);

    // заголовок
    QLabel *title = new QLabel(sort->getTitle());
    title->setStyleSheet(BIG_TITLE_LABLE);
    title->setContentsMargins(0, 16, 0, 12);
    title->setMaximumWidth(874);
    title->setWordWrap(true);
    itemsContainer->addWidget(title);

    // короткое описание
    QLabel *shortDesk = new QLabel(sort->getShortDescription());
    shortDesk->setStyleSheet(HINT_LABLE);
    shortDesk->setContentsMargins(0, 0, 0, 8);
    shortDesk->setMaximumWidth(874);
    shortDesk->setWordWrap(true);
    itemsContainer->addWidget(shortDesk);

    // надписи на карточках
    QLabel *stepExpression = new QLabel(sort->getStepString());
    QLabel *stepValue = new QLabel(sort->getStepValue());
    QHBoxLayout *cardsContainer = new QHBoxLayout();
    stepExpression->setStyleSheet(CARD_BLUE_LABLE);
    stepValue->setStyleSheet(CARD_RED_LABLE);
    cardsContainer->setContentsMargins(0,0,0,8);
    cardsContainer->addWidget(stepExpression);
    cardsContainer->addWidget(stepValue);
    cardsContainer->setAlignment(Qt::AlignLeft);
    itemsContainer->addLayout(cardsContainer);

    // описание
    QLabel *description = new QLabel(sort->getDescription());
    description->setStyleSheet(HINT_LABLE);
    description->setContentsMargins(0, 8, 0, 8);
    description->setMaximumWidth(874);
    description->setWordWrap(true);
    itemsContainer->addWidget(description);

    QList<QString> alg = sort->getAlgoritm();
    // заголовок для алгоритма
    QLabel *algTitle = new QLabel("Алгоритм метода сортировки:");
    algTitle->setStyleSheet(TITLE_LABLE);
    algTitle->setContentsMargins(0, 16, 0, 12);
    algTitle->setMaximumWidth(874);
    algTitle->setWordWrap(true);
    if (alg.size() > 0) {
        itemsContainer->addWidget(algTitle);
    }
    // шаги алгоритма
    for (int i = 0; i < alg.size(); i++) {
        itemsContainer->addWidget(new AlgStepWidget(i+1, alg[i]));
    }

    if (sort->getSourceCode().length() > 0) {
        // заголовок для исходного кода
        QLabel *codeTitle = new QLabel("Реализация метода:");
        codeTitle->setStyleSheet(TITLE_LABLE);
        codeTitle->setContentsMargins(0, 16, 0, 12);
        codeTitle->setMaximumWidth(874);
        codeTitle->setWordWrap(true);
        itemsContainer->addWidget(codeTitle);

        // короткое описание для исходного кода
        QLabel *codeShortDesk = new QLabel("Реализация данного метода сортировки на языке С++.");
        codeShortDesk->setStyleSheet(HINT_LABLE);
        codeShortDesk->setContentsMargins(0, 0, 0, 8);
        codeShortDesk->setMaximumWidth(874);
        codeShortDesk->setWordWrap(true);
        itemsContainer->addWidget(codeShortDesk);

        // отображение исходного кода
        itemsContainer->addWidget(new CodeViewWidget(sort->getSourceCode()));
    }

    if (sort->getNominations().length() > 0) {
        // заголовок для номинаций
        QLabel *codeTitle = new QLabel("Что в итоге можно сказать?");
        codeTitle->setStyleSheet(TITLE_LABLE);
        codeTitle->setContentsMargins(0, 16, 0, 12);
        codeTitle->setMaximumWidth(874);
        codeTitle->setWordWrap(true);
        itemsContainer->addWidget(codeTitle);

        // короткое описание для номинаций
        QLabel *codeShortDesk = new QLabel("Небольшие отметки от составителей справочника, чтоб в методах было проще ориентироваться.");
        codeShortDesk->setStyleSheet(HINT_LABLE);
        codeShortDesk->setContentsMargins(0, 0, 0, 8);
        codeShortDesk->setMaximumWidth(874);
        codeShortDesk->setWordWrap(true);
        itemsContainer->addWidget(codeShortDesk);

        // контейнер для номинаций
        QHBoxLayout *nominationHorisontal = new QHBoxLayout;
        QVBoxLayout *firstCol = new QVBoxLayout;
        QVBoxLayout *secondCol = new QVBoxLayout;
        firstCol->setContentsMargins(0,0,8,0);
        firstCol->setAlignment(Qt::AlignTop);
        secondCol->setContentsMargins(8,0,0,0);
        secondCol->setAlignment(Qt::AlignTop);
        nominationHorisontal->setContentsMargins(0,0,0,0);
        nominationHorisontal->addLayout(firstCol);
        nominationHorisontal->addLayout(secondCol);
        itemsContainer->addLayout(nominationHorisontal);

        // заполнение номинаций
        for (int i = 0; i < sort->getNominations().size(); i++) {
            NominationWidget *nomWidget = new NominationWidget(sort->getNominations()[i]);
            if (i % 2 == 0) {
                firstCol->addWidget(nomWidget);
            } else {
                secondCol->addWidget(nomWidget);
            }
        }
    }

    // кнопка для переходв к сравнению
    QHBoxLayout *buttonContainer = new QHBoxLayout();
    QPushButton *selectButton = new QPushButton("К сравнению");
    selectButton->setStyleSheet(BUTTON_SOLID);
    selectButton->setMinimumWidth(169);
    connect(selectButton, &QPushButton::clicked, this, &SortDetailFragment::onButtonClick);
    buttonContainer->setAlignment(Qt::AlignRight);
    buttonContainer->addWidget(selectButton);
    itemsContainer->addLayout(buttonContainer);


    // запуск таймера для обновления картинки
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&SortDetailFragment::updateSortStep));
    timer->start(100);

    this->setLayout(mainHLayout);
    this->setObjectName("fragment");
}

void SortDetailFragment::onBack() {
    emit back();
}

void SortDetailFragment::updateSortStep() {
    step++;
    if (step >= steps.size()) {
        steps = currentSort->sort(currentSort->generateStartArray(20));
        step = 0;
    }
    stepWidget->drawStep(steps[step]);
}

void SortDetailFragment::onButtonClick() {
    emit navigateWhithData(VS_SECKND_TAG, new ComparisonModel(currentSort->getFactoryKey()));
}
