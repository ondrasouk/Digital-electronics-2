/***********************************************************************
 * 
 * Stopwatch with LCD display output.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2017-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include "lcd.h"            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for conversion function

/* Variables ---------------------------------------------------------*/
// Custom character definition using https://omerk.github.io/lcdchargen/
uint8_t customChar[56] = {
    0b00111,
    0b01110,
    0b11100,
    0b11000,
    0b11100,
    0b01110,
    0b00111,
    0b00011,
    0b00000,
	0b00100,
	0b00110,
	0b00111,
	0b00110,
	0b00100,
	0b00100,
    0b11111,
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b11000,
	0b11000,
	0b11000,
	0b11000,
	0b11000,
	0b11000,
	0b11000,
	0b11000,
	0b11100,
	0b11100,
	0b11100,
	0b11100,
	0b11100,
	0b11100,
	0b11100,
	0b11100,
	0b11110,
	0b11110,
	0b11110,
	0b11110,
	0b11110,
	0b11110,
	0b11110,
	0b11110,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
};
/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Update stopwatch value on LCD display when 8-bit 
 *           Timer/Counter2 overflows.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Initialize LCD display
    lcd_init(LCD_DISP_ON);
    
    lcd_command(1 << LCD_CGRAM);
    for (uint8_t i = 0; i < 56; i++){
        lcd_data(customChar[i]);
    }
    lcd_command(1 << LCD_DDRAM);
    lcd_gotoxy(0, 1);
    lcd_putc(0);
    lcd_putc(1);
    lcd_putc(2);
    lcd_putc(3);
    lcd_putc(4);
    lcd_putc(5);
    lcd_putc(6);
    
    // Put string(s) at LCD display
    lcd_gotoxy(1, 0);
    lcd_puts("LCD Test");
    lcd_putc('!');

    // Configure 8-bit Timer/Counter2 for Stopwatch
    // Set the overflow prescaler to 16 ms and enable interrupt
    TIM2_overflow_16ms();
    TIM2_overflow_interrupt_enable();

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}

void int2disp(uint16_t){
    
}

/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter2 overflow interrupt
 * Purpose:  Update the stopwatch on LCD display every sixth overflow,
 *           ie approximately every 100 ms (6 x 16 ms = 100 ms).
 **********************************************************************/
ISR(TIMER2_OVF_vect)
{
    static uint8_t number_of_overflows = 0;
    static int8_t first = 120; //2s = 6 * 20 = 120
    static uint8_t tens = 0;
    static uint8_t min = 0, sec = 0;
    static char lcd_char = 0;

    number_of_overflows++;
    if (number_of_overflows >= 6)
    {
        // Do this every 6 x 16 ms = 100 ms
        number_of_overflows = 0;
        
        if (first > 0){
            first--;
        }
        else if (first == 0){
            lcd_clrscr();
            first--;
            lcd_gotoxy(0,0);
            lcd_puts(" 00:00.0   a");
            lcd_gotoxy(0,1);
            lcd_puts(" b         c");
        }
        else{
            tens++;
            if (tens == 10){
                sec++;
                if (sec == 60){
                    min++;
                    sec = 0;
                    tens = 0;
                    itoa(min%10, &lcd_char, 10);
                    lcd_gotoxy(2,0);
                    lcd_puts(&lcd_char);
                    itoa(min/10, &lcd_char, 10);
                    lcd_gotoxy(1,0);
                    lcd_puts(&lcd_char);
                }
                tens = 0;
                itoa(sec%10, &lcd_char, 10);
                lcd_gotoxy(5,0);
                lcd_puts(&lcd_char);
                itoa(sec/10, &lcd_char, 10);
                lcd_gotoxy(4,0);
                lcd_puts(&lcd_char);
            }
            itoa(tens, &lcd_char, 10);
            lcd_gotoxy(7,0);
            lcd_puts(&lcd_char);
        }
    }
    // Else do nothing and exit the ISR
}
