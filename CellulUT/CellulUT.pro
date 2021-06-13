QT += widgets
QT += xml
QT += gui
QT += core
QT += core gui

HEADERS += \
    Automate.h \
    BrianBrainTransition.h \
    Cellule.h \
    Etat.h \
    GameLifeTransition.h \
    Reseau.h \
    Moore.h \
    MooreGeneral.h \
    Newmann.h \
    NewmannGeneral.h \
    Transition.h \
    Voisinage.h \
    VoisinageARayon.h \
    AutomateException.h \
    Arbitraire.h \
    GriffeathTransition.h \
    fenetredejeu.h \
    gamewindow.h



SOURCES += \
    Automate.cpp \
    Cellule.cpp \
    Etat.cpp \
    GameLifeTransition.cpp \
    Reseau.cpp \
    Moore.cpp \
    MooreGeneral.cpp \
    Neumann.cpp \
    NeumannGeneral.cpp \
    Voisinage.cpp \
    VoisinageARayon.cpp \
    AutomateException.cpp \
    fenetredejeu.cpp \
    main.cpp \
    Arbitraire.cpp \
    BrianBrainTransition.cpp \
    GriffeathTransition.cpp \
    gamewindow.cpp

FORMS += \
    fenetredejeu.ui \
    gamewindow.ui \
    mainwindow.ui \
