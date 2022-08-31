#include "mainwindow.h"
#include "controller.h"

#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller controller;
    MainWindow w;

    // Rudder
    QObject::connect(&w, &MainWindow::yawValueChanged, &controller, &Controller::onYawValueChanged);

    // Ailerons
    QObject::connect(&w, &MainWindow::rollValueChanged, &controller, &Controller::onRollValuChanged);

    // Elevator
    QObject::connect(&w, &MainWindow::pitchValueChanged, &controller, &Controller::onPitchValuChanged);

    // Power
    QObject::connect(&w,&MainWindow::powerValueChanged,&controller,&Controller::onPowerValueChanged);


    // Flap
    QObject::connect(&w,&MainWindow::flapValueChanged,&controller,&Controller::onFlapValueChanged);

    w.show();
    return a.exec();
}
