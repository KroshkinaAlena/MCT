TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    ProjectFunctions.cpp

RESOURCES += qml.qrc
CONFIG+=qml_debug


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    ProjectFunctions.h

