/*
 * setup.h
 *
 *  Created on: Feb 4, 2019
 *      Author: Zotti
 */
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

#ifndef SETUP_H_
#define SETUP_H_

//*****************************************************************************
// LED setup
//*****************************************************************************
void initLED();
void blinkLEDRed();
void blinkLEDGreen();
void blinkLEDBlue();

//*****************************************************************************
// ADC setup
//*****************************************************************************
void initADC14();
void clearFlag();

//*****************************************************************************
// Interrupt setup
//*****************************************************************************
void initEnable14();
void initDisable14();

#endif /* SETUP_H_ */
