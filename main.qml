import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.3

Window {
    id: root
    width: 300
    height: 480
    visible: true

    Column {
        width: parent.width
        height: parent.height

        TextField {
            id: tf
            placeholderText: "Type the name of the state you want to look for..."
            onTextChanged: SearchClass.setModel(text)
            width: root.width
            height: 30
        }

        ListView {
            width: root.width; height: root.height
            spacing: 5

            model: SearchClass.model
            delegate: MouseArea {
                height: 30
                width: root.width
                    Text {
                        id: txt
                        text: modelData
                           anchors.centerIn: parent}
                    onClicked: console.log(txt.text)
            }
        }
    }
}
