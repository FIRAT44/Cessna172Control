#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "communicator.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);

public slots:
    void  onYawValueChanged(float pYaw);
    void  onRollValuChanged(float pRoll);
    void  onPitchValuChanged(float pPitch);
    void  onPowerValueChanged(float pPower);
    void  onFlapValueChanged(float mFlap);

signals:

private:
    float        mYaw;
    float        mRoll;
    float        mPitch;
    float        mPower;
    float        mFlap;

    Communicator mCommunicator;



};

#endif // CONTROLLER_H
