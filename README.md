

Table of contents
---------------------------

  * [Overview](#overview)
  * [Output](#output)
  * [Installation](#installation)
  * [Hardware](#hardware)
  * [Features](#features)
  * [Files](#files)
  
Overview
--------------------
* Name : Max471
* Title : Library for Max 471 current and voltage sensor for the Arduino eco-system
* Description : 

1. Current reading     0-3 A
2. Voltage reading   3-25 V
3. ATmega AVref supported. 

* Author: Gavin Lyons
* Arduino IDE: 1.8.16
* History: See Changelog in extras/doc folder
* Copyright: GNU GPL v3

Output
---------------------------------

Example file outputs data to Serial monitor.

Installation
------------------------------

The library is not yet included in the official Arduino library manger.

Install by copying folder into your Arduino IDE library folder.

[Installing Additional Arduino Libraries guide](https://www.arduino.cc/en/Guide/Libraries)

Hardware
----------------------------

![ h](https://github.com/gavinlyonsrepo/MAX471/blob/main/extras/image/max471.jpg)

Connect two ADC pins for voltage = VT &  current = AT. 
Connect Vout to PSU.
Connect Vin to circuit Device under test.

Features
-------------------------

When declaring the constructor list of possible values for ADC  resolution and Voltage reference(mV) are in keywords.txt. If user wishes to use a custom value not in this list , 
cast the custom int to the relevant enum. 

If user is using an Atmega328 and wishes to use internal battery reference  voltage.
They can pass VCC_BAT to constructor. Using this requires battery voltage for best result
see notes in function header in cpp file.  

Files
-------------------

| Src Files| Desc |
| ------ | ------ |
| ERM19264_UC1609.h | library header file  |
| ERM19264_UC1609.cpp |  library  source file  |
| MAX471_basic_usage | example file  |  
