#ifndef SPLASHFRAGMENT_H
#define SPLASHFRAGMENT_H

#include <common/base/basefragment.h>



class SplashFragment: public BaseFragment {
    Q_OBJECT

public:
    SplashFragment();
    ~SplashFragment();
public slots:
    /**
     * @brief openStartScreen
     *
     * Переходим к меню после небольшой
     * задержки, чтобы юзверь успел увидеть
     * лого игры.
     */
    void openStartScreen();
};
#endif // SPLASHFRAGMENT_H
