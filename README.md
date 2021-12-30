

Table of contents
---------------------------

  * [Overview](#overview)
  * [Installation](#installation)
  * [Hardware](#hardware)
  * [Features](#features)
  * [Files](#files)
  
Overview
--------------------
* Name : Max471
* Title : Small library for Max 471 current and voltage sensor for the Arduino eco-system
* Description : 

1. Current reading     0-3 A
2. Voltage reading   3-25 V
3. ATmega328 battery internal reference voltage supported. 

* Author: Gavin Lyons
* Arduino IDE: 1.8.16
* Copyright: GNU GPL v3


Installation
------------------------------

The library is not included in the official Arduino library manger.
Install by copying folder into your Arduino IDE library folder.

[Installing Additional Arduino Libraries guide](https://www.arduino.cc/en/Guide/Libraries)

Hardware
----------------------------

Tested with this module. 

![ h](https://github.com/gavinlyonsrepo/MAX471/blob/main/extras/image/max471.jpg)

Connect two ADC pins for voltage = VT &  current = AT. 
Connect Vout(+RS) to PSU.
Connect Vin(-RS) to circuit/device under test.


Features
------------------------
Example file outputs data to Serial monitor.
When declaring the constructor list, possible values for ADC resolution and Voltage reference(mV) are in keywords.txt. If user wishes to use a custom value not in this list , 
cast the custom int value to the relevant enum. 

If user is using an ATmega328 and wishes to use internal battery reference  voltage.
They can pass VCC_BAT to constructor. Using this requires battery voltage for best result
see notes in function header in cpp file.  If using another IC other than ATmega328p
then  comment out the define in header file to avoid compile errors.

Files
-------------------

| Src Files| Desc |
| ------ | ------ |
| MAX471.h | library header file  |
| MAX471.cpp |  library  source file  |
| MAX471_basic_usage | example file  |  
