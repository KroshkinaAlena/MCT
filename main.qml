import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow
{
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar
    {
        Menu
        {
            title: qsTr("File")
            MenuItem
            {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem
            {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Label
    {
        text: qsTr("Hello World")
        anchors.verticalCenterOffset: -162
        anchors.horizontalCenterOffset: -141
        anchors.centerIn: parent
    }
    Image
    {
        id: image1
        x: 230
        y: 157
        width: 243
        height: 222
        source: 'file:///Projects/App2/AppNew/Images/elephant.png'
    }
}

