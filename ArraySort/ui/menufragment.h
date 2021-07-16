#ifndef MENUFRAGMENT_H
#define MENUFRAGMENT_H

#include <common/base/basefragment.h>

#include <ui/widgets/sortitemwidget.h>



class MenuFragment: public BaseFragment {
    Q_OBJECT

private:
    QVBoxLayout *mainVLayout;
    SortItemWidget *randSort;
public:
    MenuFragment();
    ~MenuFragment();
public slots:
    void openCatalog();
    void openVs();
    void closeGame();

    void openRandDetail(int key);

};

#endif // MENUFRAGMENT_H
