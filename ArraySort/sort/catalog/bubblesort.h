#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <sort/basesort.h>

class BubbleSort : public BaseSort {
public:
    BubbleSort();

    QList<QList<int>> sort(QList<int> array) override;
};

#endif // BUBBLESORT_H
