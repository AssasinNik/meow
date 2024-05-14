QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    PhotoLabel.cpp \
    add_theme.cpp \
    greeting.cpp \
    list_of_themes.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    my_themes.cpp \
    profil.cpp \
    register.cpp

HEADERS += \
    PhotoLabel.h \
    add_theme.h \
    add_theme_копия.h \
    greeting.h \
    list_of_themes.h \
    login.h \
    mainwindow.h \
    my_themes.h \
    profil.h \
    register.h

FORMS += \
    add_theme.ui \
    greeting.ui \
    list_of_themes.ui \
    login.ui \
    mainwindow.ui \
    my_themes.ui \
    profil.ui \
    register.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    greeting.qrc
