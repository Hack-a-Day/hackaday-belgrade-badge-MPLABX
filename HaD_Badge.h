/**
  @Generated MPLAB® Code Configurator Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    HaD_Badge.h

  @Summary:
    This is the header file with defines and globals for HaD european sueprconference 2016 badge

  
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

#include <stdint.h>

volatile uint8_t Flag       @ 0x00;     //Flag 0 = set by kernel : Pause, clr by kernel : Run mode(read only)
volatile uint8_t RXFlag     @ 0x01;     //RXFlag 0 = set : Enable auto RX to RAM 0x600...0x6FF and to EEprom
volatile uint8_t KeyEdge    @ 0x02;     //KeyEdge 0 = set by kernel; //if key INT edge detected(user must reset)
volatile uint8_t Brightness @ 0x03;     //Brightness Display ON PWM, user presets to 0...15 for dimming
volatile uint8_t GPreg      @ 0x04;     //GPreg General purpose register, may be used by user
volatile uint8_t BitMask    @ 0x05;     //BitMask 10000000...00000001, shift reg(CA) or 0...7 row count(CC)
volatile uint8_t BitMask2   @ 0x06;     //BitMask2 11111110...01111111, shift reg used for anode scan
volatile uint8_t T0period   @ 0x07;     //T0period Total Timer 0 period, may be modified to alter scan frequency
volatile uint8_t Rotor0     @ 0x08;     //Rotor0 Used for key INT debouncer(bit 0 = 0 if key pressed)
volatile uint8_t Rotor1     @ 0x09;     //Rotor1 Used for key LEFT debouncer(bit 0 = 0 if key pressed)
volatile uint8_t Rotor2     @ 0x0A;     //Rotor2 Used for key UP debouncer(bit 0 = 0 if key pressed)
volatile uint8_t Rotor3     @ 0x0B;     //Rotor3 Used for key DOWN debouncer(bit 0 = 0 if key pressed)
volatile uint8_t Rotor4     @ 0x0C;     //Rotor4 Used for key RIGHT debouncer(bit 0 = 0 if key pressed)
volatile uint8_t InnerInt   @ 0x0D;     //InnerInt Loop counter, used by interrupt routine
volatile uint8_t OuterInt   @ 0x0E;     //OuterInt Loop counter, used by interrupt routine
volatile uint8_t OuterPlusInt @ 0x0F;   //OuterPlusInt Loop counter, used by interrupt routine
volatile uint8_t RXptr      @ 0x10;     //RXptr Low RXD buffer pointer(high is always = 6)
volatile uint8_t Received   @ 0x11;     //Received Received charracters counter, 0...255, used in Interrupt service
volatile uint8_t RXpatience @ 0x12;     //RXpatience Patience counter, preset when byte received, count down
volatile uint8_t PowerOFF   @ 0x13;     //PowerOFF Auto Power Off period(×6 sec), preset here to alter timing
volatile uint8_t PowerCount @ 0x14;     //PowerCount Auto Power Off count down
volatile uint16_t Uniform   @ 0x15;     //Uniform(2 bytes) 150 Hz divider, count up for 6 sec timing
volatile uint16_t RXserial  @ 0x17;     //RXserial(2 bytes) Received serial number(binary), ready for comparison
volatile uint16_t MySerial  @ 0x19;     //MySerial(2 bytes) unit serial number copied from ROM address 0x100E
volatile uint16_t FSR0temp  @ 0x1B;     //FSR0temp(2 bytes) Temporary FSR0 during INT
//0x1D...0x5FF User data RAM space
volatile uint8_t RXBuffer[256]  @ 0x600;//0x600...0x6FF RX Buffer, used by infrared port routine(bytes loaded here)
volatile uint8_t Buffer[16]     @ 0x700;//0x700...0x70F Display buffer, upper row first, bit 7 = left column(user writes here)
volatile uint8_t AuxBuffer[16]  @ 0x710;//0x710...0x71F Aux buffer(not displayed by interrupt display refresh, used by user)
volatile uint8_t Pause[16]      @ 0x720;//0x720...0x72F Pause display buffer(displayed only during pause)
volatile uint32_t RNDseed   @ 0x720;    //0x730...0x733 RND seed *
volatile uint32_t RND       @ 0x734;    //0x734...0x737 RND internal arithmetic registers

#define TOTPIXELX       8
#define TOTPIXELY       16

//LED Control definitions
#define OFF     0x00
#define ON      0x0F

//Directions of travel
#define UP      0
#define DOWN    1
#define LEFT    2
#define RIGHT   3
//Miscellaneous
#define ESCAPE  4
#define NOINPUT 5
#define BUTTON  6
