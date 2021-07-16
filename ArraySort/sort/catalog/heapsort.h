#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <sort/basesort.h>

class HeapSort : public BaseSort{
public:
    HeapSort();

    QList<QList<int>> sort(QList<int> array) override;
};

#endif // HEAPSORT_H
