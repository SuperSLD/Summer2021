#ifndef BASEFRAGMENT_H
#define BASEFRAGMENT_H

#include "basemodel.h"

#include <QFrame>
#include <QVBoxLayout>
#include <QWidget>

/**
 * @brief The BaseFragment class
 *
 * Базовый фрагмент приложения.
 */
class BaseFragment: public QFrame {
    Q_OBJECT

signals:
    void back();
    void backWhithData(BaseModel* model);

    void navigateTo(QString tag);
    void navigateWhithData(QString tag, BaseModel* model);

    void newRootScreen(QString tag);
    void replace(QString tag);
    void replaceWhithData(QString tag, BaseModel* model);

protected:
    void clearList(QLayout *list);
public:
    BaseFragment();
    ~BaseFragment();

    virtual void onPause();
    virtual void onResume();
    virtual void bindData(BaseModel* model);
};

#endif // BASEFRAGMENT_H
