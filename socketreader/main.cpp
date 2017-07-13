#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqml.h>
#include "udpreceiver.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterSingletonType<UdpReceiver>("myapp.udpreceiver", 1, 0, "UdpReceiverSingleton", UdpReceiver::udpReceiverProvider);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
