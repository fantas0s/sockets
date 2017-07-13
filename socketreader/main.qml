import QtQuick 2.8
import QtQuick.Window 2.2
import myapp.udpreceiver 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Socket Reader App")
    id: root

    function handleReceivedMessage(messageString) {
        textEdit.text += messageString
    }
    Component.onCompleted: {
        UdpReceiverSingleton.messageReceived.connect(handleReceivedMessage)
    }

    TextEdit {
        id: textEdit
        text: ""
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        width: parent.width / 2
        height: parent.height / 2
        enabled: false
        Rectangle {
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            border.width: 1
        }
    }
}
