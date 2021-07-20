QT += core gui
QT += network
QT += sql
QT += widgets
QT += svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    common/base/basefragment.cpp \
    common/base/basefragmentfactory.cpp \
    common/base/basemodel.cpp \
    common/navigator.cpp \
    implfragmentfactory.cpp \
    main.cpp \
    mainwindow.cpp \
    models/comparisonmodel.cpp \
    models/filtermodel.cpp \
    models/idcontainer.cpp \
    sort/basesort.cpp \
    sort/catalog/bubblesort.cpp \
    sort/catalog/combsort.cpp \
    sort/catalog/gnomesort.cpp \
    sort/catalog/heapsort.cpp \
    sort/catalog/insertionsort.cpp \
    sort/catalog/quicksort.cpp \
    sort/catalog/selectionsort.cpp \
    sort/catalog/shakersort.cpp \
    sort/sortfactory.cpp \
    stylecontainer.cpp \
    ui/catalog/catalogfragment.cpp \
    ui/catalog/filterfragment.cpp \
    ui/catalog/sortdetailfragment.cpp \
    ui/comparison/comparisonfragment.cpp \
    ui/comparison/selectfirstfragment.cpp \
    ui/comparison/selectsecondfragment.cpp \
    ui/confitmexitframgent.cpp \
    ui/menufragment.cpp \
    ui/splashfragment.cpp \
    ui/widgets/algstepwidget.cpp \
    ui/widgets/codeviewwidget.cpp \
    ui/widgets/filteritemwidget.cpp \
    ui/widgets/nominationwidget.cpp \
    ui/widgets/slidingstackedwidget.cpp \
    ui/widgets/sortitemwidget.cpp \
    ui/widgets/sortstepwidget.cpp \
    ui/widgets/swgbutton.cpp \
    ui/widgets/toolbarwidget.cpp

HEADERS += \
    common/base/basefragment.h \
    common/base/basefragmentfactory.h \
    common/base/basemodel.h \
    common/navigator.h \
    implfragmentfactory.h \
    mainwindow.h \
    models/comparisonmodel.h \
    models/filtermodel.h \
    models/idcontainer.h \
    sort/basesort.h \
    sort/catalog/bubblesort.h \
    sort/catalog/combsort.h \
    sort/catalog/gnomesort.h \
    sort/catalog/heapsort.h \
    sort/catalog/insertionsort.h \
    sort/catalog/quicksort.h \
    sort/catalog/selectionsort.h \
    sort/catalog/shakersort.h \
    sort/sortfactory.h \
    stylecontainer.h \
    ui/catalog/catalogfragment.h \
    ui/catalog/filterfragment.h \
    ui/catalog/sortdetailfragment.h \
    ui/comparison/comparisonfragment.h \
    ui/comparison/selectfirstfragment.h \
    ui/comparison/selectsecondfragment.h \
    ui/confitmexitframgent.h \
    ui/menufragment.h \
    ui/splashfragment.h \
    ui/widgets/algstepwidget.h \
    ui/widgets/codeviewwidget.h \
    ui/widgets/filteritemwidget.h \
    ui/widgets/nominationwidget.h \
    ui/widgets/slidingstackedwidget.h \
    ui/widgets/sortitemwidget.h \
    ui/widgets/sortstepwidget.h \
    ui/widgets/swgbutton.h \
    ui/widgets/toolbarwidget.h

RESOURCES += \
    resc.qrc \
    resc.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
