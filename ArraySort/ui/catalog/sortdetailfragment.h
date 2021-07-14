#ifndef SORTDETAILFRAGMENT_H
#define SORTDETAILFRAGMENT_H

#include <common/base/basefragment.h>
#include <sort/sortfactory.h>
#include <ui/widgets/sortstepwidget.h>


class SortDetailFragment : public BaseFragment {
    Q_OBJECT
private:
    QVBoxLayout *itemsContainer;
    SortFactory *factory;

    SortStepWidget *stepWidget;

    BaseSort *currentSort;
    int step = 0;
    QList<QList<int>> steps;
public:
    SortDetailFragment();
    ~SortDetailFragment();

    void bindData(BaseModel *model) override;
public slots:
    void onBack();
    void updateSortStep();
    void onButtonClick();
};

#endif // SORTDETAILFRAGMENT_H
