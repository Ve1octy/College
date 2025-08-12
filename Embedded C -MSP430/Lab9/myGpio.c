// myGpio.c  ('FR6989 Launchpad)
// Dr. Gregg Chapman, The Ohio State University, January 2020
// ----------------------------------------------------------------------------

//***** Header Files **********************************************************
#include <driverlib.h>
#include "ECE3567.h"
#include "stdio.h"

//*****************************************************************************
// Initialize GPIO
//*****************************************************************************

void Init_GPIO(void)
{
    //Configure LED1 and LED2, both OFF
    P1DIR |= BIT0;  // Set P1.0 as output (RED LED)
    P9DIR |= BIT7;  // Set P9.7 as output (GREEN LED)
    P1OUT &= ~BIT0;              // Clear RED LED
    P9OUT &= ~BIT7;              // Clear GREEN LED
    //Set up pushbuttons on PORT1 Bit1 and Bit2 for Interrupts
    //Left Push Button: Set As Input Pin With Pull-up Resistor
    P1DIR &= ~BIT1;
    P1REN |= BIT1;
    P1OUT |= BIT1;
    //Left Push Button: Select Interrupt Edge as Low to High
    P1IES &= ~BIT1;
    //Left Push Button: Clear Interrupt P1IFG.1
    P1IFG &= ~BIT1;
    //Left Push Button: Enable Interrupt
    P1IE |= BIT1;
    //Right Push Button: Set As Input Pin With Pull-up Resistor
    P1DIR &= ~BIT2;
    P1REN |= BIT2;
    P1OUT |= BIT2;
    //Right Push Button: Select Interrupt Edge as Low to High
    P1IES &= BIT2;
    //Right Push Button: Clear Interrupt P1IFG.2
    P1IFG  &= ~BIT2;// Clear P1IFG.1
    //Right Push Button: Enable Interrupt
    P1IE |= BIT2;
    return;
}
