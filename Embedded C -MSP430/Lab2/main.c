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

volatile unsigned int ISR_Counter; // Used to count to 10 in order to delay exactly 1 second
volatile unsigned char ISR_Flag = 0; // Flag to tell main() that a Timer A0 interrupt occurred
volatile unsigned char ISR_Flag_10 = 0; // Flag to tell main() that a Timer A0 interrupt occurred 10 times

/******************************** Variables *************************************/

// Consider placing global variables in a header file, e.g. ECE3567.h


/*************************** Function Prototypes *******************************/

// Consider placing function prototypes in a header file, e.g. ECE3567.h



/***************************** First Function***********************************/


void main(void) {
    // Initializations go here including Init_GPIO(), Init_Timer_A0(), etc
    WDT_A_hold(__MSP430_BASEADDRESS_WDT_A__);
    PMM_unlockLPM5();

    Init_GPIO();
    Init_Timer_A0();
    _enable_interrupt();

        while(1) {
                if(ISR_Flag==1) // Timer A0 has occurred.
                   {
                   ISR_Flag = 0;
                   }
                   if(ISR_Flag_10 ==1) // 1 Sec interval
                   {
                   ISR_Flag_10 = 0;
                       // MOVE YOUR LED XORs HERE
                   P1OUT ^= BIT0;
                   P9OUT ^= BIT7;
                   }
            }
    }


#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer_A0(void) {

    ISR_Flag = 1;
    ISR_Counter++;

    if (ISR_Counter >= 10) {
        ISR_Flag_10 = 1;
        ISR_Counter = 0;
    }

    return;
}


/******************************** END OF CODE **********************************/
