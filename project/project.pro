QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_prof.cpp \
    add_stage.cpp \
    add_stud.cpp \
    add_theme.cpp \
    change_prof.cpp \
    change_stage.cpp \
    change_student.cpp \
    change_theme.cpp \
    greeting.cpp \
    list_of_prof.cpp \
    list_of_stages.cpp \
    list_of_students.cpp \
    list_of_themes.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    my_themes.cpp \
    pgreeting.cpp \
    professor_project.cpp \
    role.cpp \
    role_type.cpp \
    sgreeting.cpp \
    student_project.cpp

HEADERS += \
    add_prof.h \
    add_stage.h \
    add_stud.h \
    add_theme.h \
    change_prof.h \
    change_stage.h \
    change_student.h \
    change_theme.h \
    greeting.h \
    list_of_prof.h \
    list_of_stages.h \
    list_of_students.h \
    list_of_themes.h \
    login.h \
    mainwindow.h \
    my_themes.h \
    pgreeting.h \
    professor_project.h \
    role.h \
    role_type.h \
    sgreeting.h \
    student_project.h

FORMS += \
    add_prof.ui \
    add_stage.ui \
    add_stud.ui \
    add_theme.ui \
    change_prof.ui \
    change_stage.ui \
    change_student.ui \
    change_theme.ui \
    greeting.ui \
    list_of_prof.ui \
    list_of_stages.ui \
    list_of_students.ui \
    list_of_themes.ui \
    login.ui \
    mainwindow.ui \
    my_themes.ui \
    pgreeting.ui \
    professor_project.ui \
    role.ui \
    sgreeting.ui \
    student_project.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    greeting.qrc
