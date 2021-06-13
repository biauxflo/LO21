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
    GraphAutomate.h \
    chargesim.h \
    createsim.h \
    menucreation.h \
    popuploadmodele.h \
    simload.h \
    simulateur.h \
    fenetrejeu.h




SOURCES += \
    Automate.cpp \
    Cellule.cpp \
    Etat.cpp \
    GameLifeTransition.cpp \
    Reseau.cpp \
    MooreGeneral.cpp \
    NeumannGeneral.cpp \
    chargesim.cpp \
    createsim.cpp \
    menucreation.cpp \
    popuploadmodele.cpp \
    simload.cpp \
    simulateur.cpp \
    AutomateException.cpp \
    fenetrejeu.cpp \
    main.cpp \
    Arbitraire.cpp \
    BrianBrainTransition.cpp \
    GriffeathTransition.cpp \
    GraphAutomate.cpp \


FORMS += \
    chargesim.ui \
    createsim.ui \
    fenetrejeu.ui \
    menucreation.ui \
    popuploadmodele.ui \
    simload.ui

