#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QSlider>
#include <iostream>
#include <QUdpSocket>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mSocket = new QUdpSocket(this);



    // Engine
    mHrzSlider = new QSlider(Qt::Horizontal);
    mHrzSliderValue = new QLabel();
    textValue = new QLabel();

    // Flap
    flapSlider = new QSlider(Qt::Horizontal);
    flapValue = new QLabel();
    flapText = new QLabel();

    // Ailerons
    aileronsSlider = new QSlider(Qt::Horizontal);
    aileronsSliderValue = new QLabel();
    aileronsSliderText = new QLabel();


    // Elevator
    elevatorSlider = new QSlider(Qt::Horizontal);
    elevatorSliderValue = new QLabel();
    elevatorSliderText = new QLabel();

    // Rudder
    rudderSlider = new QSlider(Qt::Horizontal);
    rudderSliderValue = new QLabel();
    rudderSliderText = new QLabel();



    // engine layout
    QHBoxLayout *tHBoxLayout = new QHBoxLayout;

    tHBoxLayout->addWidget(textValue);
    tHBoxLayout->addWidget(mHrzSlider);
    tHBoxLayout->addWidget(mHrzSliderValue);
    ui->verticalLayout->addLayout(tHBoxLayout);

    textValue->setText("Engine Power  ");

    mHrzSlider->setMinimum(0);
    mHrzSlider->setMaximum(100);
    mHrzSlider->setSingleStep(5);
    mHrzSlider->setPageStep(20);
    mHrzSlider->setTracking(false);

    mHrzSliderValue->setText(QString::number(mHrzSlider->value()));
    connect(mHrzSlider,&QSlider::sliderMoved,this,&MainWindow::setHrzSliderValue);


    // flap layout
    QHBoxLayout *flapLayout = new QHBoxLayout;
    flapLayout->addWidget(flapText);
    flapLayout->addWidget(flapSlider);
    flapLayout->addWidget(flapValue);

    ui->verticalLayout->addLayout(flapLayout);

    flapText->setText("Flap Angle  ");

    flapSlider->setMinimum(0);
    flapSlider->setMaximum(100);
    flapSlider->setSingleStep(5);
    flapSlider->setPageStep(20);
    flapSlider->setTracking(false);

    // flap
    flapValue->setText(QString::number(flapSlider->value()));
    connect(flapSlider,&QSlider::sliderMoved,this,&MainWindow::flapHrzSliderValue);





    // Ailerons layout
    QHBoxLayout *aileronsLayout = new QHBoxLayout;
    aileronsLayout->addWidget(aileronsSliderText);
    aileronsLayout->addWidget(aileronsSlider);
    aileronsLayout->addWidget(aileronsSliderValue);

    ui->verticalLayout->addLayout(aileronsLayout);

    aileronsSliderText->setText("Ailerons ");

    aileronsSlider->setMinimum(-100);
    aileronsSlider->setMaximum(100);
    aileronsSlider->setSingleStep(5);
    aileronsSlider->setPageStep(20);
    aileronsSlider->setTracking(false);

    // Ailerons
    aileronsSliderValue->setText(QString::number(aileronsSlider->value()));
    connect(aileronsSlider,&QSlider::sliderMoved,this,&MainWindow::aileronsHrzSliderValue);



    // Elevator layout
    QHBoxLayout *elevatorLayout = new QHBoxLayout;
    elevatorLayout->addWidget(elevatorSliderText);
    elevatorLayout->addWidget(elevatorSlider);
    elevatorLayout->addWidget(elevatorSliderValue);

    ui->verticalLayout->addLayout(elevatorLayout);

    elevatorSliderText->setText("Elevator ");

    elevatorSlider->setMinimum(-100);
    elevatorSlider->setMaximum(100);
    elevatorSlider->setSingleStep(5);
    elevatorSlider->setPageStep(20);
    elevatorSlider->setTracking(false);

    // Elevator
    elevatorSliderValue->setText(QString::number(elevatorSlider->value()));
    connect(elevatorSlider,&QSlider::sliderMoved,this,&MainWindow::elevatorHrzSliderValue);



    // Rudder layout
    QHBoxLayout *rudderLayout = new QHBoxLayout;
    rudderLayout->addWidget(rudderSliderText);
    rudderLayout->addWidget(rudderSlider);
    rudderLayout->addWidget(rudderSliderValue);

    ui->verticalLayout->addLayout(rudderLayout);

    rudderSliderText->setText("Rudder ");

    rudderSlider->setMinimum(-100);
    rudderSlider->setMaximum(100);
    rudderSlider->setSingleStep(5);
    rudderSlider->setPageStep(20);
    rudderSlider->setTracking(false);

    // Rudder
    rudderSliderValue->setText(QString::number(rudderSlider->value()));
    connect(rudderSlider,&QSlider::sliderMoved,this,&MainWindow::rudderHrzSliderValue);


    // UDP bölümü
    QHBoxLayout *UDPLayout = new QHBoxLayout;
    UDPlabel = new QLabel();
    UDPLayout->addWidget(UDPlabel);
    ui->verticalLayout->addLayout(UDPLayout);

    udpSocket=new QUdpSocket(this);
        udpSocket->bind(QHostAddress::Any,8888);//Bind ip and port, it can be Any, LocalHost
       //label display status
        statusText=statusText+"wait for connecting..."+"\n";
        UDPlabel->setText(statusText);
       //Bind the signal slot and react when data is received
        connect(udpSocket,SIGNAL(readyRead()),this,SLOT(ProcessPendingDatagram()));

}






MainWindow::~MainWindow()
{
    delete ui;
}




// UDP bölümü
void MainWindow::ProcessPendingDatagram()
{
   //Wait for data reception to complete before processing
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray recvData;
        recvData.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(recvData.data(), recvData.size(),&clientIp,&clientPort);//Read data and ip and port from the sender’s package and assign them to the variables of the class
        statusText+="connet from "+clientIp.toString()+":"+QString::number(clientPort)+" ";
        statusText+=recvData+"\n";
       //Display to the status label
        UDPlabel->setText(statusText);
       //forward it back
        SocketSend("from server:"+recvData,clientIp,clientPort);
    }
}

void MainWindow::SocketSend(QString sendStr,QHostAddress targetIp,quint16 targetPort)
{
    udpSocket->writeDatagram(sendStr.toStdString().c_str(),sendStr.length(),targetIp,targetPort);
}



//unity object left-handed
void MainWindow::on_leftBtn_clicked()
{
    SocketSend("leftrotate",clientIp,clientPort);
}

//unity object right rotation
void MainWindow::on_rightBtn_clicked(float iValue)
{
    float a = iValue/100;
    rudderSliderValue->setText(" Rudder value: "+QString::number(a));
    SocketSend(QString::number(a),clientIp,clientPort);
}






// fonkisyon bölümü

void MainWindow::setHrzSliderValue(int iValue)
{
    //std::cout<<iValue<<"\n";
    float a = iValue*0.69;
    mHrzSliderValue->setText(QString::number(a)+ " hp ");
    SocketSend(QString::number(a),clientIp,clientPort);
}
void MainWindow::flapHrzSliderValue(int iValue)
{
    //std::cout<<iValue<<"\n";
    float a = iValue/53.7;
    flapValue->setText(QString::number(a)+" Radian ");
    SocketSend(QString::number(a),clientIp,clientPort);
}

void MainWindow::aileronsHrzSliderValue(float iValue)
{
    //std::cout<<iValue<<"\n";
    float a = iValue/100;
    aileronsSliderValue->setText(" Aileron value: "+QString::number(a));
    SocketSend(QString::number(a),clientIp,clientPort);
}

void MainWindow::elevatorHrzSliderValue(float iValue)
{
    //std::cout<<iValue<<"\n";
    float a = iValue/100;
    elevatorSliderValue->setText(" Elevator value: "+QString::number(a));
    SocketSend(QString::number(a),clientIp,clientPort);
}

void MainWindow::rudderHrzSliderValue(float iValue)
{
    //std::cout<<iValue<<"\n";
    float a = iValue/100;
    rudderSliderValue->setText(" Rudder value: "+QString::number(a));
    SocketSend(QString::number(a),clientIp,clientPort);
}
