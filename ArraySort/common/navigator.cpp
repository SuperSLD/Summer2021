#include "navigator.h"

#include <QLinkedList>

Navigator::Navigator(
        SlidingStackedWidget *container,
        BaseFragmentFactory *screensFactory
) {
    qDebug("create navigator");
    this->screensFactory = screensFactory;
    this->currentContainer = container;
    qDebug("create start fragment");
    BaseFragment* startFragment = getStartScreen();
    qDebug("append start fragment");
    this->stack.append(startFragment);

    qDebug("add widget");
    currentContainer->addWidget(stack.last());
    currentContainer->setCurrentIndex(0);
}

Navigator::~Navigator() {
}

void Navigator::navigateTo(QString tag) {
    qDebug("Navigator navigateTo");
    BaseFragment *newFragment = this->screensFactory->create(tag);
    stack.last()->onPause();
    disconnectFragment(stack.last());
    connectFragment(newFragment);
    stack.append(newFragment);
    currentContainer->addWidget(newFragment);
    currentContainer->slideInIdx(stack.size()-1);
}

void Navigator::back() {
    qDebug("Navigator back");
    currentContainer->slideInIdx(stack.size()-2);
    connect(currentContainer, &SlidingStackedWidget::animationFinished, this, &Navigator::removeOnFinishLast);
}

void Navigator::removeOnFinishLast() {
    disconnect(currentContainer, &SlidingStackedWidget::animationFinished, this, &Navigator::removeOnFinishLast);
    currentContainer->removeWidget(stack.last());
    delete stack.last();
    stack.removeLast();
    connectFragment(stack.last());
    stack.last()->onResume();
}

void Navigator::replace(QString tag) {
    qDebug("Navigator replace");
    BaseFragment *newFragment = this->screensFactory->create(tag);
    connect(currentContainer, &SlidingStackedWidget::animationFinished, this, &Navigator::removeOnReplace);
    disconnectFragment(stack.last());
    stack.append(newFragment);
    currentContainer->addWidget(newFragment);
    currentContainer->slideInIdx(stack.size()-1);
}

void Navigator::removeOnReplace() {
    disconnect(currentContainer, &SlidingStackedWidget::animationFinished, this, &Navigator::removeOnReplace);
    connectFragment(stack.last());
    BaseFragment* last = stack.last();
    stack.removeLast();
    currentContainer->removeWidget(stack.last());
    stack.removeLast();
    stack.append(last);
}

void Navigator::newRootScreen(QString tag) {
    qDebug("Navigator newRootScreen");
    BaseFragment *newFragment = this->screensFactory->create(tag);
    connect(currentContainer, &SlidingStackedWidget::animationFinished, this, &Navigator::removeOnRoot);
    disconnectFragment(stack.last());
    stack.append(newFragment);
    connectFragment(newFragment);
    currentContainer->addWidget(newFragment);
    currentContainer->slideInIdx(stack.size()-1);
}

void Navigator::removeOnRoot() {
    disconnect(currentContainer, &SlidingStackedWidget::animationFinished, this, &Navigator::removeOnRoot);
    BaseFragment* last = stack.last();
    stack.clear();
    for(int i = 0; i <= currentContainer->count()-1; i++)
    {
        QWidget* widget = currentContainer->widget(i);
        currentContainer->removeWidget(widget);
        widget->deleteLater();
    }
    stack.append(last);
}

void Navigator::backWhithData(BaseModel* model) {
    back();
    stack.last()->bindData(model);
}

void Navigator::navigateWhithData(QString tag, BaseModel* model) {
    navigateTo(tag);
    stack.last()->bindData(model);
}


void Navigator::replaceWhithData(QString tag, BaseModel* model) {
    replace(tag);
    stack.last()->bindData(model);
}

BaseFragment* Navigator::getStartScreen() {
    return createAndConnect(this->screensFactory->createStart());
}

void Navigator::connectFragment(BaseFragment *fragment) {
    qDebug("Navigator connect slots");
    connect(fragment, &BaseFragment::back, this, &Navigator::back);
    connect(fragment, &BaseFragment::replace, this, &Navigator::replace);
    connect(fragment, &BaseFragment::navigateTo, this, &Navigator::navigateTo);
    connect(fragment, &BaseFragment::newRootScreen, this, &Navigator::newRootScreen);
    connect(fragment, &BaseFragment::backWhithData, this, &Navigator::backWhithData);
    connect(fragment, &BaseFragment::navigateWhithData, this, &Navigator::navigateWhithData);
    connect(fragment, &BaseFragment::replaceWhithData, this, &Navigator::replaceWhithData);
}

void Navigator::disconnectFragment(BaseFragment *fragment) {
    qDebug("Navigator disconnect slots");
    disconnect(fragment, &BaseFragment::back, this, &Navigator::back);
    disconnect(fragment, &BaseFragment::replace, this, &Navigator::replace);
    disconnect(fragment, &BaseFragment::navigateTo, this, &Navigator::navigateTo);
    disconnect(fragment, &BaseFragment::newRootScreen, this, &Navigator::newRootScreen);
    disconnect(fragment, &BaseFragment::backWhithData, this, &Navigator::backWhithData);
    disconnect(fragment, &BaseFragment::navigateWhithData, this, &Navigator::navigateWhithData);
    disconnect(fragment, &BaseFragment::replaceWhithData, this, &Navigator::replaceWhithData);
}

BaseFragment* Navigator::createAndConnect(QString tag) {
    BaseFragment *fragment = this->screensFactory->create(tag);
    qDebug("Navigator create screen");
    connectFragment(fragment);
    return fragment;
}
