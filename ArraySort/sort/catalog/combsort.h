#ifndef COMBSORT_H
#define COMBSORT_H

#include <sort/basesort.h>



class CombSort : public BaseSort
{
public:
    CombSort();

    QList<QList<int>> sort(QList<int> array) override;
};

#endif // COMBSORT_H
