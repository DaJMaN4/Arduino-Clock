Arduino Clock V1

This document describes how my Arduino clock V1 works

# Features:

Measuring temperature and humidity.

DHT-11 is a module that I used on the clock, it can sense temperature and humidity of environment with accuracy of 5% with humidity and up to +-2C with temperature which are bad parameters but for this usage its ok because it’s completely for fun.

the one I used, has a circuit board on it, connections look like this:

Current time:

With help of Real Time Clock Module, the device can know what time it is. Disadvantage of this model that I used is that it’s not accurate and it misses around 5 minutes every 24h, so it’s not something that is useful because it often requires calibration, it might be also because that this module came from a Chinas supplier on AliExpress, and it may be fake. That’s why for my new clock I ordered a better version, I recommend using newer clock modules, because of the possibility of being bad and newer versions use I2C for communication, with this protocol you safe 3 pins on your Arduino which can be used for something else.

Stopper:

Stopper is the third and last option on this clock, it’s basically a normal stopper, I program that on Arduino so there is no module for that.

## Parts I used:

| Amount | Name                            | Technical name                        |
|--------|---------------------------------|---------------------------------------|
| 1      | Arduino Uno                     | Arduino Uno                           |
| 3      | Buttons                         | Normal N0 pushbuttons for breadboards |
| 1      | LCD display                     | 1602A                                 |
| 1      | LCD driver module               | PCF8574 i2c Driver Module             |
| 1      | Side switch                     | I do not possess data                 |
| 3      | Resistors                       | 100kOhm resistors                     |
| 1      | 9V rechargeable battery         | HR 6F22                               |
| 1      | Clock module                    | MH-Real-Time Clock Modules-2          |
| 1      | X4 Seven segment display        | 5641AS                                |
| 1      | Breadboard                      | MB102                                 |
| 1      | Humility and temperature sensor | DHT-11                                |

# System

To turn on the clock the switch the side switched. When it has been turned on. Screen will show text “Select Mode”

Two buttons on left and right are used for maneuvering over options, the one in the middle is for choosing options and interacting with them.

## Options:

-   One is called temperature, when you click on it you will get a screen that shows current temperature and humidity
-   Second is current time, it shows on the 7-segment display
-   Third is stopper, after you choose this mode, the stopper will start to run, and it will stop as fast as you click the button in the middle again.

    Any additional options can be added relatively easily because the code is written in a way that can support large amounts of options.

The main inspiration was a meme that I found on internet. I found it hilarious, and it inspired me to make my own version of device visible on the meme, you can see it in folder Photos, it is called “inspiration”.
