//*******************************************************************************/
// ----------------------------------------------------------------------------
// The Ohio State University
// ECE 3567 - Microcontrollers Lab
// Spring Semester 2020
// Instructor: Prof. Gregg Chapman
// Group #
// Name 1
// Name 2
// (MSP430FR6989 Launchpad) - Texas Instruments Corporation
// Code Composer Studio version 9.0.1
// (Filename)Timers.c or .h
// This module contains files necessary to Initialize Timer A0 for Lab 2
// Timer Ao is used for a periodic interrupt. The PWM output for CCR1 is
// configured to be present on P1.6
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

/*************************** Function Prototypes *******************************/
// Consider placing function prototypes in a header file, e.g. ECE3567.h


/***************************** First Function***********************************/
//*****************************************************************************
// Initialize GPIO
//*****************************************************************************
void Init_GPIO(void) {
    P1DIR |= BIT0;  // Set as output
    P9DIR |= BIT7;  // Set as output
    P1OUT |= BIT0;  // Clear RED LED
    P9OUT &= ~BIT7;  // Set GREEN LED

    return;
}

/******************************* END of Code ***************************************/
