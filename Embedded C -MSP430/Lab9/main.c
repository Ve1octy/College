//*******************************************************************************/
// ----------------------------------------------------------------------------
// The Ohio State University
// ECE 3567 - Microcontrollers Lab
// Spring Semester 2022,  DATE
// Instructor: Prof. Gregg Chapman
// (MSP430FR6989 Launchpad) - Texas Instruments Corporation
// Code Composer Studio version 9.0.1
// main.c
// This module contains files necessary to Lab 10
// ----------------------------------------------------------------------------
/*******************************************************************************/

//***** Header Files ***********************************************************/
#include <driverlib.h>
#include "stdio.h"
#include "string.h"
#include "ECE3567.h"
//***** Lab 10 Variables ******************************************************
  // For NVRAM make count persistent
#pragma PERSISTENT(count);
  // Declare and initialize count
uint16_t count = 0;
/*************************** Function Prototypes *******************************/
void delay(long unsigned int);
/***************************** main () ***********************************/
void main(void) {
    // Stop Watchdog Timer
    WDT_A_hold(__MSP430_BASEADDRESS_WDT_A__);
    // Disable the GPIO power-on default high-impedance mode
    PMM_unlockLPM5();
    //*********************The Initializations*************************************/
    Init_LCD();             // Display, in myLCD.c
    Init_GPIO();            // I/O including LED, in myGpio.c
    Init_Timer_A0();        // 100mSec, in  myClocks.c
    __enable_interrupt();   // Enables all defined interrupts
    while(1)
    {
        if(ISR_Flag == 1)    // Set every 100mSec
        {
            ISR_Flag = 0;
            displayCount(count);
    // update LCD display with current count value
        }
    }
}


//*****************************************************************************
// Interrupt Service Routines
//*****************************************************************************
/*******************************  Time A0 ISR **********************************/
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A(void)
{
   ISR_Flag = 1;                    // 100 millisecond ISR
    return;
}
/*******************************  Pushbutton ISR **********************************/
#pragma vector=PORT1_VECTOR
__interrupt void pushbutton_ISR (void)
{
    unsigned long int debounce = 0x2000;    // adjust debounce here. 0x2000 is 100 mSec
    switch(P1IV) {                      // Test Port1 Interrupt Vector Register
       case P1IV_NONE:   break;         // None
       case P1IV_P1IFG1:                // Pin 1 (button 1)
             GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);             // Red LED ON
             delay(debounce);              // debounce
             if (((P1IN & BIT1) == 0x02)) {
                 count++;                 // Count up
             }
             GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);                           // is button still released?
             P1IFG &= ~BIT1;             // Clear interrupt flag
            break;

       case P1IV_P1IFG2:                // Pin 2 (button 2)
           GPIO_setOutputHighOnPin(GPIO_PORT_P9, GPIO_PIN7);                // Green LED ON
            delay(debounce);                // debounce
            if (((P1IN & BIT2) == 0x04)) { // is button still released?
                if(count > 0){
                    count--;                    // Count down
                }
            }
            GPIO_setOutputLowOnPin(GPIO_PORT_P9, GPIO_PIN7);             // Green LED OFF
            P1IFG &= ~BIT2;              // Clear interrupt flag
                                        // Test for zero
            break;

       default:
           break;
    }
    return;
}

/******************************** Delay **********************************/

void delay(long unsigned int x)
{
    long unsigned int delay_count = x;
    while(delay_count>0)
    {
        delay_count--;
        __no_operation();
    }
    return;
}
/******************************** END OF CODE **********************************/
