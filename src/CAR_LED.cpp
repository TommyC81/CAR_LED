/////////////////////////////////////////////////////////////////
/*
    CAR_LED.cpp - Arduino Library to manage LED output.
    Created by Tommy Carlsson.
*/
/////////////////////////////////////////////////////////////////

#include <CAR_LED.h>

/////////////////////////////////////////////////////////////////

CAR_LED::CAR_LED(byte p_outputPin) {
    _outputPin = p_outputPin;
    _outputState = LOW;
    _blinkState = DISABLE;
    _highTime = 0;
    _lowTime  = 0;
    _blinkTimes  = -1;
    _timeSinceLastOutputChange = 0;
    pinMode(_outputPin, OUTPUT);
}

void CAR_LED::high(void){
    _blinkState = DISABLE;
    _outputState = HIGH;
    digitalWrite(_outputPin, _outputState);
}

void CAR_LED::low(void){
    _blinkState = DISABLE;
    _outputState = LOW;
    digitalWrite(_outputPin, _outputState);
}

void CAR_LED::toggle(void) {
    _blinkState = DISABLE;
    _outputState = (_outputState == LOW) ? HIGH : LOW;
    digitalWrite(_outputPin, _outputState);
}

void CAR_LED::blink(unsigned int p_lowTime, unsigned int p_highTime, unsigned int p_delayTime, int p_blinkTimes) {
    _blinkStartState = _outputState;
	_highTime = p_highTime;
    _lowTime = p_lowTime;
    _delayTime = p_delayTime;
    _blinkTimes = p_blinkTimes;

	if (_blinkState != BLINK) {
		_timeSinceLastOutputChange = 0;
	}

	// No need to check what delay time is requested, as it is checked in the loop().
    if (_blinkState == DISABLE) {
        _blinkState = DELAY;
    }
}

void CAR_LED::blink(unsigned int p_lowTime, unsigned int p_highTime, unsigned int p_delayTime) {
    blink(p_lowTime, p_highTime, p_delayTime, -1);
}

void CAR_LED::blink(unsigned int p_lowTime, unsigned int p_highTime) {
    blink(p_lowTime, p_highTime, 0, -1);
}

byte CAR_LED::getState(void) {
    return _outputState;
}

void CAR_LED::loop(void) {
    bool blinkIsDue = false;
    if (_blinkTimes == 0) {
        _blinkState = DISABLE;
    }

    switch (_blinkState) {
        case DISABLE:
            return;
        case DELAY:
            if (_timeSinceLastOutputChange >= _delayTime) {
                blinkIsDue = true;
                _blinkState = BLINK;
            }
            break;
        case BLINK:
            if (_outputState == LOW && _timeSinceLastOutputChange >= _lowTime) {
                blinkIsDue = true;
            } else if (_outputState == HIGH && _timeSinceLastOutputChange >= _highTime) {
                blinkIsDue = true;
            }
            break;
        default:
            return;
    }

    if (blinkIsDue) {
        _outputState = (_outputState == LOW) ? HIGH : LOW;
        digitalWrite(_outputPin, _outputState);
        _timeSinceLastOutputChange = 0;
		// Only reduce the remaining blinktimes if the changed output is now back to the startstate.
		// This means you can start from LED HIGH or LOW, and it will blink it back to the state it was when started.
        if (_outputState == _blinkStartState && _blinkTimes > 0) {
            _blinkTimes--;
        }
    }
}
