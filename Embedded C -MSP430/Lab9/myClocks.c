// ----------------------------------------------------------------------------
// myClocks.c  ('FR6989 Launchpad)
//
// This routine sets up the Low Frequency crystal (LFXT) and high-freq
// internal clock source (DCO). Then configures ACLK, SMCLK, and MCLK:
//    ACLK  = 32KHz
//    SMCLK =  8MHz
//    MCLK  =  8MHz
//
// Gregg Chapman, The Ohio State University, February 2018
// ----------------------------------------------------------------------------

//***** Header Files **********************************************************
#include <driverlib.h>
#include "ECE3567.h"


void Init_Timer_A0(void)
{
      TA0CTL = 0x0110;     // Set ACLK, UP MODE for Timer_0
      TA0CCTL0 |= CCIE;    // Enable interrupt for Timer_0 (0x0010)
      TA0CCTL1 = 0x00E0;   // CCR1 reset/set
      TA0CCR0 = 0x0CCE;    // for 10 Hz=100 ms and count is 3278
      TA0CCR1 = 0x0667;    // CCR1 PWM at 50 % duty cycle, on TA0.1
      return;
}





