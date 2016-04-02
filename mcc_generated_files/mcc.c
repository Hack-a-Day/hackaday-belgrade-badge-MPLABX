/**
  @Generated MPLAB� Code Configurator Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    mcc.c

  @Summary:
    This is the mcc.c file generated using MPLAB� Code Configurator

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB� Code Configurator - v2.25.2
        Device            :  PIC18F24K50
        Driver Version    :  1.02
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

// Configuration bits: selected in the GUI

// CONFIG1L

#pragma config CFGPLLEN = OFF    // PLL Enable Configuration bit->PLL Disabled (firmware controlled)
#pragma config LS48MHZ = SYS24X4    // Low Speed USB mode with 48 MHz system clock->System clock at 24 MHz, USB clock divider is set to 4
#pragma config CPUDIV = NOCLKDIV    // CPU System Clock Postscaler->CPU uses system clock (no divide)
#pragma config PLLSEL = PLL4X    // PLL Selection->4x clock multiplier

// CONFIG1H
#pragma config FCMEN = OFF    // Fail-Safe Clock Monitor->Fail-Safe Clock Monitor disabled
#pragma config FOSC = INTOSCIO    // Oscillator Selection->Internal oscillator
#pragma config IESO = OFF    // Internal/External Oscillator Switchover->Oscillator Switchover mode disabled
#pragma config PCLKEN = ON    // Primary Oscillator Shutdown->Primary oscillator enabled

// CONFIG2L
#pragma config nPWRTEN = OFF    // Power-up Timer Enable->Power up timer disabled
#pragma config BOREN = SBORDIS    // Brown-out Reset Enable->BOR enabled in hardware (SBOREN is ignored)
#pragma config nLPBOR = OFF    // Low-Power Brown-out Reset->Low-Power Brown-out Reset disabled
#pragma config BORV = 190    // Brown-out Reset Voltage->BOR set to 1.9V nominal

// CONFIG2H
#pragma config WDTPS = 32768    // Watchdog Timer Postscaler->1:32768
#pragma config WDTEN = OFF    // Watchdog Timer Enable bits->WDT disabled in hardware (SWDTEN ignored)

// CONFIG3H
#pragma config CCP2MX = RC1    // CCP2 MUX bit->CCP2 input/output is multiplexed with RC1
#pragma config MCLRE = ON    // Master Clear Reset Pin Enable->MCLR pin enabled; RE3 input disabled
#pragma config T3CMX = RC0    // Timer3 Clock Input MUX bit->T3CKI function is on RC0
#pragma config SDOMX = RB3    // SDO Output MUX bit->SDO function is on RB3
#pragma config PBADEN = ON    // PORTB A/D Enable bit->PORTB<5:0> pins are configured as analog input channels on Reset

// CONFIG4L
#pragma config XINST = OFF    // Extended Instruction Set Enable bit->Instruction set extension and Indexed Addressing mode disabled
#pragma config LVP = OFF    // Single-Supply ICSP Enable bit->Single-Supply ICSP disabled
#pragma config STVREN = ON    // Stack Full/Underflow Reset->Stack full/underflow will cause Reset
#pragma config ICPRT = OFF    // Dedicated In-Circuit Debug/Programming Port Enable->ICPORT disabled
#pragma config DEBUG = OFF    // Background Debugger Enable bit->Background debugger disabled, RB6 and RB7 configured as general purpose I/O pins

// CONFIG5L
#pragma config CP0 = OFF    // Block 0 Code Protect->Block 0 is not code-protected
#pragma config CP1 = OFF    // Block 1 Code Protect->Block 1 is not code-protected

// CONFIG5H
#pragma config CPB = OFF    // Boot Block Code Protect->Boot block is not code-protected
#pragma config CPD = OFF    // Data EEPROM Code Protect->Data EEPROM is not code-protected

// CONFIG6L
#pragma config WRT1 = OFF    // Block 1 Write Protect->Block 1 (2000-3FFFh) is not write-protected
#pragma config WRT0 = OFF    // Block 0 Write Protect->Block 0 (0800-1FFFh) is not write-protected

// CONFIG6H
#pragma config WRTB = OFF    // Boot Block Write Protect->Boot block (0000-7FFh) is not write-protected
#pragma config WRTC = OFF    // Configuration Registers Write Protect->Configuration registers (300000-3000FFh) are not write-protected
#pragma config WRTD = OFF    // Data EEPROM Write Protect->Data EEPROM is not write-protected

// CONFIG7L
#pragma config EBTR1 = OFF    // Block 1 Table Read Protect->Block 1 is not protected from table reads executed in other blocks
#pragma config EBTR0 = OFF    // Block 0 Table Read Protect->Block 0 is not protected from table reads executed in other blocks

// CONFIG7H
#pragma config EBTRB = OFF    // Boot Block Table Read Protect->Boot block is not protected from table reads executed in other blocks

#include "mcc.h"



void SYSTEM_Initialize(void) {
    /*
    OSCILLATOR_Initialize();
    PIN_MANAGER_Initialize();
    */
}

void OSCILLATOR_Initialize(void) {
    /*
    // SCS INTOSC; IDLEN disabled; IRCF 16MHz; 
    OSCCON = 0x72;
    // INTSRC INTRC_31_25KHz; PLLEN enabled; PRISD disabled; SOSCGO disabled; 
    OSCCON2 = 0x10;
    // SPLLMULT 4xPLL; TUN 0x0; 
    OSCTUNE = 0x00;
    // Set the secondary oscillator
    */
}

/**
 End of File
 */