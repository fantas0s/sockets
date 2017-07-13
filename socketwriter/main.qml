import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import myapp.udpsender 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Socket writer app")
    id: root

    function afterSending(success) {
        sendButton.text = qsTr("Send")
        sendButton.enabled = true
        textEdit.enabled = true
        if( success ) {
            textEdit.text = ""
        }
    }
    Component.onCompleted: {
        UdpSenderSingleton.messageSent.connect(afterSending)
    }

    TextEdit {
        id: textEdit
        text: qsTr("Enter some text...")
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        width: parent.width / 2
    }
    Rectangle {
        id: borderRect
        anchors.fill: textEdit
        anchors.margins: -10
        color: "transparent"
        border.width: 1
    }

    Button {
        id: sendButton
        text: qsTr("Send")
        width: textEdit.width
        anchors.top: borderRect.bottom
        anchors.left: textEdit.left
        onClicked: {
            sendButton.text = qsTr("Sending...")
            sendButton.enabled = false
            textEdit.enabled = false
            UdpSenderSingleton.sendMessage(textEdit.text)
        }
    }
}
