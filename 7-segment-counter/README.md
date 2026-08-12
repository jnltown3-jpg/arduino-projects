# Arduino 7-Segment Counter

A push-button-controlled counter built with an Arduino Uno, a breadboard, and a multiplexed 4-digit 7-segment display. The project displays one digit on D1 and advances from 0 to 9 with each button press.

## Hardware demo

![Arduino 7-segment counter on a breadboard](../IMG_3121.jpeg)

![Arduino 7-segment counter display and button](../IMG_3122.jpeg)

## Features

- Counts upward from 0 through 9
- Returns to 0 after 9
- Uses a push button connected to A0 with `INPUT_PULLUP`
- Debounces the button and registers one count per press
- Displays the active digit on D1 while D2-D4 remain disabled

## Hardware

- Arduino Uno
- 4-digit 7-segment display
- Breadboard and jumper wires
- Push button
- Resistors

## Pin mapping

| Function | Arduino pin |
| --- | --- |
| Segment A | 13 |
| Segment B | 8 |
| Segment C | 4 |
| Segment D | 6 |
| Segment E | 7 |
| Segment F | 11 |
| Segment G | 3 |
| Decimal point | 5 |
| Digit D1 | 2 |
| Digit D2 | 9 |
| Digit D3 | 10 |
| Digit D4 | 12 |
| Push button | A0 |

## How it works

The button input uses the Arduino internal pull-up resistor, so a press reads as `LOW`. The sketch waits briefly to debounce the signal, increments the value once, then waits for the button to be released before it accepts another press.

## Run it

1. Open `count_upward.ino` in Arduino IDE.
2. Wire the circuit using the pin mapping above.
3. Select the Arduino board and serial port.
4. Upload the sketch and press the button to advance the displayed number.
