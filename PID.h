#ifndef PID_h
#define PID_h

#include <Arduino.h>

class PID
{
private:
    int _error;
    float _kp;
    float _ki;
    float _kd;
    int _previousError;
    int _P;
    int _I;
    int _D;
    int _PIDValue;

public:
    PID(float kp, float ki, float kd);
    int calcPID(int error);
    float getKP();
    float getKI();
    float getKD();
    void setPID(float kp, float ki, float kd);
};

#endif