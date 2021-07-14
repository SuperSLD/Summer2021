#ifndef SELECTSECONDFRAGMENT_H
#define SELECTSECONDFRAGMENT_H

#include <common/base/basefragment.h>

#include <sort/sortfactory.h>

#include <models/comparisonmodel.h>



class SelectSecondFragment: public BaseFragment {
    Q_OBJECT
private:
    QVBoxLayout *itemsContainer;
    SortFactory *factory;

    ComparisonModel *firstSelection = new ComparisonModel(-1);
public:
    SelectSecondFragment();
    ~SelectSecondFragment();

    void bindData(BaseModel *model) override;
public slots:
    void onBack();
    void onSelectSort(int key);
};
#endif // SELECTSECONDFRAGMENT_H
