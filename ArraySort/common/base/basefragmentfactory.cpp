#include "basefragment.h"
#include "basefragmentfactory.h"

BaseFragmentFactory::BaseFragmentFactory() {

}

BaseFragmentFactory::~BaseFragmentFactory() {

}

BaseFragment* BaseFragmentFactory::create(QString tag) {return nullptr;}

QString BaseFragmentFactory::createStart() {return nullptr;}
