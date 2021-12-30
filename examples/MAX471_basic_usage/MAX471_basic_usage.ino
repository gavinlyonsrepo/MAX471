/*
* Project Name: MAX471
* File: MAX471.ino
* Description: Library for MAX471  ino example file
* Tested : on UNO / NAN0 ATmeag328
* URL: https://github.com/gavinlyonsrepo/MAX471
*/

//******************** LIBRARIES ******************
#include "MAX471.h"

//******************** GLOBALS + DEFINES **********
// Max471 test parameters
#define TEST_DELAY delay(2000);
#define VT_PIN A0
#define AT_PIN A1

// 1. Vref = calibrated battery voltage ATmega328p
MAX471 myMax471(ADC_10_bit , VCC_BAT, AT_PIN, VT_PIN); 

// 2. Custom ADC + Vcc ref
//MAX471 myMax471( ( ADC_RES_t)8192 , (VCC_REF_t)4000, AT_PIN, VT_PIN); 

// 3. VAref = 5 volt Vcc
//MAX471 myMax471(ADC_10_bit , VCC_5, AT_PIN, VT_PIN); 

// 4. 12 bit ADc and 3.3 V 
//MAX471 myMax471(ADC_12_bit , VCC_3_3, AT_PIN, VT_PIN); 

//******************** SETUP *********************
void setup() {
  Serial.begin(38400);
  Serial.println("== START LIBRARY TEST ==");
}

//******************* MAIN LOOP *****************

void loop() {

  // Test 1 Read Amps and Volts 
  Serial.print("A: ");
  Serial.println(myMax471.CurrentRead(), 3);
  Serial.print("V: ");
  Serial.println(myMax471.VoltageRead(), 3);
  Serial.println();
  TEST_DELAY

  // Test 2 Read mA and mV
  Serial.print("mA: ");
  Serial.println(myMax471.CurrentRead() * 1000, 1);
  Serial.print("mV: ");
  Serial.println(myMax471.VoltageRead() * 1000, 1);
  Serial.println();
  TEST_DELAY

} // End of main

//******************* EOF *****************
