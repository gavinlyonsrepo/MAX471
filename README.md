

Table of contents
---------------------------

  * [Overview](#overview)
  * [Installation](#installation)
  * [Hardware](#hardware)
  * [Software](#software)
 
  
Overview
--------------------
* Name : MAX471
* Description : 

Small library for the MAX471 current and voltage sensor for the Arduino eco-system

1. Current range     0-3 A
2. Voltage range   3-25 V
3. ATmega328 battery internal reference voltage supported. 

* Author: Gavin Lyons
* Arduino IDE: 1.8.16 
* Copyright: GNU GPL v3

Installation
------------------------------

The library is included in the official Arduino library manger and the optimum way to install it 
is using the library manager which can be opened by the *manage libraries* option in Arduino IDE. 
Search "MAX471" in search bar of library manager to find it.

See link below for instruction for this and for the other methods too.

[Installing Additional Arduino Libraries guide](https://www.arduino.cc/en/Guide/Libraries)

Hardware
----------------------------

Tested with this module pictured. There is a  few different designs of this module some with less connections and circuitry and you can also purchase the barebones MAX471 chip.
Some of these modules don't have some or all of these components just breakout  connectors so user must add them. 
The resistor divider network on board divides Vout to VT, it divides voltage reading by 0.2.
So we multiply by 5 in software to "restore" value. This ratio is defined by RS_VOLT_DIVIDE define
in header file.  If using different resistor values this will have to be  adjusted.

1. VT =  (R2/(R2+R1)) * Vout 
2. VT = (7.5K/37.5)* Vout 
3. VT = 0.2*Vout
3. VT*5 = Vout

The other resistor(2K) and a capacitor are on current signal line (AT)
for transient suppression. 

There is a full schematic and example of this module and library in a project here at 
[LINK](https://github.com/gavinlyonsrepo/MAX471_PVI_METER)

![ h](https://github.com/gavinlyonsrepo/MAX471/blob/main/extras/image/max471.jpg)

1. Connect two ADC pins for voltage = VT &  current = AT. 
2. Connect Vout(+RS) to external PSU to drive load.
3. Connect Vin(-RS) to load/circuit/device under test.

Software
------------------------
Example file outputs data to Serial monitor.
When declaring the constructor list, possible values for ADC resolution and Voltage reference(mV) are in keywords.txt. If user wishes to use a custom value not in this list , 
cast the custom int value to the relevant enum. 

If user is using an ATmega328 and wishes to use internal battery reference  voltage.
They can pass VCC_BAT to constructor. Using this requires battery voltage for best result
see notes in function header in cpp file.  If using another IC other than ATmega328p
then  comment out the define in header file to avoid compile errors.

*Files*

| Src Files| Desc |
| ------ | ------ |
| MAX471.h | library header file  |
| MAX471.cpp |  library  source file  |
| MAX471_basic_usage | example file  |  
