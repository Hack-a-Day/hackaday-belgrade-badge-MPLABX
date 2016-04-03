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

/*****Begin Kernel Compliance Section: Do not edit this code*******************/
void interrupt_at_high_vector(void) @ 0x1800
{
    //Do add or edit code inside this function; needed for kernel compliance
    asm("goto 0x1008");
}

// LOW VECTOR

//#pragma code low_vector=0x1806
void interrupt_at_low_vector(void) @ 0x1806
{
    //Do add or edit code inside this function; needed for kernel compliance
    asm("goto 0x1008");
}
/*****End Kernel Compliance Section********************************************/

/*****Software Emulator Compliance Functions***********************************/
/*---- Display Prototypes ----*/
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
    if (state == ON) {
        Buffer[y] |= 1<<(7-x);
    }
    else {
        Buffer[y] &= ~(1<<(7-x));
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



/*---- Control Prototypes ----*/
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
}

uint32_t getTime(void) {
    //Return milliseconds (upcounting)
    
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
 * 
 */
int main(int argc, char** argv) {
    /****Functions must be called to place code for kernel****/
    interrupt_at_high_vector();
    interrupt_at_low_vector();
    /****End mandatory function calls*************************/
    
    /****Begin User Code**************************************/
    initDisplay();
    initTime();
    displayLatch();
    
    animateBadge();
    
    return (EXIT_SUCCESS);
}

