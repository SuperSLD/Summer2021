#ifndef SWGBUTTON_H
#define SWGBUTTON_H

#include <qpushbutton.h>



class SwgButton: public QPushButton {
    Q_OBJECT

public:
    SwgButton(QString path, QSize size);
    ~SwgButton();
};


#endif // SWGBUTTON_H
