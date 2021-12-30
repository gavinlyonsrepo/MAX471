/*
* Project Name: MAX471
* File: MAX471.h
* Description: Library for MAX471  header file example file
* URL: https://github.com/gavinlyonsrepo/MAX471
*/

#ifndef MAX471_H
#define MAX471_H

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif


// Voltage reference for ADC,  mV
enum VCC_REF_t
{
	VCC_BAT = 0, // ATmega328 Aref
	VCC_3_3= 3300,
	VCC_5 = 5000,
};

// ADC resolution in bits
enum ADC_RES_t
{
	ADC_8_bit =256,
	ADC_9_bit = 512,
	ADC_10_bit = 1024,
	ADC_11_bit = 2048,
	ADC_12_bit = 4096,
	ADC_14_bit = 16384,  
	ADC_16_bit = 65536  
};

// Resistor divider network on RS Vo * value
#define RS_VOLT_DIVIDE 5

// Comment this out if not using ATmega328p based Chip.
#define ATMEGA328P


// class MAX471
class MAX471 {

  public:
	 // Contructor 
	MAX471(ADC_RES_t  adc, VCC_REF_t vcc, int8_t ATreadPin, int8_t VTreadPIN);
	~MAX471(){};

	float VoltageRead() ;
	float CurrentRead() ;

  private:

	float getBatteryVolts(); 
	float  CalcResolution(void);
	
	uint16_t _VCC_TYPE ;
	uint32_t _ADC_RESOLUTION;
	int8_t _CURRENT_PIN;
	int8_t _VOLTAGE_PIN; 
};

#endif // Header Guard EOF
