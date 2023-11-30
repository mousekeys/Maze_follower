#ifndef MOTORS_h
#define MOTORS_h

#include <Arduino.h>

class MOTORS
{
private:
  unsigned short _PWMA;
  unsigned short _AIN1;
  unsigned short _AIN2;
  unsigned short _BIN1;
  unsigned short _BIN2;
  unsigned short _PWMB;

public:
  MOTORS(unsigned short PWMA, unsigned short AIN1, unsigned short AIN2,unsigned short BIN1, unsigned short BIN2, unsigned short PWMB);

  void forward(unsigned short pwmVal);
  void backward(unsigned short pwmVal);
  void turnLeft(unsigned short pwmVal);
  void turnLeft(unsigned short pwmValA, unsigned short pwmValB);
  void turnRight(unsigned short pwVal);
  void turnRight(unsigned short pwmValA, unsigned short pwmValB);
  void turnAround(unsigned short pwmVal);
  void moveA(unsigned short pwmVal);
  void moveB(unsigned short pwmVal);
  void drive(unsigned short pwmLeftVal, unsigned short pwmRightVal);
  void stop();
};

#endif