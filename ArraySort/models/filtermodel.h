#ifndef FILTERMODEL_H
#define FILTERMODEL_H

#include <common/base/basemodel.h>
#include <QList>


class FilterModel : public BaseModel {
public:
    QList<QList<QString>> markers;

    FilterModel(QList<QList<QString>> markers);
};

#endif // FILTERMODEL_H
