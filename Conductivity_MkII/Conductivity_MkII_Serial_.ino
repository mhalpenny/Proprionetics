// MATTHEW HALPENNY - Conductivity
//Designed for CART 360 & CART 346
//Part of "Then" Assignment, Tangible Media
// Final Project for Sound Design
//December 6th, 2017
//
// Arduino code section - passes Serial values to Max 7 for further processing.

//pin declarations
#define FLEX_PIN_I A10
#define FLEX_PIN_M A9
#define FLEX_PIN_R A7

//included libraries
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LSM9DS0.h>
#include <Adafruit_Sensor.h>

// i2c declaration
Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0();



void setup()
{
//#ifndef ESP8266
//  while (!Serial);     // will pause Flora until Serial console opens *adapted from Adafruit lsm9dof test sketch
//#endif
  Serial.begin(9600);
  Serial.println("LSM raw read demo");

//  // Try to initialise and warn if we couldn't detect the chip
//  if (!lsm.begin())
//  {
//    Serial.println("Oops ... unable to initialize the LSM9DS0. Check your wiring!");
//    while (1);
//  }
  Serial.println("Found LSM9DS0 9DOF");
  Serial.println("");
  Serial.println("");

  pinMode(A10, INPUT);
  pinMode(A9, INPUT);
  pinMode(A6, INPUT);
  analogReference(DEFAULT); //ensure only 3.3V is being draw from microUSB power supply (for flex sensors)

}



void loop()
{
  
//  //begin reading i2c data
  lsm.read(); 
//
//
//  //print values on one line to be passed to Max
//  
 Serial.print((int)lsm.accelData.x);
  Serial.print(" ");
  Serial.print((int)lsm.accelData.y);
  Serial.print(" ");
  Serial.print((int)lsm.accelData.z);
  Serial.print(" ");
  Serial.print((int)lsm.magData.x);
  Serial.print(" ");
  Serial.print((int)lsm.magData.y);
  Serial.print(" ");
  Serial.print((int)lsm.magData.z);
  Serial.print(" ");
  Serial.print((int)lsm.gyroData.x);
  Serial.print(" ");
  Serial.print((int)lsm.gyroData.y);
  Serial.print(" ");
  Serial.print((int)lsm.gyroData.z);
  Serial.print(" ");
//  Serial.print(analogRead(FLEX_PIN_I));
//  Serial.print(" ");
//  Serial.print(analogRead(FLEX_PIN_M));
//  Serial.print(" ");
//  Serial.print(analogRead(FLEX_PIN_R));
//  Serial.println();


}
