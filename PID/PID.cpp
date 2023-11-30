
#include "PID.h"

PID::PID(float kp, float ki, float kd)
{

    _kp = kp;
    _ki = ki;
    _kd = kd;
    _error = 0;
    _previousError = 0;
    _P = 0;
    _I = 0;
    _D = 0;
    _PIDValue = 0;
}

int PID::calcPID(int error)
{
    _error = error;
    _P = _error;
    _I = _I + _error;
    _D = _error - _previousError;
    _PIDValue = (_P * _kp) + (_I * _ki) + (_D * _kd);
    _previousError = _error;
    return _PIDValue;
}

float PID::getKP()
{
    return _kp;
}

float PID::getKI()
{
    return _ki;
}

float PID::getKD()
{
    return _kd;
}

void PID::setPID(float kp, float ki, float kd)
{
    _kp = kp;
    _ki = ki;
    _kd = kd;
}