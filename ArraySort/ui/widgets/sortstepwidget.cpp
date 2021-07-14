#include "sortstepwidget.h"

#include <QVBoxLayout>

#include <stylecontainer.h>
using namespace styles;

SortStepWidget::SortStepWidget(int height) {
    QHBoxLayout *mainLayout = new QHBoxLayout;

    // выглядит фигово зато работает
    colors.append("#72B8F9");
    colors.append("#7EB5EE");
    colors.append("#7EB5EE");
    colors.append("#91B0DB");
    colors.append("#96AED6");
    colors.append("#99AED3");
    colors.append("#A3AAC8");
    colors.append("#AAA9C1");
    colors.append("#AAA9C1");
    colors.append("#B3A6B9");
    colors.append("#B8A5B4");
    colors.append("#C2A2A9");
    colors.append("#CC9FA0");
    colors.append("#D49D98");
    colors.append("#DD9B8F");
    colors.append("#E59886");
    colors.append("#E79885");
    colors.append("#EE967E");
    colors.append("#F59477");
    colors.append("#F99272");

    for (int i = 0; i < 20; i++) {
        QFrame *col = new QFrame();
        col->setStyleSheet("background-color: "+colors[i]+"");
        int colH = height - i*(height/20);
        col->setMinimumHeight(colH);
        col->setMaximumHeight(colH);
        mainLayout->addWidget(col);
        mainLayout->setAlignment(col, Qt::AlignBottom);
        colList.append(col);
    }

    mainLayout->setContentsMargins(0,0,0,0);
    this->setLayout(mainLayout);
    this->setMinimumHeight(height);
    this->setMaximumHeight(height);
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
}

void SortStepWidget::drawStep(QList<int> step) {
    for (int i = 0; i < 20; i++) {
        int colH = this->minimumHeight() - step[i]*(this->minimumHeight()/20);
        colList[i]->setMinimumHeight(colH);
        colList[i]->setMaximumHeight(colH);
    }
}
