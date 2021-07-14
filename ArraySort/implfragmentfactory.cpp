#include "implfragmentfactory.h"

#include <QString>

#include <ui/confitmexitframgent.h>
#include <ui/menufragment.h>
#include <ui/splashfragment.h>

#include <ui/catalog/catalogfragment.h>
#include <ui/catalog/sortdetailfragment.h>

#include <ui/comparison/comparisonfragment.h>
#include <ui/comparison/selectfirstfragment.h>
#include <ui/comparison/selectsecondfragment.h>

using namespace screens;

ImplFragmentFactory::ImplFragmentFactory(){}
ImplFragmentFactory::~ImplFragmentFactory(){}

BaseFragment* ImplFragmentFactory::create(QString tag) {
    qDebug("ScreensFactory create");
    if (tag == SPLASH_TAG) {
        return new SplashFragment;
    } else if (tag == MAIN_MENU_TAG) {
        return new MenuFragment;
    } else if (tag == CONFIRM_EXIT_TAG) {
        return new ConfitmExitFramgent;
    } else if (tag == CATALOG_TAG) {
        return new CatalogFragment;
    } else if (tag == CATALOG_DETAIL_TAG) {
        return new SortDetailFragment;
    } else if (tag == VS_FIRST_TAG) {
        return new SelectFirstFragment;
    } else if (tag == VS_SECKND_TAG) {
        return new SelectSecondFragment;
    } else if (tag == VS_DETAIL_TAG) {
        return new ComparisonFragment;
    } else {
        return nullptr;
    }
}

QString ImplFragmentFactory::createStart() {
    return SPLASH_TAG;
}
