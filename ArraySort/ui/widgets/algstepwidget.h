#ifndef ALGSTEPWIDGET_H
#define ALGSTEPWIDGET_H

#include <QFrame>

class AlgStepWidget : public QFrame {
    Q_OBJECT
public:
    AlgStepWidget(int position, QString text);
};

#endif // ALGSTEPWIDGET_H
