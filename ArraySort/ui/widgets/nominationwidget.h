#ifndef NOMINATIONWIDGET_H
#define NOMINATIONWIDGET_H

#include <QFrame>

class NominationWidget : public QFrame {
    Q_OBJECT
public:
    NominationWidget(QList<QString> nomination);
};

#endif // NOMINATIONWIDGET_H
