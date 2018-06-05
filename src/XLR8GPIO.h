/*--------------------------------------------------------------------
 * Copyright 2018 Alorium Technology. All rights reserved.
 * This library gives access to arbitrary GPIO by allowing users to 
 * pass in DDR, PORT, and PIN register addresses. Several XLR8 and 
 * Hinj libraries rely on this library.
 * Written by Bryan Craker of Alorium Technology (info@aloriumtech.com)
 *
 *
 * To use this class, instantiate a class instance with the addresses 
 * of the DDR, PORT, and PIN registers for the GPIO you wish to access. 
 * Helpful address defines may be found in XLR8AddrPack files.
 *
 *   XLR8GPIOClass GPIO_D(DDRD, PORTD, PIND);
 *
 * Functions then are similar to standard Arduino IO access:
 *
 *   GPIO_D.pinMode(3, OUTPUT);
 *   GPIO_D.digitalWrite(3, HIGH);
 *   GPIO_D.pinMode(3, INPUT);
 *   int d = GPIO_D.digitalRead(3);
 *
 * Other helper functions to directly access the registers are available 
 * if the user desires them.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining 
 * a copy of this software and associated documentation files (the 
 * "Software"), to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, merge, publish, 
 * distribute, sublicense, and/or sell copies of the Software, and to 
 * permit persons to whom the Software is furnished to do so, subject to 
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *--------------------------------------------------------------------*/

#ifndef _XLR8_GPIO_H_INCLUDED
#define _XLR8_GPIO_H_INCLUDED

#include <Arduino.h>

class XLR8GPIOClass {
public:

  inline XLR8GPIOClass(uint8_t ddr, uint8_t port, uint8_t pin) {
    ddrReg  = ((volatile uint8_t *)ddr);
    portReg = ((volatile uint8_t *)port);
    pinReg  = ((volatile uint8_t *)pin);
    ddrAddr = ddr;
    portAddr = port;
    pinAddr = pin;
  }

  // Getters & Setters for direct port access
  inline void setDDR(uint8_t data) {
    *ddrReg = data;
  }
  inline void setPORT(uint8_t data) {
    *portReg = data;
  }
  inline void setPIN(uint8_t data) {
    *pinReg = data;
  }
  inline uint8_t getDDR() {
    return *ddrReg;
  }
  inline uint8_t getPORT() {
    return *portReg;
  }
  inline uint8_t getPIN() {
    return *pinReg;
  }

  inline uint8_t getDDRAddr() {
    return ddrAddr;
  }
  inline uint8_t getPORTAddr() {
    return portAddr;
  }
  inline uint8_t getPINAddr() {
    return pinAddr;
  }

  inline void pinMode(int pin, int mode) {
    if (mode == OUTPUT) {
      *ddrReg |= (1 << pin);
    }
    else if (mode == INPUT) {
      *ddrReg &= ~(1 << pin);
    }
  }

  inline void digitalWrite(int pin, int value) {
    if (value == HIGH) {
      *portReg |= (1 << pin);
    }
    else if (value == LOW) {
      *portReg &= ~(1 << pin);
    }
  }

  inline int digitalRead(int pin) {
    return B00000001 & (*pinReg >> pin);
  }

private:
  volatile uint8_t * ddrReg;
  volatile uint8_t * portReg;
  volatile uint8_t * pinReg;
  uint8_t ddrAddr;
  uint8_t portAddr;
  uint8_t pinAddr;

};

#endif

