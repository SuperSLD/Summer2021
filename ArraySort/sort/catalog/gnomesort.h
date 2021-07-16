#ifndef GNOMESORT_H
#define GNOMESORT_H

#include <sort/basesort.h>

class GnomeSort : public BaseSort{
public:
    GnomeSort();

        QList<QList<int>> sort(QList<int> array) override;
};

#endif // GNOMESORT_H
