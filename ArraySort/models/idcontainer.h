#ifndef IDCONTAINER_H
#define IDCONTAINER_H

#include <common/base/basemodel.h>


class IdContainer : public BaseModel {
public:
    int id;

    IdContainer(int id);
};

#endif // IDCONTAINER_H
