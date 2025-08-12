/*
 * Timer.c
 *
 *  Created on: Feb 4, 2025
 *      Author: sivak.13
 */

#include <driverlib.h>

#include "stdio.h"

#include "string.h"
#include "ECE3567.h"

void Init_Timer_A0(void) {

    TA0CTL = 0x0110;
        //TASSEL = ACLK // 32.768 KHz
        //ID = /1 // No Pre-Divide
        //MC = Up Mode // Timer A0 in Up Mode
    //TA0CCTL0 – Comparator 0 Control Register
        TA0CCTL0 = 0x0010;
        //CCIE = enabled (1) // Interrupt enabled for CCR0
    //TA0CCTL1 – Comparator 1 Control Register
       // OUTMOD = Reset/Set (111) // Reset/Set Mode for PWM
        TA0CCTL1 = 0x00E0;
    //TA0CCR0 – Comparator 0
       TA0CCR0 = 0x0CCD; // 100 mSec period
    //TA0CCR1 – Comparator 1
       TA0CCR1 = 0x0666; // 50% Duty Cycle

}

