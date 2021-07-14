#ifndef SHAKERSORT_H
#define SHAKERSORT_H

#include <sort/basesort.h>


class ShakerSort : public BaseSort {
public:
    ShakerSort();

    QList<QList<int>> sort(QList<int> array) override;
};

#endif // SHAKERSORT_H
