#ifndef ARRAY_h
#define ARRAY_h

#include <Arduino.h>

class ARRAY
{
private:
  uint8_t _A1;
  uint8_t _A2;
  uint8_t _A3;
  uint8_t _A4;
  uint8_t _A5;
  int minVals[5];
  int maxVals[5];
  int threshold[5];
  bool isBlackLine = 1;

public:
  int IRvalues[5];
  ARRAY(uint8_t A1, uint8_t A2, uint8_t A3, uint8_t A4, uint8_t A5);

  void readSensorValue();
  void printSensorValue();
  void calibrate();
  bool isOnLine();
  int calcError();
};

#endif