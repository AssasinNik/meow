QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_theme.cpp \
    greeting.cpp \
    list_of_themes.cpp \
    main.cpp \
    mainwindow.cpp \
    my_themes.cpp \
    pgreeting.cpp \
    role.cpp \
    sgreeting.cpp

HEADERS += \
    add_theme.h \
    greeting.h \
    list_of_themes.h \
    mainwindow.h \
    my_themes.h \
    pgreeting.h \
    role.h \
    sgreeting.h

FORMS += \
    add_theme.ui \
    greeting.ui \
    list_of_themes.ui \
    mainwindow.ui \
    my_themes.ui \
    pgreeting.ui \
    role.ui \
    sgreeting.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    greeting.qrc
