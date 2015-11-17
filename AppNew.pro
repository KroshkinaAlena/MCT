TEMPLATE = app

QT += qml quick widgets
QT += declarative

SOURCES += main.cpp \
    ProjectFunctions.cpp

RESOURCES += qml.qrc
CONFIG+=qml_debug
CONFIG+=qml_release


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    ProjectFunctions.h

