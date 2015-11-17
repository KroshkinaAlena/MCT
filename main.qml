import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow
{
    id: base
    visible: true
    width: 1000; height: 800
    title: qsTr("Some Application")

    menuBar: MenuBar{

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

     Rectangle{
         id: viewFild
         x: 200; y: 50
         width: parent.width-x; height: parent.height-y;
         //border.color: "black"
        // border.width: 3
         //color: "lightsteelblue"
         /*gradient: Gradient{
             GradientStop { position: 1.0; color: "white" }
             GradientStop { position: 0.0; color: "AntiqueWhite" }
         }*/

         /*ColorAnimation on color{
             from: Qt.rgba(1, 0.5, 0, 1)
             to: Qt.rgba(0.5, 0, 1, 1)
             duration: 1500
             running: true
             loops: Animation.Infinite
         }*/
         Image{
             id: elephant;
             x: parent.x; y: parent.y
             width: 100; height: 100
             source: 'file:///Projects/Images/el.png'
             /*NumberAnimation on x {
                 from: 800
                 to: -100
                 duration: 10000
                 easing.type: Easing.Linear
                 loops: Animation.Infinite;
             }
             */
             Behavior on x {
                 NumberAnimation { duration: 900; easing.type: Easing.OutBounce}
             }
             Behavior on y {
                 NumberAnimation { duration: 900; easing.type: Easing.OutBounce}
             }
         }
         MouseArea {
             anchors.fill: viewFild
             hoverEnabled: true
             onMouseXChanged: { elephant.x = mouseX}
             onMouseYChanged: { elephant.y = mouseY}
         }
         /*Slider {
             id: sliderVertical1
             x: parent; y: parent
             width: 22;  height: parent.height-y;
             orientation: Qt.Vertical
             value: 1.0
         }*/
         Grid{
             rows: 4; columns: 3;
             anchors.centerIn: parent
             spacing: 5
             Rectangle{ width: 100; height: 100; color: "white";}
             Rectangle{ width: 100; height: 100; color: "red"}
             Rectangle{ width: 100; height: 100; color: "red"}
             Rectangle{ width: 100; height: 100; color: "red"}
             Rectangle{ width: 100; height: 100; color: "red"}
             Rectangle{ width: 100; height: 100; color: "red"}
             Rectangle{ width: 100; height: 100; color: "red"}
             Rectangle{ width: 100; height: 100; color: "red"}
             Rectangle{ width: 100; height: 100; color: "red"}
             Rectangle{ width: 100; height: 100; color: "red"}
         }

     }

     Rectangle{
         id: previewFild
         x: 0; y: 50
         width: 200; height: parent.height-50;
         gradient: Gradient{
             GradientStop { position: 1.0; color: "white" }
             GradientStop { position: 0.0; color: "lightsalmon" }
         }
         Column{
             anchors{
                 top: parent.top
                 horizontalCenter: parent.horizontalCenter
                 leftMargin: 5
                 topMargin: 5
                 rightMargin: 5
                 bottomMargin: 5
             }
             spacing: 10
             Rectangle{ width: 100; height: 150; color: "PaleVioletRed"}
             Rectangle{ width: 100; height: 150; color: "PaleVioletRed"}
             Rectangle{ width: 100; height: 150; color: "PaleVioletRed"}
             Rectangle{ width: 100; height: 150; color: "PaleVioletRed"}
             Rectangle{ width: 100; height: 150; color: "PaleVioletRed"}
             Rectangle{ width: 100; height: 150; color: "PaleVioletRed"}
             Rectangle{ width: 100; height: 150; color: "PaleVioletRed"}
             Rectangle{ width: 100; height: 150; color: "PaleVioletRed"}
         }
     }
     Rectangle{
         id: panelFild
         x: 0; y: 0
         width: parent.width; height: 50;
         gradient: Gradient{
             GradientStop { position: 0.0; color: "white" }
             GradientStop { position: 1.0; color: "AntiqueWhite" }
         }
     }



}

