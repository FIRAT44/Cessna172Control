#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setHrzSliderValue(int iValue);
    void flapHrzSliderValue(int iValue);
    void aileronsHrzSliderValue(float iValue);
    void elevatorHrzSliderValue(float iValue);
    void rudderHrzSliderValue(float iValue);


private:
    Ui::MainWindow *ui;
    QSlider *mHrzSlider;
    QSlider *flapSlider;

    QLabel *mHrzSliderValue;
    QLabel *flapValue;
    QLabel *textValue;
    QLabel *flapText;

    // Ailerons
    QSlider *aileronsSlider;
    QLabel *aileronsSliderValue;
    QLabel *aileronsSliderText;

    // Elevator
    QSlider *elevatorSlider;
    QLabel *elevatorSliderValue;
    QLabel *elevatorSliderText;

    // Rudder
    QSlider *rudderSlider;
    QLabel *rudderSliderValue;
    QLabel *rudderSliderText;

};
#endif // MAINWINDOW_H
