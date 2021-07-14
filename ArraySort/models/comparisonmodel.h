#ifndef COMPARISONMODEL_H
#define COMPARISONMODEL_H

#include <common/base/basemodel.h>



class ComparisonModel : public BaseModel {
public:
    int firstId = -1;
    int secondId = -1;

    ComparisonModel(int first);
};

#endif // COMPARISONMODEL_H
