/*
 * setup.c
 *
 *  Created on: Feb 8, 2019
 *      Author: Kaitlin Mazotti
 */

#include "setup.h"
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

//*****************************************************************************
// LED setup
//*****************************************************************************
void initLED(){
    // Set P1.0 to output direction
    // Red P2.0
    // Green P2.1
    // Blue P2.2
    GPIO_setAsOutputPin(GPIO_PORT_P2,
                        GPIO_PIN0
                        | GPIO_PIN1
                        | GPIO_PIN2);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2,
                        GPIO_PIN0
                        | GPIO_PIN1
                        | GPIO_PIN2);
}

void blinkLEDRed(){
    // Toggle P1.0 output
    GPIO_toggleOutputOnPin(
        GPIO_PORT_P2,
        GPIO_PIN0
        );
}

void blinkLEDGreen(){
    // Toggle P1.0 output
    GPIO_toggleOutputOnPin(
        GPIO_PORT_P2,
        GPIO_PIN1
        );
}

void blinkLEDBlue(){
    // Toggle P1.0 output
    GPIO_toggleOutputOnPin(
        GPIO_PORT_P2,
        GPIO_PIN2
        );
}

//*****************************************************************************
// ADC initialization
//*****************************************************************************
void initADC14(){
        /* Setting Flash wait state */
       MAP_FlashCtl_setWaitState(FLASH_BANK0, 1);
       MAP_FlashCtl_setWaitState(FLASH_BANK1, 1);

       /* Setting DCO to 48MHz  */
       MAP_PCM_setPowerState(PCM_AM_LDO_VCORE1);
       MAP_CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_48);

       /* Enabling the FPU for floating point operation */
       MAP_FPU_enableModule();
       MAP_FPU_enableLazyStacking();

       //![Single Sample Mode Configure]
       /* Initializing ADC (MCLK/1/4) */
       MAP_ADC14_enableModule();
       MAP_ADC14_initModule(ADC_CLOCKSOURCE_MCLK, ADC_PREDIVIDER_1, ADC_DIVIDER_1,
               0);

       /* Configuring GPIOs (5.5 A0) */
       MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P5, GPIO_PIN5,
       GPIO_TERTIARY_MODULE_FUNCTION);

       /* Configuring ADC Memory */
       MAP_ADC14_configureSingleSampleMode(ADC_MEM0, true);
       MAP_ADC14_configureConversionMemory(ADC_MEM0, ADC_VREFPOS_AVCC_VREFNEG_VSS,
       ADC_INPUT_A0, false);

       /* Configuring Sample Timer */
       MAP_ADC14_enableSampleTimer(ADC_MANUAL_ITERATION);

       /* Enabling/Toggling Conversion */
       MAP_ADC14_enableConversion();
       MAP_ADC14_toggleConversionTrigger();
       //![Single Sample Mode Configure]

       /* Enabling interrupts */
       MAP_ADC14_enableInterrupt(ADC_INT0);
       MAP_Interrupt_enableInterrupt(INT_ADC14);
       MAP_Interrupt_enableMaster();

}
