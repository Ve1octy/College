//*******************************************************************************/

// ----------------------------------------------------------------------------

// The Ohio State University

// ECE 3567 - Microcontrollers Lab

// Spring Semester 2025

// Instructor: Prof. Gregg Chapman

// Group # 18

// Aidan Sivak

// Name 2

// (MSP430FR6989 Launchpad) - Texas Instruments Corporation

// Code Composer Studio version 9.1.0

// (Filename).c or .h

// This module contains files necessary to ....... as part of Lab 1

// ----------------------------------------------------------------------------

/*******************************************************************************/


//***** Header Files ***********************************************************/


#include <driverlib.h>

#include "stdio.h"

#include "string.h"

#include "ECE3567.h"


/********************* Compiler Directives and Definitions **********************/



/******************************** Variables *************************************/

// Consider placing global variables in a header file, e.g. ECE3567.h

void delay(long unsigned int delay_count);
/*************************** Function Prototypes *******************************/

// Consider placing function prototypes in a header file, e.g. ECE3567.h



/***************************** First Function***********************************/


int main(void) {

    WDT_A_hold(__MSP430_BASEADDRESS_WDT_A__);       //Disable watchdog timer
    PMM_unlockLPM5();                               //Release all pins on MCU


        P1DIR |= BIT0;                      //Set bit for direction
        P9DIR |= BIT7;                      //Set bit for direction
        P1OUT &= ~BIT0;                     //Clear then invert for Red LED off
        P9OUT |= BIT7;                      //Green LED ON

       unsigned long int delay_count;

        while(1)
        {

            delay_count = 0x20000;
            delay(delay_count);

            P1OUT ^= BIT0;
            P9OUT ^= BIT7;
        }

}


/******************************** END OF CODE **********************************/
void delay(long unsigned int delay_count) {

    long unsigned int count = delay_count;

    while (count > 1) {

        count--;
        __no_operation();

    }

        return;
}
