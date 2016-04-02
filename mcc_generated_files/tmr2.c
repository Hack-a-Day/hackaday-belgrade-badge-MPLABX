/**
  TMR2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr2.c

  @Summary
    This is the generated driver implementation file for the TMR2 driver using MPLAB� Code Configurator

  @Description
    This source file provides APIs for TMR2.
    Generation Information :
        Product Revision  :  MPLAB� Code Configurator - v2.25.2
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

/**
  Section: Included Files
 */

#include <xc.h>
#include "tmr2.h"
#include "../HaD_Badge.h"

const uint8_t ShiftSeq[] = {10, 13, 15, 14, 12, 1, 3, 0, 4, 6, 7, 5, 2, 9, 11, 8}; // order

/**
  Section: TMR2 APIs
 */

void TMR2_Initialize(void) {
    // Set TMR2 to the options selected in the User Interface

    // TMR2ON off; T2OUTPS 1:8; T2CKPS 1:16; 
    T2CON = 0x0A;

    // PR2 255; 
    PR2 = 0x80;

    // TMR2 0x0; 
    TMR2 = 0x00;

    // Clearing IF flag before enabling the interrupt.
    PIR1bits.TMR2IF = 0;

    // Enabling TMR2 interrupt.
    PIE1bits.TMR2IE = 1;

    // Start TMR2
    TMR2_StartTimer();
}

void TMR2_StartTimer(void) {
    // Start the Timer by writing to TMRxON bit
    T2CONbits.TMR2ON = 1;
}

void TMR2_StopTimer(void) {
    // Stop the Timer by writing to TMRxON bit
    T2CONbits.TMR2ON = 0;
}

uint8_t TMR2_ReadTimer(void) {
    uint8_t readVal;

    readVal = TMR2;

    return readVal;
}

void TMR2_WriteTimer(uint8_t timerVal) {
    // Write to the Timer2 register
    TMR2 = timerVal;
}

void TMR2_LoadPeriodRegister(uint8_t periodVal) {
    PR2 = periodVal;
}

void TMR2_ISR(void) {

    // clear the TMR2 interrupt flag
    PIR1bits.TMR2IF = 0;


    static uint8_t BitMask = 0b10000000;

    Anode0off();
    Anode1off();
    Anode2off();
    Anode3off();
    Anode4off();
    Anode5off();
    Anode6off();
    Anode7off();

    LatchLow();
    for (uint8_t i=0; i<16; i++) {
        if (Buffer[ShiftSeq[i]] & BitMask) { DataHigh(); }
        else { DataLow(); }


        ClkHigh();
        ClkLow();
    }

    LatchHigh();
    switch (BitMask) {
        case(0b10000000):
            Anode0on();
            break;
        case(0b01000000):
            Anode1on();
            break;
        case(0b00100000):
            Anode2on();
            break;
        case(0b00010000):
            Anode3on();
            break;
        case(0b00001000):
            Anode4on();
            break;
        case(0b00000100):
            Anode5on();
            break;
        case(0b00000010):
            Anode6on();
            break;
        case(0b00000001):
            Anode7on();
            break;
    }

    BitMask >>= 1;
    if (BitMask == 0) {
        /* This will trigger a at about 100Hz; use for debounce and timing */
        
        //Get scanning ready for next pass
        BitMask = 0b10000000;
        
        //Increment universal timer
        ticks += 10; // Roughly 10ms has passed. This is close enough
        
        
        //Button Debounce (https://github.com/szczys/Button-Debounce)
        static unsigned char ct0, ct1, rpt;
        unsigned char i;
        
        i = key_state ^ ~KEY_PIN;    // key changed ?
        ct0 = ~( ct0 & i );          // reset or count ct0
        ct1 = ct0 ^ (ct1 & i);       // reset or count ct1
        i &= ct0 & ct1;              // count until roll over ?
        key_state ^= i;              // then toggle debounced state
        key_press |= key_state & i;  // 0->1: key press detect

        if( (key_state & REPEAT_MASK) == 0 )   // check repeat function 
         rpt = REPEAT_START;      // start delay 
        if( --rpt == 0 ){ 
            rpt = REPEAT_NEXT;         // repeat delay 
            key_rpt |= key_state & REPEAT_MASK; 
        }
         
    }
}

/**
  End of File
 */