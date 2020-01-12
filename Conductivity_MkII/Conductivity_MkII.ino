// MATTHEW HALPENNY - Conductivity
//Designed for CART 360 & CART 346
//Part of "Then" Assignment, Tangible Media
// Final Project for Sound Design
//December 6th, 2017
//
// Arduino code section - passes Serial1 values to Max 7 for further processing.

//pin declarations
#define FLEX_PIN_I A9
#define FLEX_PIN_M A10
#define FLEX_PIN_R A6

//included libraries
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LSM9DS0.h>
#include <Adafruit_Sensor.h>

// i2c declaration
Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0();

//int I, M, R;


void setup()
{
#ifndef ESP8266
  while (!Serial1);     // will pause Flora until Serial1 console opens *adapted from Adafruit lsm9dof test sketch
#endif
  Serial1.begin(9600);
  Serial1.println("LSM raw read demo");

  // Try to initialise and warn if we couldn't detect the chip
  if (!lsm.begin())
  {
    Serial1.println("Oops ... unable to initialize the LSM9DS0. Check your wiring!");
    while (1);
  }
  Serial1.println("Found LSM9DS0 9DOF");
  Serial1.println("");
  Serial1.println("");

  pinMode(A10, INPUT);
  pinMode(A9, INPUT);
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
  Serial1.print((int)lsm.accelData.x);
  Serial1.print(" ");
  Serial1.print((int)lsm.accelData.y);
  Serial1.print(" ");
  Serial1.print((int)lsm.accelData.z);
  Serial1.print(" ");
  Serial1.println();
  Serial1.print((int)lsm.magData.x);
  Serial1.print(" ");
  Serial1.print((int)lsm.magData.y);
  Serial1.print(" ");
  Serial1.print((int)lsm.magData.z);
  Serial1.print(" ");
   Serial1.println();
  Serial1.print((int)lsm.gyroData.x);
  Serial1.print(" ");
  Serial1.print((int)lsm.gyroData.y);
  Serial1.print(" ");
  Serial1.print((int)lsm.gyroData.z);
  Serial1.print(" ");
  Serial1.println();
  Serial1.println();

 int I = analogRead(FLEX_PIN_I);
 int M = analogRead(FLEX_PIN_M);
 int R = analogRead(FLEX_PIN_R);
  Serial1.print(I);
  Serial1.print(" ");
  Serial1.println();
   Serial1.print(M);
  Serial1.print(" ");
  Serial1.println();
   Serial1.print(R);
  Serial1.print(" ");
  Serial1.println();
  delay(50);

}
