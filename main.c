/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB® Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.25.2
        Device            :  PIC18F24K50
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB             :  MPLAB X v2.35 or v3.00
 */

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

#include "mcc_generated_files/mcc.h"
#include "HaD_Badge.h"
//#include "bh-badge-animate.h"

uint8_t KeyUpPress;
uint8_t KeyMiddlePress;
uint8_t KeyLeftPress;
uint8_t KeyRightPress;

//uint8_t Buffer[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

//Turn on display and set all LEDs off
void initDisplay(void) {
    // Turn on peripherals

}

//Turn all LEDs off
void displayClear(void) {
    for (uint8_t i=0; i<16; i++) {
        Buffer[i] = 0x00;
    }
}

//Set LED to state (ON|OFF)
void displayPixel(uint8_t x, uint8_t y, uint8_t state) {
    if (state == ON) {
        Buffer[y] |= 1<<(7-x);
    }
    else {
        Buffer[y] &= ~(1<<(7-x));
    }
}

//Close the display (used for SDL2 emulator window)
void displayClose(void) {    
    //Not implemented for hardware but kept for portability
}

//Make display changes visible (can be used for a framebuffer)
void displayLatch(void) {
    //Not implemented for hardware but kept for portability
}

//Setup button input
void initControl(void) {
    
}

//Return last pressed button
uint8_t getControl(void) {
    //return key_mask;
    /*
    if (key_mask & 1<<KEY0) { return LEFT; }
    if (key_mask & 1<<KEY1) { return RIGHT; }
    if (key_mask & 1<<KEY2) { return UP; }
    if (key_mask & 1<<KEY3) { return DOWN; }
    */
    return 0;
}

//Initialize timekeeping hardware
void initTime(void) {
    //ticks = 0;
}

//Return milliseconds (upcounting)
uint32_t getTime(void) {
    //We're adding 10 to this value every in timr2_1.c
    //every 8th interrupt (~100Hz)
    /*
    return ticks;
     */
}

//Delay milliseconds (blocking)
void controlDelayMs(uint16_t ms) {
    ms = ms/10;
    while (ms > 0) {
        __delay_ms(10);
        --ms;
    }
}

void POST(void) {
    //Test all anode drivers
    /*
    LEDtestlat &= ~LEDtestbit;  //Sink to test LEDs
    Anode0on();
    controlDelayMs(500);
    Anode0off();
    Anode1on();
    controlDelayMs(500);
    Anode1off();
    Anode2on();
    controlDelayMs(500);
    Anode2off();
    Anode3on();
    controlDelayMs(500);
    Anode3off();
    Anode4on();
    controlDelayMs(500);
    Anode4off();
    Anode5on();
    controlDelayMs(500);
    Anode5off();
    Anode6on();
    controlDelayMs(500);
    Anode6off();
    Anode7on();
    controlDelayMs(500);
    Anode7off();
    LEDtestlat |= LEDtestbit;
    */
    //End Anode driver test
    
    //Fill buffer, will be displayed when POST exits
    for (uint8_t i=0; i<16; i++) {
        Buffer[i] = 0xFF;
    }
}
/*
                         Main application
 */
void main(void) {
    // Initialize the device
    SYSTEM_Initialize();
    
    initDisplay();
    initTime();
    
    
    //Self test
    POST();
    
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    // INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    // INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    //animateBadge();
    
    while (1) {
                // Add your application code
    }
}
/**
 End of File
 */