#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <QLabel>
#include <QUdpSocket>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QUdpSocket;


class MainWindow : public QMainWindow
{
    Q_OBJECT




public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    QUdpSocket *mSocket;

signals:
    void  yawValueChanged(float pYaw);
    void  rollValueChanged(float pRoll);
    void  pitchValueChanged(float pPitch);
    void  powerValueChanged(float pPower);
    void  flapValueChanged(float pFlap);


private slots:
    void setHrzSliderValue(float iValue);
    void flapHrzSliderValue(float iValue);
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

// UDP bölümü

private:
    QString statusText;//Status information
    QUdpSocket *udpSocket;//Socket
    QHostAddress clientIp;//Client ip
    quint16 clientPort;//Client port
    QLabel *UDPlabel;

    void SocketSend(QString sendStr,QHostAddress targetIp,quint16 targetPort);//Send data, you can send to the specified target, or broadcast
private slots:
    void ProcessPendingDatagram();//Respond when data is received
    void on_leftBtn_clicked();
    void on_rightBtn_clicked(float iValue);


};

#endif // MAINWINDOW_H
