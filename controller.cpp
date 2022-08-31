#include "controller.h"
#include <QDebug>


Controller::Controller(QObject *parent)
    : QObject{parent}
{

}

// Rudder
void Controller::onYawValueChanged(float pYaw)
{
    mYaw = pYaw/100;
    qDebug()<<"Yaw val: "<<mYaw;
    // TODO :  Send message to unity service,mCommunicator
    //mCommunicator.sendMessage(mYaw);
}

// Ailerons
void Controller::onRollValuChanged(float pRoll){
    mRoll = pRoll/100;
    qDebug()<<"Roll val: "<<mRoll;
}

// Elevator
void Controller::onPitchValuChanged(float pPitch){
    mPitch = pPitch/100;
    qDebug()<<"Pitch val: "<<mPitch;
}


// Power
void Controller::onPowerValueChanged(float pPower){
    mPower = pPower/100;
    qDebug()<<"Power val: "<<mPower;
}


// Flap
void Controller::onFlapValueChanged(float pFlap){
    mFlap = pFlap/1000;
    qDebug()<<"Flap val: "<<pFlap;
}

