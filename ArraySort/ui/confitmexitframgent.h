#ifndef CONFITMEXITFRAMGENT_H
#define CONFITMEXITFRAMGENT_H

#include <common/base/basefragment.h>


class ConfitmExitFramgent: public BaseFragment {
    Q_OBJECT

public:
    ConfitmExitFramgent();
    ~ConfitmExitFramgent();
public slots:
    void cancel();
    void closeGame();
};

#endif // CONFITMEXITFRAMGENT_H
