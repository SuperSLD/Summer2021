#ifndef CATALOGFRAGMENT_H
#define CATALOGFRAGMENT_H

#include <QLabel>
#include <common/base/basefragment.h>
#include <sort/sortfactory.h>



class CatalogFragment : public BaseFragment {
   Q_OBJECT
private:
    QVBoxLayout *itemsContainer;
    SortFactory *factory;

    QList<QList<QString>> markers;

    QLabel* createFilterCard(QList<QString> marker);
public:
    CatalogFragment();
    ~CatalogFragment();

    void bindData(BaseModel *model) override;
public slots:
    void onBack();
    void onOpenFilter();
    void onSelectSort(int key);
};

#endif // CATALOGFRAGMENT_H
