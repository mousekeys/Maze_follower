
// A is left MOTOR
// B is right MOTOR

// MOTORS(PWMA, AIN1, AIN2, PWMB, BIN1, BIN2);

#include "MOTORS.h"

MOTORS::MOTORS(unsigned short PWMA, unsigned short AIN1, unsigned short AIN2,
               unsigned short BIN1, unsigned short BIN2, unsigned short PWMB)
{
    _PWMA = PWMA;
    _AIN1 = AIN1;
    _AIN2 = AIN2;
    _PWMB = PWMB;
    _BIN1 = BIN1;
    _BIN2 = BIN2;

    pinMode(_PWMA, OUTPUT);
    pinMode(_AIN1, OUTPUT);
    pinMode(_AIN2, OUTPUT);
    pinMode(_PWMB, OUTPUT);
    pinMode(_BIN1, OUTPUT);
    pinMode(_BIN2, OUTPUT);
}

void MOTORS::forward(unsigned short pwmVal)
{

    digitalWrite(_AIN1, HIGH);
    digitalWrite(_AIN2, LOW);
    digitalWrite(_BIN1, HIGH);
    digitalWrite(_BIN2, LOW);

    analogWrite(_PWMA, pwmVal);
    analogWrite(_PWMB, pwmVal);
}

void MOTORS::backward(unsigned short pwmVal)
{

    digitalWrite(_AIN1, LOW);
    digitalWrite(_AIN2, HIGH);
    digitalWrite(_BIN1, LOW);
    digitalWrite(_BIN2, HIGH);

    analogWrite(_PWMA, pwmVal);
    analogWrite(_PWMB, pwmVal);
}

void MOTORS::turnLeft(unsigned short pwmVal)
{
    digitalWrite(_AIN1, LOW);
    digitalWrite(_AIN2, LOW);
    digitalWrite(_BIN1, HIGH);
    digitalWrite(_BIN2, LOW);

    analogWrite(_PWMA, 0);
    analogWrite(_PWMB, pwmVal);
}

void MOTORS::turnLeft(unsigned short pwmLeftVal, unsigned short pwmRightVal)
{

    digitalWrite(_AIN1, LOW);
    digitalWrite(_AIN2, HIGH);
    digitalWrite(_BIN1, HIGH);
    digitalWrite(_BIN2, LOW);

    analogWrite(_PWMA, pwmLeftVal);
    analogWrite(_PWMB, pwmRightVal);
}

void MOTORS::turnRight(unsigned short pwmVal)
{
    digitalWrite(_AIN1, HIGH);
    digitalWrite(_AIN2, LOW);
    digitalWrite(_BIN1, LOW);
    digitalWrite(_BIN2, LOW);

    analogWrite(_PWMA, pwmVal);
    analogWrite(_PWMB, 0);
}

void MOTORS::turnRight(unsigned short pwmLeftVal, unsigned short pwmRightVal)
{

    digitalWrite(_AIN1, HIGH);
    digitalWrite(_AIN2, LOW);
    digitalWrite(_BIN1, LOW);
    digitalWrite(_BIN2, HIGH);

    analogWrite(_PWMA, pwmLeftVal);
    analogWrite(_PWMB, pwmRightVal);
}

void MOTORS::turnAround(unsigned short pwmVal)
{

    digitalWrite(_AIN1, HIGH);
    digitalWrite(_AIN2, LOW);
    digitalWrite(_BIN1, LOW);
    digitalWrite(_BIN2, HIGH);

    analogWrite(_PWMA, pwmVal);
    analogWrite(_PWMB, pwmVal);
}

void MOTORS::stop()
{

    digitalWrite(_AIN1, LOW);
    digitalWrite(_AIN2, LOW);
    digitalWrite(_BIN1, LOW);
    digitalWrite(_BIN2, LOW);

    analogWrite(_PWMA, 0);
    analogWrite(_PWMB, 0);
}

void MOTORS::moveA(unsigned short pwmVal)
{

    digitalWrite(_AIN1, pwmVal > 0 ? HIGH : LOW);
    digitalWrite(_AIN2, pwmVal < 0 ? HIGH : LOW);

    analogWrite(_PWMA, pwmVal);
}

void MOTORS::moveB(unsigned short pwmVal)
{

    digitalWrite(_BIN1, pwmVal > 0 ? HIGH : LOW);
    digitalWrite(_BIN2, pwmVal < 0 ? HIGH : LOW);

    analogWrite(_PWMB, pwmVal);
}

void MOTORS::drive(unsigned short pwmLeftVal, unsigned short pwmRightVal)
{
    digitalWrite(_AIN1, pwmLeftVal > 0 ? HIGH : LOW);
    digitalWrite(_AIN2, pwmLeftVal < 0 ? HIGH : LOW);
    digitalWrite(_BIN1, pwmRightVal > 0 ? HIGH : LOW);
    digitalWrite(_BIN2, pwmRightVal < 0 ? HIGH : LOW);

    analogWrite(_PWMA, pwmLeftVal);
    analogWrite(_PWMB, pwmRightVal);
}