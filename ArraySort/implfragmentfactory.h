#ifndef IMPLFRAGMENTFACTORY_H
#define IMPLFRAGMENTFACTORY_H

#include <QString>

#include <common/base/basefragmentfactory.h>


namespace screens {
    static const QString SERVER_URL = "http://jutter.online/mytask";
    //static const QString SERVER_URL = "http://localhost:8080";

    static const QString SPLASH_TAG = "splash";
    static const QString MAIN_MENU_TAG = "start";
    static const QString CONFIRM_EXIT_TAG = "confirm_exit";
    static const QString CATALOG_TAG = "catalog";
    static const QString CATALOG_DETAIL_TAG = "catalog_detail";
    static const QString VS_FIRST_TAG = "vs_first";
    static const QString VS_SECKND_TAG = "vs_second";
    static const QString VS_DETAIL_TAG = "vs_detail";
    static const QString FILTER_TAG = "filter";

};

class ImplFragmentFactory: public BaseFragmentFactory {
public:
    ImplFragmentFactory();
    ~ImplFragmentFactory();

    BaseFragment* create(QString tag) override;
    QString createStart() override;
};

#endif // IMPLFRAGMENTFACTORY_H
