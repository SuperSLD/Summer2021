#ifndef SORTITEMWIDGET_H
#define SORTITEMWIDGET_H

#include <QFrame>

#include <sort/basesort.h>

/**
 * @brief The SortItemWidget class
 *
 * Виджет с элементом списка сортировок.
 */
class SortItemWidget : public QFrame {
    Q_OBJECT
private:
    BaseSort *model;
public:
    SortItemWidget(BaseSort *sort, QString buttonText = "Подрообнее");
public slots:
    void onButtonClicl();
signals:
    /**
     * @brief selectSort
     *
     * Сигнал вызываемый при выборе сортировки.
     *
     * @param key ключ по которому
     *        создана сортировка.
     */
    void selectSort(int key);
};

#endif // SORTITEMWIDGET_H
