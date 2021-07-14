#ifndef COMPARISONFRAGMENT_H
#define COMPARISONFRAGMENT_H

#include <common/base/basefragment.h>

#include <sort/sortfactory.h>

#include <ui/widgets/sortstepwidget.h>

#include <QLabel>

class ComparisonFragment : public BaseFragment {
    Q_OBJECT

private:
    QVBoxLayout *itemsContainer;
    QVBoxLayout *firstContainer;
    QVBoxLayout *secondContainer;
    SortFactory *factory;

    SortStepWidget *firstIlustration;
    SortStepWidget *secondIlustration;

    BaseSort *firstSort;
    BaseSort *secondSort;

    QLabel *firstProgress;
    QLabel *secondProgress;

    QList<QList<int>> firstSteps;
    QList<QList<int>> secondSteps;
    int step;

    void createLine(QVBoxLayout *container, BaseSort *sort, int w);
public:
    ComparisonFragment();
    ~ComparisonFragment();

    void bindData(BaseModel *model) override;
public slots:
    void onBack();
    void updateSortStep();
};

#endif // COMPARISONFRAGMENT_H
