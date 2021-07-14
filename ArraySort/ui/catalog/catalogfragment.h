#ifndef CATALOGFRAGMENT_H
#define CATALOGFRAGMENT_H

#include <common/base/basefragment.h>
#include <sort/sortfactory.h>



class CatalogFragment : public BaseFragment {
   Q_OBJECT
private:
    QVBoxLayout *itemsContainer;
    SortFactory *factory;
public:
    CatalogFragment();
    ~CatalogFragment();
public slots:
    void onBack();
    void onSelectSort(int key);
};

#endif // CATALOGFRAGMENT_H
