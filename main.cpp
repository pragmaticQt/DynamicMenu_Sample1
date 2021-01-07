#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "MenuModel.h"
#include "UserMenuModel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<MenuModel>("ca.imaginativethinking.tutorial.menu", 1, 0, "MenuModel");
    qmlRegisterType<UserMenuModel>("ca.imaginativethinking.tutorial.menu", 1, 0, "UserMenuModel");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
