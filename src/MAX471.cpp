/*
* Project Name: MAX471
* File: MAX471.cpp
* Description: Library for MAX471  Source file
* URL: https://github.com/gavinlyonsrepo/MAX471
*/

#include "MAX471.h"


// Constructor for class MAX471
// Param 1 Enum ADC_RES_t , ADC resolution in bits
// Param 2 Enum VCC_REF_t , Voltage reference for ADC
// Param 3 ADC GPIO pin for current reading attach to AT on Max471
// Param 4 ADC GPIO pin for voltage reading attach to VT on Max471
MAX471  :: MAX471(ADC_RES_t  adc, VCC_REF_t vcc, int8_t ATreadPin, int8_t VTreadPIN) 
{
	 _ADC_RESOLUTION= adc;
	 _VCC_TYPE = vcc;
	 _CURRENT_PIN = ATreadPin;
	_VOLTAGE_PIN = VTreadPIN; 

}

//Func Desc:
// Reads current on ADC pin 
// Returns Float with value of current in Amps 0  to  +/- 3
float MAX471::CurrentRead()
{
	uint16_t  ATread  = analogRead(_CURRENT_PIN);
	return (ATread * CalcResolution());
} 


// Func Desc:
// Reads current on ADC pin 
// Returns Float with value of Voltage in Volts 3  to  25
float MAX471::VoltageRead() 
{ 
	uint16_t VTread = analogRead(_VOLTAGE_PIN);
	return ((VTread * CalcResolution()) * RS_VOLT_DIVIDE);
} 

// Func Desc:
// Calculates the resolution  pre volt Vcc ref/ADC resolution
// returns float with ADC per volt . 
// e.g. 5/1024 = .0048828
float  MAX471::CalcResolution(void)
{
	
	float resolution = 0.0;
	if (_VCC_TYPE == VCC_BAT)
	{
		resolution  = getBatteryVolts() / _ADC_RESOLUTION;
	}else
	{
		resolution  = (((float)_VCC_TYPE/1000) / _ADC_RESOLUTION);
	}

	return resolution;
}

/* Func Desc: Get Vcc of  ATMega328p
  Param 1: returns float with Vcc i.e 5.04
  notes: You MUST measure the voltage at pin 21 (AREF) using just a simple one line sketch consisting
  of:  analogReference(INTERNAL) analogRead(A0)
  See: https://github.com/RalphBacon/Arduino-Battery-Monitor
  Then use the measured value here. at  const float InternalReferenceVoltage
  Normally this is 1.10 volts in theory.
*/

#ifdef ATMEGA328P
float MAX471::getBatteryVolts() {


  const float InternalReferenceVoltage = 1.088; // <- as measured (or 1v1 by default)
  // turn ADC on
  ADCSRA =  bit (ADEN);
  // Prescaler of 128
  ADCSRA |= bit (ADPS0) |  bit (ADPS1) | bit (ADPS2);
  // MUX3 MUX2 MUX1 MUX0  --> 1110 1.1V (VBG) - Selects channel 14, bandgap voltage, to measure
  ADMUX = bit (REFS0) | bit (MUX3) | bit (MUX2) | bit (MUX1);
  // let it stabilize
  delay (50);
  // start a conversion
  bitSet (ADCSRA, ADSC);
  // Wait for the conversion to finish
  while (bit_is_set(ADCSRA, ADSC))
  {
    ;
  }
  // Float normally reduces precion but works OK here. Add 0.5 for rounding not truncating.
  float results = InternalReferenceVoltage / float (ADC + 0.5) * 1024.0;
  return results;
}
#else
float MAX471::getBatteryVolts() 
{
	//Other MCU non ATmega328p code can go here,
	return 0;
}
#endif
//***********************************************
