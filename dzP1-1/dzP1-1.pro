TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        src/main.cpp \
        src/Bomb.cpp \
        src/Crater.cpp \
        src/Ground.cpp \
        src/House.cpp \
        src/LevelGUI.cpp \
        src/MyTools.cpp \
        src/Plane.cpp \
        src/SBomber.cpp \
        src/ScreenSingleton.cpp \
        src/Tank.cpp

HEADERS += \
    include/Bomb.h \
    include/Crater.h \
    include/DestroyableGroundObject.h \
    include/DynamicObject.h \
    include/GameObject.h \
    include/Ground.h \
    include/House.h \
    include/LevelGUI.h \
    include/MyTools.h \
    include/Plane.h \
    include/SBomber.h \
    include/ScreenSingleton.h \
    include/Tank.h \
    include/Timer.h \
    include/enums/ConsoleColors.h \
    include/enums/CraterSize.h
