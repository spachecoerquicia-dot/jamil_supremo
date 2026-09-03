//*****************************************************************************
//
// blinky.c - Simple example to blink the on-board LED.
//
// Copyright (c) 2013-2020 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2.2.0.295 of the EK-TM4C1294XL Firmware Package.
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

//*****************************************************************************
//
//! \addtogroup example_list
//! <h1>Blinky (blinky)</h1>
//!
//! A very simple example that blinks the on-board LED using direct register
//! access.
//
//*****************************************************************************

//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
    while(1);
}
#endif

//*****************************************************************************
//
// Blink the on-board LED.
//
//*****************************************************************************
int
main(void)
{
    int c = 0;
    //volatile uint32_t ui32Loop;
    SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480), 120000000); // Enables system clock

    
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // Enables peripheral F
    //
    // Enable the GPIO port that is used for the on-board LED.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ);


    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION))
    {
    }
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    }
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOJ))
    {
    }

    //
    // Enable the GPIO pin for the LED (PN0).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0);
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_1);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_4);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0);

    //Activacion de botones
    GPIOPinTypeGPIOInput(GPIO_PORTJ_BASE, GPIO_PIN_0|GPIO_PIN_1);
    GPIOPadConfigSet(GPIO_PORTJ_BASE,GPIO_PIN_0|GPIO_PIN_1,GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    //
    // Loop forever.
    //
    while(1)
    {
        if(GPIOPinRead(GPIO_PORTJ_BASE,GPIO_PIN_0) == 0){

            if(c < 15){
                c=c+1;
            }
            SysCtlDelay(40000000);
        }
        else if(GPIOPinRead(GPIO_PORTJ_BASE, GPIO_PIN_1) == 0){
           
            if(c>0){
                 c=c-1;
            }
            SysCtlDelay(40000000);

        } 


         
        if(c ==0){
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_1,0);
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_0,0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_4,0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,0);
            
        }else if(c == 1){
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_1,0);
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_0,0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_4,0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,GPIO_PIN_0);          
            

        }else if(c == 2){
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_1,0);
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_0,0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_PIN_4);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,0);
        }else if(c == 3){
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_1,0);
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_0,0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_PIN_4);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,GPIO_PIN_0);
        }else if(c == 4){
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_1,0);
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_0,GPIO_PIN_0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_4,0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,0);
        }else if(c == 5){
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_1,0);
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_0,GPIO_PIN_0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_4,0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,GPIO_PIN_0);
        }else if(c == 6){
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_1,0);
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_0,GPIO_PIN_0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_PIN_4);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,0);
        }else if(c == 7){
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_1,0);
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_0,GPIO_PIN_0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_PIN_4);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,GPIO_PIN_0);
        }else if(c == 8){
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_1,GPIO_PIN_1);
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_0,0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_4,0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,0);
        }else if(c == 9){
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_1,GPIO_PIN_1);
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_0,0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_4,0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,GPIO_PIN_0);
        }else if(c == 10){
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_1,GPIO_PIN_1);
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_0,0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_PIN_4);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,0);
        }else if(c == 11){
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_1,GPIO_PIN_1);
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_0,0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_PIN_4);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,GPIO_PIN_0);
        }else if(c == 12){
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_1,GPIO_PIN_1);
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_0,GPIO_PIN_0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_4,0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,0);
        }else if(c == 13){
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_1,GPIO_PIN_1);
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_0,GPIO_PIN_0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_4,0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,GPIO_PIN_0);
        }else if(c == 14){
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_1,GPIO_PIN_1);
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_0,GPIO_PIN_0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_PIN_4);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,0);
        }else if(c == 15){
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_1,GPIO_PIN_1);
            GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_0,GPIO_PIN_0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_PIN_4);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,GPIO_PIN_0);
        }

    }
}
