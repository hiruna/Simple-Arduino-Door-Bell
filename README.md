# Simple Arduino Door Bell by hiruna

This is a very basic Arduino based door bell using the tone() function to generate a specific tone. My code generates a shift from 2500Hz to 1000Hz square wave and loops it three times.

### Hardware List
* 1602 Arduino Compatible LCD
* I2C LCD module (I soldered all the 'A' jumper pins)
* Arduino UNO R3 (or other arduino)
* 16mm push button
* Wires or breadboard wires
* 47ohm resistor (for the piezo buzzer)
* ~100+ ohm resistor for the push button
* 3D Printed enclosure - Model on Thingiverse: https://www.thingiverse.com/thing:2469363

### Arduino Setup

Grab your Arduino R3 (or other) and set up the I/O pins according to my schematic.

```Push Button : 5```
```Piezo Buzzer : 9```
```I2C LCD SDA : A4```
```I2C LCD SDA : A5```

##### Schematic:


![Simple-Arduino-Door-Bell-Schematic](https://raw.githubusercontent.com/hiruna/Simple-Arduino-Door-Bell/master/Schematic.png)

