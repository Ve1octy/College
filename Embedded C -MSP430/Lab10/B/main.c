//*******************************************************************************/
// ----------------------------------------------------------------------------
// The Ohio State University
// ECE 3567 - Microcontrollers Lab
// Spring Semester 2022
// Instructor: Prof. Gregg Chapman
// Group # xxxx
// Name 1
// Name 2
// (MSP430FR6989 Launchpad) - Texas Instruments Corporation
// Code Composer Studio version 9.0.1
// (Filename)main.c or .h
// This module contains files necessary to alternate Red and Green LEDs at exactly 1 Hz,
//  using a Timer A0 ISR, as part of Lab 9 Part 1
// ----------------------------------------------------------------------------
/*******************************************************************************/
//***** Header Files ***********************************************************/
#include <driverlib.h>
#include "stdio.h"
#include "string.h"
#include "ECE3567.h"
/******************************** Variables *************************************/
volatile unsigned char ISR_Flag_WDT = 0; // Flag to tell main() that a WDT interrupt occurred
/***************************** First Function***********************************/
int main(void)
{
    WDT_A_hold(WDT_A_BASE);     // Disable Watchdog counter
    PMM_unlockLPM5();           // Release pins from all input state
    Init_GPIO();                // Configure GPIO for LEDs
    // Configure WDTCTL - Password/WDT OFF/ ACLK/ Internal Mode / 1 Second count
    WDTCTL = 0x5ABC;
    // Enable WDT interrupt
    SFRIE1 |= BIT0;
    // Start the Watchdog Timer
    WDT_A_start(__MSP430_BASEADDRESS_WDT_A__);
    __enable_interrupt();
    while(1)                    // Main Loop
        {
            if(ISR_Flag_WDT == 1)    // WDT ISR at 1 Second
            {
               P1OUT ^= BIT0;        // Toggle RED LED
               P9OUT ^= BIT7;        // Toggle GREEN LED
               ISR_Flag_WDT = 0;     // Clear ISR flag
             }
        }
}
/********************************* END MAIN ***************************************/
/******************************** Interrupt Service Routine for WDT ****************/

#pragma vector=WDT_VECTOR
__interrupt void watchdog_timer(void){
               ISR_Flag_WDT = 1;     // Flag to main
    return;
}
/****************************** END OF CODE ****************************************/
