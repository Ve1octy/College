/*
 * myGPIO.c
 *
 *  Created on: Feb 4, 2025
 *      Author: sivak.13
 */


#include <driverlib.h>

#include "stdio.h"

#include "string.h"
#include "ECE3567_Lab3.h"

void Init_GPIO(void) {

        P1DIR |= BIT0;                      //Set bit for direction
        P9DIR |= BIT7;                      //Set bit for direction
        P1OUT &= ~BIT0;                     //Clear then invert for Red LED off
        P9OUT |= BIT7;                      //Green LED ON

}
