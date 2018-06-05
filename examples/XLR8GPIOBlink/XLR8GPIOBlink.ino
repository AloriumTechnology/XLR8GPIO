/*
  XLR8GPIOBlink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, XLR8, or Hinj 
  it is attached to digital pin 13.

  This code demonstrates how to access GPIO pins defined by a DDR, PORT, and PIN
  register. The XLR8GPIO class is instantiated of the builtin GPIO pins of 
  Port B. The address of the control registers are passed to the class, then 
  the GPIO instance is used to control the onboard LED.
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman

  modified 8 Feb 2018
  by Bryan Craker of Alorium Technology (info@aloriumtech.com)

*/

#include <XLR8GPIO.h>

XLR8GPIOClass bankB(0x24, 0x25, 0x23);

#define LED_PIN 5

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  bankB.pinMode(LED_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  bankB.digitalWrite(LED_PIN, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  bankB.digitalWrite(LED_PIN, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}

