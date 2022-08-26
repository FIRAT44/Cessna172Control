#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QSlider>
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

    // Ailerons
    rudderSliderValue->setText(QString::number(rudderSlider->value()));
    connect(rudderSlider,&QSlider::sliderMoved,this,&MainWindow::rudderHrzSliderValue);

}






MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setHrzSliderValue(int iValue)
{
    //std::cout<<iValue<<"\n";
    float a = iValue*0.69;
    mHrzSliderValue->setText(QString::number(a)+ " hp ");
}
void MainWindow::flapHrzSliderValue(int iValue)
{
    //std::cout<<iValue<<"\n";
    float a = iValue/53.7;
    flapValue->setText(QString::number(a)+" Radian ");
}

void MainWindow::aileronsHrzSliderValue(float iValue)
{
    //std::cout<<iValue<<"\n";
    float a = iValue/100;
    aileronsSliderValue->setText(" Aileron value: "+QString::number(a));
}

void MainWindow::elevatorHrzSliderValue(float iValue)
{
    //std::cout<<iValue<<"\n";
    float a = iValue/100;
    elevatorSliderValue->setText(" Elevator value: "+QString::number(a));
}

void MainWindow::rudderHrzSliderValue(float iValue)
{
    //std::cout<<iValue<<"\n";
    float a = iValue/100;
    rudderSliderValue->setText(" Rudder value: "+QString::number(a));
}
