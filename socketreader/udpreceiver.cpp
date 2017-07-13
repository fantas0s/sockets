#include "udpreceiver.h"
#include <QNetworkDatagram>

UdpReceiver* UdpReceiver::instance = Q_NULLPTR;
const QHostAddress senderAddress = QHostAddress::LocalHost;
const quint16 senderPort = 7755;

UdpReceiver::UdpReceiver()
{
    m_udpSocket = new QUdpSocket(this);
    m_udpSocket->bind(senderAddress, senderPort);
    connect(m_udpSocket, SIGNAL(readyRead()),
            this, SLOT(readPendingDatagrams()));
}

QObject* UdpReceiver::udpReceiverProvider(QQmlEngine* engine, QJSEngine* scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)
    if( !instance )
        instance = new UdpReceiver();
    return instance;
}

void UdpReceiver::readPendingDatagrams()
{
    while (m_udpSocket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = m_udpSocket->receiveDatagram();
        QString payloadString = QString::fromUtf8(datagram.data());
        payloadString.append("\n");
        emit messageReceived(payloadString);
    }
}
