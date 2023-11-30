#include "ARRAY.h"

ARRAY::ARRAY(uint8_t A1, uint8_t A2, uint8_t A3, uint8_t A4, uint8_t A5)
{
    _A1 = A1;
    _A2 = A2;
    _A3 = A3;
    _A4 = A4;
    _A5 = A5;

    int IRvalues[5] = {0, 0, 0, 0, 0};

    pinMode(_A1, INPUT);
    pinMode(_A2, INPUT);
    pinMode(_A3, INPUT);
    pinMode(_A4, INPUT);
    pinMode(_A5, INPUT);
}

void ARRAY::readSensorValue()
{
    uint8_t irArrayPins[5] = {_A1, _A2, _A3, _A4, _A5};
    for (int i = 0; i < 5; i++)
    {
        IRvalues[i] = analogRead(irArrayPins[i]);
        Serial.print(IRvalues[i]);
        Serial.print(" ");
    }
    Serial.println();
}

void ARRAY::printSensorValue()
{
    Serial.print(IRvalues[0]);
    Serial.print(" ");
    Serial.print(IRvalues[1]);
    Serial.print(" ");
    Serial.print(IRvalues[2]);
    Serial.print(" ");
    Serial.print(IRvalues[3]);
    Serial.print(" ");
    Serial.println(IRvalues[4]);
}

void ARRAY::calibrate()
{
    uint8_t analogPins[5] = {A1, A2, A3, A4, A5};

    for (int i = 0; i < 5; i++)
    {
        minVals[i] = maxVals[i] = analogRead(analogPins[i]);
    }

    for (int i = 0; i < 10000; i++)
    {

        for (int j = 0; j < 5; j++)
        {
            int readValue = analogRead(analogPins[j]);

            if (readValue < minVals[j])
            {
                minVals[j] = readValue;
            }

            else if (readValue > maxVals[j])
            {
                maxVals[j] = readValue;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        threshold[i] = (minVals[i] + maxVals[i]) / 2;
    }
}

bool ARRAY::isOnLine()
{
    bool returnValue = false;
        for (int i = 0; i < 5; i++)
        {
            IRvalues[i] = map(analogRead(i), minVals[i], maxVals[i], 0, 1000);
            IRvalues[i] = constrain(IRvalues[i], 0, 1000);

            if (((isBlackLine == 1) && (IRvalues[i] > 700)) || ((isBlackLine == 0) && (IRvalues[i] < 700)))
            {
                returnValue = true;
            }
        }
        return returnValue;
}

    int ARRAY::calcError()
    {
        ARRAY::readSensorValue();
        int error = 3 * IRvalues[0] + 2 * IRvalues[1] - 2 * IRvalues[3] - 3 * IRvalues[4];
        if (isBlackLine)
        {
            return error = error * -1;
        }
        return error;
    }