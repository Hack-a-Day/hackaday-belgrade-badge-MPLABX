/* 
 * File:   main.c
 * Author: mike
 *
 * Created on April 2, 2016, 1:05 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "HaD_Badge.h"
#include "bh-badge-animate.h"

volatile uint16_t innerTick = 0;
volatile uint32_t ticks = 0;

/*****Begin Kernel Compliance Section: Do not edit this code*******************/
void fakeHighVect(void) @ 0x1800 { interrupt_at_high_vector(); }
void fakeLowVect(void) @ 0x1806 { interrupt_at_low_vector(); }

void initBootloaderInterruptHandling(void) {
    /***************************
     * These two functions connect the bootloader/kernel interrupt vector
     * handling to this C code. This is a hack. The only way I could figure
     * out to get the high and low interrupt vectors to be at the exact
     * addresses specified by the bootloader (0x1800 and 0x1806) was to place
     * functions at those address. You must call those functions at least once
     * or the compiler will not pull them in. That is the only purpose of this 
     * init function.
     *****************************/
    fakeHighVect();
    fakeLowVect();
}

void interrupt_at_high_vector(void)
{
    //NOTE: Timer0 and Timer2 are in use by the bootloader/kernel
    
    /***** User Code for high priority interrupts *****/
    if (TMR1IF) {
        //Use Timer1 to generate ~1ms tick for getTime() function
        TMR1 = 0xFA24;  //Prewind for 1 ms overflow (0xFFFF-(48MHz/4/8/1000)+1)
        ++ticks;        //Increment time variable (~24 days to overflow)
        TMR1IF = 0;     //Clear interrupt flag
    }
    /***** End User Code for high priority interrupts *****/
    
    //this ASM call must end the function (needed for kernel compliance)
    asm("goto 0x1008");
}

// LOW VECTOR

//#pragma code low_vector=0x1806
void interrupt_at_low_vector(void)
{   
    /***** User Code for low priority interrupts *****/
    
    /***** End User Code for low priority interrupts *****/
    
    //this ASM call must end the function (needed for kernel compliance)
    asm("goto 0x1008");
}

/*****End Kernel Compliance Section********************************************/

/*****Software Emulator Compliance Functions***********************************/
/*---- Display Functions ----*/
void initDisplay(void) {
    //Turn on display and set all LEDs off   
    /* Do Nothing -- Handled by kernel */
    /* function still needed for emulator compliance */
}
void displayClear(void) {
    //Turn all LEDs off
    for (uint8_t i=0; i<16; i++) {
        Buffer[i] = 0x00;
    }
}

void displayPixel(uint8_t x, uint8_t y, uint8_t state) {
    //Set LED to state (ON|OFF)
    uint8_t mask = 1<<(7-x);
    if (state == ON) {
        Buffer[y] |= mask;
    }
    else {
        Buffer[y] &= ~(mask);
    }
}

void displayClose(void) {
    //Close the display (used for SDL2 emulator window)
    /* Do nothing, not used on hardware badge*/
    /* function still needed for emulator compliance */
}
void displayLatch(void) {
    //Make display changes visible (can be used for a framebuffer)
    /* Do nothing, not used on hardware badge*/
    /* function still needed for emulator compliance */
}
/*--------------------*/



/*---- Control Functions ----*/
void initControl(void) {
    //Setup button input
    /* Do nothing, not used on hardware badge*/
    /* function still needed for emulator compliance */
}

uint8_t getControl(void) {
    //Return last pressed button
    uint8_t key_mask = KeyEdge;
    if (key_mask & 1<<1) { KeyEdge = 0x00; return LEFT; }
    if (key_mask & 1<<4) { KeyEdge = 0x00; return RIGHT; }
    if (key_mask & 1<<2) { KeyEdge = 0x00; return UP; }
    if (key_mask & 1<<3) { KeyEdge = 0x00; return DOWN; }
    return 0;
}


void initTime(void) {
    //Initialize timekeeping hardware
    T1CON = 0b00110001; // Fosc/4 1:8 Prescale
    TMR1IP = 0;
    TMR1IF = 0;
    TMR1IE = 1;
    PEIE = 1 ;
    GIE = 1;
}

uint32_t getTime(void) {
    //Return milliseconds (upcounting)
    return ticks;
}

void controlDelayMs(uint16_t ms) {
    //Delay milliseconds (blocking)
    ms = ms/10;
    while (ms > 0) {
        __delay_ms(10);
        --ms;
    }
}

/*****End Software Emulator Compliance*****************************************/

/*
 * For software emulator compliance main must call animateBadge()
 */
int main(int argc, char** argv) {
    /****Functions must be called to place code for kernel****/
    initBootloaderInterruptHandling();
    /****End mandatory function calls*************************/
    
    /****Begin User Code**************************************/
    controlDelayMs(1);  //Just to get around "never called" compiler warning
    initDisplay();
    initTime();
    initControl();
    displayClear();
    displayLatch();
    getTime();
    
    animateBadge();
    
    return (EXIT_SUCCESS);
}

