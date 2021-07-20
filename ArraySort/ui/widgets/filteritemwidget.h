#ifndef FILTERITEMWIDGET_H
#define FILTERITEMWIDGET_H

#include <QFrame>
#include <QList>
#include <QPushButton>


class FilterItemWidget : public QFrame {
    Q_OBJECT
private:
    QPushButton *selectButton;
    bool selected = false;
    QList<QString> marker;

    /**
     * @brief drawState
     *
     * Обновление состояния кнопки.
     */
    void drawState();
public:
    FilterItemWidget(QList<QString> marker);

    /**
     * @brief isSelected
     *
     * Проверка на то что этот элемент выбран.
     *
     * @return true если выбрано.
     */
    bool isSelected();

    /**
     * @brief getMarker
     *
     * получение маркера прикрепленного
     * к текущему элементу.
     *
     * @return маркер из сортировки.
     */
    QList<QString> getMarker();

    /**
     * @brief setSelected
     *
     * Установка изначального состояния.
     *
     * @param selected выбрано или нет.
     */
    void setSelected(bool selected);
public slots:
    void changeState();
};

#endif // FILTERITEMWIDGET_H
