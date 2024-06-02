
# CAR_LED Library Documentation

## Overview

The `CAR_LED` library simplifies working with LED outputs on Arduino. It provides functionality for setting high/low states, toggling, and blinking with customizable timings.

## Installation

To use the `CAR_LED` library, include it in your project by copying the `CAR_LED.h` and `CAR_LED.cpp` files into your project's directory and include the header file in your sketch.

```cpp
#include "CAR_LED.h"
```

## Enumerations

The `CAR_LED_BlinkState` enum defines the possible states for output blinking:

- `DISABLE`: Blinking is disabled.
- `DELAY`: Delay before starting the blink.
- `BLINK`: Blinking is active.

## Class: `CAR_LED`

### Constructor

```cpp
CAR_LED(byte p_outputPin);
```

- `p_outputPin`: The pin number to which the LED is attached.

### Methods

#### `void high(void)`

Sets the output to high.

#### `void low(void)`

Sets the output to low.

#### `void toggle(void)`

Toggles the output state.

#### `void blink(unsigned int p_lowTime, unsigned int p_highTime)`

Starts blinking with the specified low and high times.

- `p_lowTime`: Time in milliseconds the output stays low.
- `p_highTime`: Time in milliseconds the output stays high.

#### `void blink(unsigned int p_lowTime, unsigned int p_highTime, unsigned int p_delayTime)`

Starts blinking with the specified low, high, and delay times.

- `p_lowTime`: Time in milliseconds the output stays low.
- `p_highTime`: Time in milliseconds the output stays high.
- `p_delayTime`: Delay time in milliseconds before starting the blink.

#### `void blink(unsigned int p_lowTime, unsigned int p_highTime, unsigned int p_delayTime, int p_blinkTimes)`

Starts blinking with the specified low, high, delay times, and number of blink cycles.

- `p_lowTime`: Time in milliseconds the output stays low.
- `p_highTime`: Time in milliseconds the output stays high.
- `p_delayTime`: Delay time in milliseconds before starting the blink.
- `p_blinkTimes`: Number of blink cycles. If set to -1, blinking continues indefinitely.

#### `byte getState(void)`

Returns the current output state.

#### `void loop(void)`

Handles the output state and manages blinking. This method should be called repeatedly in the `loop()` function of your sketch.

## Usage Examples

### Example 1: Basic High and Low Output

```cpp
#include <CAR_LED.h>

CAR_LED output(13);

void setup() {
    Serial.begin(9600);
}

void loop() {
    output.high();
    delay(1000);
    output.low();
    delay(1000);
}
```

### Example 2: Toggle Output

```cpp
#include <CAR_LED.h>

CAR_LED output(13);

void setup() {
    Serial.begin(9600);
}

void loop() {
    output.toggle();
    delay(500);
}
```

### Example 3: Simple Blinking

```cpp
#include <CAR_LED.h>

CAR_LED output(13);

void setup() {
    Serial.begin(9600);
    output.blink(500, 500);
}

void loop() {
    output.loop();
}
```

### Example 4: Blinking with Delay

```cpp
#include <CAR_LED.h>

CAR_LED output(13);

void setup() {
    Serial.begin(9600);
    output.blink(500, 500, 2000);
}

void loop() {
    output.loop();
}
```

### Example 5: Blinking with Limited Cycles

```cpp
#include <CAR_LED.h>

CAR_LED output(13);

void setup() {
    Serial.begin(9600);
    output.blink(500, 500, 0, 10);
}

void loop() {
    output.loop();
}
```
