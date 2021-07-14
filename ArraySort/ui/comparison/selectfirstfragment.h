#ifndef SELECTFIRSTFRAGMENT_H
#define SELECTFIRSTFRAGMENT_H

#include <common/base/basefragment.h>

#include <sort/sortfactory.h>



class SelectFirstFragment : public BaseFragment {
    Q_OBJECT
private:
    QVBoxLayout *itemsContainer;
    SortFactory *factory;
public:
    SelectFirstFragment();
    ~SelectFirstFragment();
public slots:
    void onBack();
    void onSelectSort(int key);
};

#endif // SELECTFIRSTFRAGMENT_H
