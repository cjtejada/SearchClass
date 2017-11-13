#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <searchclass.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    SearchClass s;

    engine.rootContext()->setContextProperty("SearchClass", &s);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
