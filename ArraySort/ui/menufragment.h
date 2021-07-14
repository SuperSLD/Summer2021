#ifndef MENUFRAGMENT_H
#define MENUFRAGMENT_H

#include <common/base/basefragment.h>



class MenuFragment: public BaseFragment {
    Q_OBJECT

public:
    MenuFragment();
    ~MenuFragment();
public slots:
    void openCatalog();
    void openVs();
    void closeGame();
};

#endif // MENUFRAGMENT_H
