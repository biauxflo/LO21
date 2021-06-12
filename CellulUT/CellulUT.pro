QT += widgets
QT += xml
QT += gui

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
    Simulateur.h \
    graph_automate.h \
    mainwindow.h



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
    graph_automate.cpp \
    main.cpp \
    Arbitraire.cpp \
    BrianBrainTransition.cpp \
    GriffeathTransition.cpp \
    Simulateur.cpp \
    mainwindow.cpp

FORMS += \
    mainwindow.ui
