#ifndef FILTERFRAGMENT_H
#define FILTERFRAGMENT_H

#include <common/base/basefragment.h>

#include <ui/widgets/filteritemwidget.h>



class FilterFragment : public BaseFragment {
    Q_OBJECT
private:
    QVBoxLayout *itemsContainer;

    QList<FilterItemWidget*> list;
public:
    FilterFragment();
    ~FilterFragment();

    void bindData(BaseModel *model) override;
public slots:
    void onBack();
    void onFinish();
    void clearFilter();
};

#endif // FILTERFRAGMENT_H
