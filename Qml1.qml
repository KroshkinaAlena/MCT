import QtQuick 1.1

Item {
    ListView {
        id: listView1
        x: parent.x
        y: parent.y
        width: parent.width
        height:parent.height
        spacing: 0
        model: ListModel {
            ListElement {
                name: "Grey"
                colorCode: "grey"
            }

            ListElement {
                name: "Red"
                colorCode: "red"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }
        }
        delegate: Item {
            x: parent.x
            width: listView1.width
            height: listView1.width
            Row {
                id: row1
                Rectangle {
                    width: listView1.width-100
                    height: listView1.width-100
                    color: colorCode
                }

                Text {
                    text: name
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
                spacing: 10
            }
        }
    }

}

