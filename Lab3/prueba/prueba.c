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
    //volatile uint32_t ui32Loop;

    SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480), 120000000);
    //
    // Enable the GPIO port that is used for the on-board LED.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);  // habilitar el periferico GPIO del puerto N.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);  // Habilitamos el periferico GPIO del Puerto F.
    //
    // Check if the peripheral access is enabled.
    //
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))  // espera a que el puerto F este listo para usarse 
    {
    }
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION))  // esperamos a que el puerto F este listo para usarse
    {
    }

    //
    // Enable the GPIO pin for the LED (PN0).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4);  // declara el tipo de pin  
                                                         // en este caso decimos el pin PN0 va a funcionar como salida.
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0 | GPIO_PIN_1);   // de claamos el tipo de pin que vayamso a usar puede ser entrda o salida Input or Output


    // Loop forever.
    while(1)  // bucle infinto
    {
        // Turn on the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4, GPIO_PIN_0 | GPIO_PIN_4); // este comando es esto GPIOPinWrite(puerto, pin, valor);  GPIO_PIN_0: es un 1 logico y 0x0 es un cero logico
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0 | GPIO_PIN_1, GPIO_PIN_0 | GPIO_PIN_1); // cla estructura es GPIOPinWrite(puerto, pin, vslor);

        // Delay for a bit.
        /*for(ui32Loop = 0; ui32Loop < 20000000; ui32Loop++)
        {
        }   */              
       SysCtlDelay(40000000*2); // ese valor de 40000000 es 1s                                  // esta funcion de for es un delay echo a mano o manualmente

        // Turn off the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4, 0);     //Apaga el led   0x0 es el valor logico cero   
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0 | GPIO_PIN_1, 0);
        // Delay for a bit.
        /*for(ui32Loop = 0; ui32Loop < 20000000; ui32Loop++)
        {
        }*/
       SysCtlDelay(40000000*2);
    }
}



// ESTO ES EL CLOCK.
// 120 MHz = es lo mismo que 120000000Hz
// Hz es ciclos por segundo.
// entonces lo que significa es 120000000 ciclos en  1 segundo.
// ESTO ES PARA LOS SEGUNDO QUE VAMSO A USAR.
// si tenemso el clock de 12000000, queremos usar el SysCtlDelay esa funcion usa 3 ciclos para ejecutarse.
// entonces lo que debemos hacer es lo siguinte.
// algo general seria, hacer 120000000/3 = 40000000 eso nos da un equivalente a 1s.

// entonces sabiendo eso podemos suar los multipos en segundos.
/* es decir que a 40 000 000 se le puede multiplicar por los segundos que se llegue a reuqerir
  sabemos que 40000000 es 1s
    40000000*0.5 = 0.5
   *40000000 = 1s
    40000000*2 = 2s
    40000000*3 = 3s
    40000000*4 = 4s*/   