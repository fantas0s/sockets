#include <QGuiApplication>
#include <qqml.h>
#include <QQmlApplicationEngine>
#include "udpsender.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterSingletonType<UdpSender>("myapp.udpsender", 1, 0, "UdpSenderSingleton", UdpSender::udpSenderProvider);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
