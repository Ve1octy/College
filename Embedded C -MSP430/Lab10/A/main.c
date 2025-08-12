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
volatile unsigned int ISR_Counter;
volatile unsigned int ISR_Flag;
volatile unsigned int ISR_Flag_10;

int main(void) {
    WDT_A_hold(__MSP430_BASEADDRESS_WDT_A__);   //****** TI Macro used to stop the watchdog timer    Commented out for CP2
    PMM_unlockLPM5();                           //****** Disable the GPIO power-on default high-impedance mode
    Init_GPIO();                // Configure GPIO for LEDs
    Init_Timer_A0();            // Set-up TA0 for 100 mSec ISR
//       Configure the Watchdog Timer here
    WDTCTL = 0x5A24;
//       Start the Watchdog Timer here
    WDT_A_start(__MSP430_BASEADDRESS_WDT_A__);  //commented out for CP1
    __enable_interrupt();
    while(1)                    // Main Loop
    {
//       Case 1 Watchdog Reset
        //WDT_A_resetTimer(__MSP430_BASEADDRESS_WDT_A__); // Shortest WDTCTL = 0x5A27;

        if(ISR_Flag == 1)       // Single ISR
            {
//       Case 2 Watchdog Reset
            //WDT_A_resetTimer(__MSP430_BASEADDRESS_WDT_A__); //Shortest WDTCTL = 0x5A25;
               ISR_Flag = 0;    // Reset
        }

        if(ISR_Flag_10 == 1)    // 10 ISRs are 1 Second
        {
//       Case 3 Watchdog Reset
            //WDT_A_resetTimer(__MSP430_BASEADDRESS_WDT_A__);  //Shortest WDTCTL = 0x5A24;

           P1OUT ^= BIT0;          // Toggle RED LED
           P9OUT ^= BIT7;          // Toggle GREEN LED
           ISR_Flag_10 = 0;        // Dismiss
         }
    }
}
/********************************* END MAIN *****************************/

/************************ Interrupt Service Routine for Timer A0 ********/
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A(void)
{
//       Case 4 Watchdog Reset
   ISR_Flag = 1;                    // 100 millisecond ISR
   ISR_Counter++;                   // Count ISRs
    if(ISR_Counter>=10)             // 10 ISRs = 1 Sec.
    {
        ISR_Flag_10 = 1;            // 1 Second to main
        ISR_Counter=0;              // Reset Counter
        WDT_A_resetTimer(__MSP430_BASEADDRESS_WDT_A__);  //Shortest WDTCTL = 0x5A24;

    }
    return;
}
/****************************** END OF ISR **********************************/
/**************************** END OF CODE ***********************************/


