#ifndef UDPSENDER_H
#define UDPSENDER_H
#include <QObject>
#include <QQmlEngine>
#include <QUdpSocket>

class UdpSender : public QObject
{
public:
    Q_INVOKABLE void sendMessage(QString messageText);
    static QObject* udpSenderProvider(QQmlEngine* engine, QJSEngine* scriptEngine);
signals:
    void messageSent(bool success);
private:
    Q_OBJECT
    UdpSender();
    static UdpSender* instance;
    QUdpSocket* m_udpSocket;
};

#endif // UDPSENDER_H
