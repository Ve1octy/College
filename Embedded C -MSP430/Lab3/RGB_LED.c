/*
 * RGB_LED.c
 *
 *  Created on: Feb 11, 2025
 *      Author: sivak.13
 */


#include <driverlib.h>

#include "stdio.h"

#include "string.h"
#include "ECE3567_Lab3.h"

#define step_size 2



void Init_PWM() {

                   //TA0CTL = 0x0110;
           //TASSEL = ACLK // 32.768 KHz
           //ID = /1 // No Pre-Divide
           //MC = Up Mode // Timer A0 in Up Mode
           //TA0CCTL0 – Comparator 0 Control Register
                   //TA0CCTL0 = 0x0010;
           //CCIE = enabled (1) // Interrupt enabled for CCR0
           //TA0CCTL1 – Comparator 1 Control Register
           // OUTMOD = Reset/Set (111) // Reset/Set Mode for PWM
                   //TA0CCTL1 = 0x00E0;
           //TA0CCR0 – Comparator 0
                   //TA0CCR0 = 0x0CCD; // 100 mSec period
           //TA0CCR1 – Comparator 1
                   //TA0CCR1 = 0x0666; // 50% Duty Cycle
            duty_cycle_blue = 0x0000;
            duty_cycle_green = 0x0000;
            duty_cycle_red = 0x0070;


            P3DIR |= BIT7;
            P3DIR |= BIT6;
            P2DIR |= BIT2;
            P3SEL1 |= BIT7;
            P3SEL0 &= ~BIT7;
            P2SEL1 |= BIT2;
            P2SEL0 &= ~BIT2;
            P3SEL1 |= BIT6;
            P3SEL0 &= ~BIT6;

           TB0CTL = 0x0110;
           TB0CCTL2 = 0x00E0;
           TB0CCTL3 = 0x00E0;
           TB0CCTL4 = 0x00E0;
           TB0CCR0 = RGB_Period;
           TB0CCR2 = duty_cycle_blue;
           TB0CCR3 = duty_cycle_green;
           TB0CCR4 = duty_cycle_red;

           return;
}



void update_RGB() {

//    int red_count = 0;

//    switch (State) {
//
//
//
//    case 1:                     //Delay red for 1.5 seconds
//        red_count++;
//        if(red_count >= 15) {
//            red_count = 0;
//            State = 2;
//        }
//
//    case 2:
//
//        if (duty_cycle_green < MAX_Green){
//            duty_cycle_green += step_size;
//        }
//        else {
//            State = 3;
//        }
//        break;
//
//    case 3:
//
//        if (duty_cycle_red > step_size){
//            duty_cycle_red -= step_size;
//         }
//         else {
//            State = 4;
//         }
//         break;
//
//    case 4:
//
//        if (duty_cycle_blue < MAX_Blue){
//            duty_cycle_blue += step_size;
//        }
//        else {
//           State = 5;
//        }
//        break;
//
//    case 5:
//
//        if (duty_cycle_green > step_size){
//            duty_cycle_green -= step_size;
//         }
//         else {
//             State = 6;
//         }
//         break;
//
//    case 6:
//
//        if (duty_cycle_red < MAX_Red){
//            duty_cycle_red += step_size;
//        }
//        else {
//             State = 7;
//        }
//        break;
//
//    case 7:
//
//        if (duty_cycle_blue > step_size){
//           duty_cycle_blue -= step_size;
//        }
//        else {
//            State = 1;
//        }
//        break;
//    }

    LED_Color++;
    if(LED_Color > White) {
        LED_Color = Red;
    }

    switch (LED_Color) {

    case Red:
        duty_cycle_red = 0x0070;
        duty_cycle_green = 0x0000;
        duty_cycle_blue = 0x0000;
        break;

    case Orange:
        duty_cycle_red = 0x00C4;
        duty_cycle_green = 0x0024;
        duty_cycle_blue = 0x0000;
        break;

    case Yellow:
        duty_cycle_red = 0x00C4;
        duty_cycle_green = 0x00AB;
        duty_cycle_blue = 0x0000;
        break;

    case Green:
        duty_cycle_red = 0x0000;
        duty_cycle_green = 0x004A;
        duty_cycle_blue = 0x0000;
        break;

    case Blue:
        duty_cycle_red = 0x0000;
        duty_cycle_green = 0x0000;
        duty_cycle_blue = 0x007A;
        break;

    case Violet:
        duty_cycle_red = 0x0026;
        duty_cycle_green = 0x0000;
        duty_cycle_blue = 0x007A;
        break;

    case White:
        duty_cycle_red = 0x00B0;
        duty_cycle_green = 0x0090;
        duty_cycle_blue = 0x00D0;
        break;

    case No_Color:
        duty_cycle_red = 0x0000;
        duty_cycle_green = 0x0000;
        duty_cycle_blue = 0x0000;
        break;

    default:
        duty_cycle_red = 0x0000;
        duty_cycle_green = 0x0000;
        duty_cycle_blue = 0x0000;
        break;

    }

    TB0CCR2 = duty_cycle_blue;
    TB0CCR3 = duty_cycle_green;
    TB0CCR4 = duty_cycle_red;
    return;

}



void PWM_null() {

        duty_cycle_blue = 0x0000;
        duty_cycle_green = 0x0000;
        duty_cycle_red = 0x0000;

        TB0CCR2 = duty_cycle_blue;
        TB0CCR3 = duty_cycle_green;
        TB0CCR4 = duty_cycle_red;

    return;
}
