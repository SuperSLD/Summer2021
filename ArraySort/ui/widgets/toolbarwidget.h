#ifndef TOOLBARWIDGET_H
#define TOOLBARWIDGET_H

#include <QFrame>


/**
 * @brief The ToolbarWidget class
 *
 * Заголовок каждого экрана.
 */
class ToolbarWidget: public QFrame {
    Q_OBJECT
private:
    QString title;
public:
    /**
     * @brief ToolbarWidget
     *
     * Инициализация виджета с заголовком.
     *
     * @param title название экрана которое увидит пользователь.
     */
    ToolbarWidget(QString title, bool showBack = false);
    ~ToolbarWidget();
signals:
    void onBackPressed();
};

#endif // TOOLBARWIDGET_H
