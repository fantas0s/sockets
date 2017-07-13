#include "udpsender.h"

UdpSender* UdpSender::instance = Q_NULLPTR;
const QHostAddress recipientAddress = QHostAddress::LocalHost;
const quint16 recipientPort = 7755;

UdpSender::UdpSender()
{
    m_udpSocket = new QUdpSocket(this);
}

QObject* UdpSender::udpSenderProvider(QQmlEngine* engine, QJSEngine* scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)
    if( !instance )
        instance = new UdpSender();
    return instance;
}

void UdpSender::sendMessage(QString messageText)
{
    const quint64 bytesWritten = m_udpSocket->writeDatagram(messageText.toUtf8(), recipientAddress, recipientPort);
    emit messageSent(bytesWritten >= 0);
}
