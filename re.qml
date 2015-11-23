import QtQuick 1.0

Item {
    Rectangle {
        id : rect
        x: parent.x
        y: parent.y
        width: parent.width
        height: parent.height
        color: "lightgreen"

        Text {
            anchors.left: rect.left
            text:"Hello QML"
        }
    }

}

