#ifndef SORTSTEPWIDGET_H
#define SORTSTEPWIDGET_H

#include <QFrame>
#include <QList>

/**
 * @brief The SortStepWidget class
 *
 * Виджет для отображения поэтапной
 * сортировки массива.
 *
 */
class SortStepWidget : public QFrame {
    Q_OBJECT
private:
    QList<QFrame*> colList;
    QList<QString> colors;
public:
    /**
     * @brief SortStepWidget
     *
     * Конструктор виджета.
     *
     * @param count количество столбцов.
     * @param height высота виджета.
     */
    SortStepWidget(int height);

    /**
     * @brief drawStep
     *
     * Отображение шага решения задачи.
     *
     * @param step шаг сортировки.
     */
    void drawStep(QList<int> step);
};

#endif // SORTSTEPWIDGET_H
