#include "basesort.h"
#include <QList>

BaseSort::BaseSort() {

}

BaseSort::~BaseSort() {
    
}

QString BaseSort::getTitle() {
    return this->title; 
}

QString BaseSort::getShortDescription() {
    return this->shortDescription;
}

QString BaseSort::getDescription() {
    return this->description;
}

QString BaseSort::getStepString() {
    return this->stepString;
}

QString BaseSort::getStepValue() {
    return this->stepValue;
}

void BaseSort::setKey(int key) {
    this->key = key;
}

int BaseSort::getFactoryKey() {
    return this->key;
}

QList<QList<int>> BaseSort::sort(QList<int> array) {
    qDebug("base sort called");
    QList<QList<int>> steps;
    steps.append(array);
    steps.append(array);
    steps.append(array);
    steps.append(array);
    steps.append(array);
    return steps;
}

QList<int> BaseSort::generateStartArray(int size) {
    QList<int> newList;
    for (int i = 1; i <= size; i++) {
        newList.append(i);
    }
    for (int i = 0; i < size; i++) {
        newList.swapItemsAt(i, arc4random()%size);
    }
    return newList;
}

QList<int> BaseSort::cloneArray(QList<int> array) {
    QList<int> newList;
    for (int i = 0; i < array.length(); i++) {
        newList.append(array[i]);
    }
    return newList;
}

QList<QString> BaseSort::getAlgoritm() {
    return this->algoritm;
}

QString BaseSort::getSourceCode() {
    return this->source;
}
