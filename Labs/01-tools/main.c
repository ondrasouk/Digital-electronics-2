/***********************************************************************
 * 
 * Blink a LED and use function from the delay library.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Defines -----------------------------------------------------------*/
/* The preprocessor will process directives that are inserted into the C
 * source code. These directives allow additional actions to be taken on
 * the C source code before it is compiled into object code. Directives
 * are not part of the C language itself.
 *
 * Preprocessor directives begin with a pound (#) symbol and may have 
 * several arguments. Do NOT put a semicolon character at the end of 
 * directives. This is a common mistake.
 */
#define LED_GREEN   PB5 // AVR pin where green LED is connected

#define DOT_DELAY   200 // Delay in milliseconds, PARIS
#define DASH_DELAY  3*DOT_DELAY
#define INTER_DELAY 1*DOT_DELAY
#define CHAR_DELAY  DASH_DELAY-INTER_DELAY
#define WORD_DELAY  7*DOT_DELAY-INTER_DELAY
#ifndef F_CPU           // Preprocessor directive allows for conditional
                        // compilation. The #ifndef means "if not defined".
# define F_CPU 16000000 // CPU frequency in Hz required for delay
#endif                  // The #ifndef directive must be closed by #endif

/* Includes ----------------------------------------------------------*/
/* Include another C language file into the current file at the location
 * of the #include statement prior to compiling the source code.
 */
#include <util/delay.h> // Functions for busy-wait delay loops
#include <avr/io.h>     // AVR device-specific IO definitions

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: dot function for displaying dot in Morse code on LED
 * Returns:  none
 **********************************************************************/
void dot()
{
    // Invert LED in Data Register
    // PORTB = PORTB xor 0010 0000
    PORTB = PORTB ^ (1<<LED_GREEN);
    _delay_ms(DOT_DELAY);
    PORTB = PORTB ^ (1<<LED_GREEN);
    _delay_ms(INTER_DELAY);
}
/**********************************************************************
 * Function: dash function for displaying dash in Morse code on LED
 * Returns:  none
 **********************************************************************/
void dash()
{
    PORTB = PORTB ^ (1<<LED_GREEN);
    _delay_ms(DASH_DELAY);
    PORTB = PORTB ^ (1<<LED_GREEN);
    _delay_ms(INTER_DELAY);
}
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Display on LED in Morse code "DE2"
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Set pin as output in Data Direction Register
    // DDRB = DDRB or 0010 0000
    DDRB = DDRB | (1<<LED_GREEN);

    // Set pin LOW in Data Register (LED off)
    // PORTB = PORTB and 1101 1111
    PORTB = PORTB & ~(1<<LED_GREEN);

    // Infinite loop
    while (1)
    {
        // "DE2" in Morse code "-.. . ..---"
        dash();
        dot();
        dot();
        _delay_ms(CHAR_DELAY);
        dot();
        _delay_ms(CHAR_DELAY);
        dot();
        dot();
        dash();
        dash();
        dash();
        _delay_ms(WORD_DELAY);
    }

    // Will never reach this
    return 0;
}


