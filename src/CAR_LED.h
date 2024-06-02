/////////////////////////////////////////////////////////////////
/*
    CAR_LED.h - Arduino Library to simplify digital output.
    Created by Tommy Carlsson.
*/
/////////////////////////////////////////////////////////////////

#pragma once

#include <Arduino.h>
#include <CAR_Timer.h>

/////////////////////////////////////////////////////////////////

enum CAR_LED_BlinkState {
    DISABLE,
    DELAY,
    BLINK
};

/////////////////////////////////////////////////////////////////

class CAR_LED
{
  private:
    byte _outputPin;
    byte _outputState;
	byte _blinkStartState;
    CAR_LED_BlinkState _blinkState;

    unsigned int _highTime;
    unsigned int _lowTime;
    unsigned int _delayTime;
    int _blinkTimes;
    CAR_Timer _timeSinceLastOutputChange;

  public:
    CAR_LED(byte p_outputPin);
    void high(void);
    void low(void);
    void toggle(void);
    void blink(unsigned int p_lowTime, unsigned int p_highTime);
    void blink(unsigned int p_lowTime, unsigned int p_highTime, unsigned int p_delayTime);
    void blink(unsigned int p_lowTime, unsigned int p_highTime, unsigned int p_delayTime, int p_blinkTimes);
    byte getState(void);
    void loop(void);
};
