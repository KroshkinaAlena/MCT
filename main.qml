import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow
{
    visible: true
    width: 1000
    height: 800
    title: qsTr("Some Application")

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

     Rectangle
     {
         id: viewFild
         x: 200
         y: 50
         width: parent.width-200; height: parent.height-50;
         //border.color: "black"
        // border.width: 3
         //color: "lightsteelblue"
         //rotation: 90;
         gradient: Gradient
         {
             GradientStop { position: 0.0; color: "white" }
             GradientStop { position: 1.0; color: "lightsteelblue" }
         }
         Image
         {
             id: elephant;
             x: 273
             y: 109
             width: parent.width/2; height: parent.height/2
             source: 'file:///Projects/Images/el.png'
         }
     }

     Rectangle
     {
         id: previewFild
         x: 0
         y: 0
         width: 200; height: parent.height;
         gradient: Gradient
         {
             GradientStop { position: 0.0; color: "white" }
             GradientStop { position: 1.0; color: "blue" }
         }
     }


}

