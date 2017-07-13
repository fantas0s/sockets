#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H
#include <QObject>
#include <QQmlEngine>
#include <QUdpSocket>

class UdpReceiver : public QObject
{
public:
    static QObject* udpReceiverProvider(QQmlEngine* engine, QJSEngine* scriptEngine);
signals:
    void messageReceived(QString payloadString);
private slots:
    void readPendingDatagrams();
private:
    Q_OBJECT
    UdpReceiver();
    static UdpReceiver* instance;
    QUdpSocket* m_udpSocket;
};
#endif // UDPRECEIVER_H
