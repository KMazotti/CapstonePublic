/*
 * main.c
 *
 *  Created on: Feb 4, 2019
 *      Author: Kaitlin Mazotti
 */

/* DriverLib Includes */
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/* Includes */
#include <stdint.h>
#include <stdbool.h>
#include <setup.h>

/* Statics */
static volatile uint16_t curADCResult;
static volatile double normalizedADCRes;
int k = 0;
double *p;
const volatile double *copyADC = &normalizedADCRes;
//const volatile double *place = &copyADC;

/* create an dynamic array*/
volatile double dataArray = calloc(10, sizeof(double));

int main(void)
{
    /* Halting the Watchdog  */
    MAP_WDT_A_holdTimer();

    /* Initializing Variables */
    curADCResult = 0;
    initADC14();



    while (1)
    {
        MAP_PCM_gotoLPM0();
    }

}

 //![Single Sample Result]
/* ADC Interrupt Handler. This handler is called whenever there is a conversion
 * that is finished for ADC_MEM0.
 */
void ADC14_IRQHandler(void)
{
    uint64_t status = MAP_ADC14_getEnabledInterruptStatus();
    MAP_ADC14_clearInterruptFlag(status);
    MAP_ADC14_disableInterrupt(ADC_INT0);
    MAP_Interrupt_disableInterrupt(INT_ADC14);

    if (ADC_INT0 & status)
    {
        curADCResult = MAP_ADC14_getResult(ADC_MEM0);
        normalizedADCRes = (curADCResult * 3.3) / 16384;

        MAP_ADC14_toggleConversionTrigger();
    }

    MAP_ADC14_enableInterrupt(ADC_INT0);
    MAP_Interrupt_enableInterrupt(INT_ADC14);

    for (k = 0; k < 10, k++)
        *(p + k) = normalizedADCRes;
}
