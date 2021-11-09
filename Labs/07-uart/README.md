# Lab 7: Ondřej Soukeník

Link to this file in your GitHub repository:

[https://github.com/ondrasouk/Digital-electronics-2/blob/main/Labs/07-uart/README.md](https://github.com/ondrasouk/Digital-electronics-2/blob/main/Labs/07-uart/README.md)


### Analog-to-Digital Conversion

1. Complete table with voltage divider, calculated, and measured ADC values for all five push buttons.

   | **Push button** | **PC0[A0] voltage** | **ADC value (calculated)** | **ADC value (measured)** |
   | :-: | :-: | :-: | :-: |
   | Right  | 0&nbsp;V | 0   | 0 |
   | Up     | 0.495&nbsp;V | 101 | 157 |
   | Down   | 1.203&nbsp;V | 246 | 329 |
   | Left   | 1.970&nbsp;V | 403 | 507 |
   | Select | 3.182&nbsp;V | 651 | 743 |
   | none   | 5&nbsp;V | 1024 | 1023 |

2. Code listing of ACD interrupt service routine for sending data to the LCD/UART and identification of the pressed button. Always use syntax highlighting and meaningful comments:

```c
/**********************************************************************
 * Function: ADC complete interrupt
 * Purpose:  Display value on LCD and send it to UART.
 **********************************************************************/
ISR(ADC_vect)
{
    uint16_t value = 0;
    char lcd_string[4] = "0000";

    value = ADC;                  // Copy ADC result to 16-bit variable
    itoa(value, lcd_string, 10);  // Convert decimal value to string
    lcd_gotoxy(8, 0);
    lcd_puts("    ");
    lcd_gotoxy(8, 0);
    lcd_puts(lcd_string);
    uart_puts("\n\rADC Value: ");
    uart_puts(lcd_string);
    itoa(value, lcd_string, 16);  // Convert hexadecimal value to string
    lcd_gotoxy(13, 0);
    lcd_puts("    ");
    lcd_gotoxy(13, 0);
    lcd_puts(lcd_string);
    //uart_puts("\n\rADC Value (hex): "); uart_puts(lcd_string); 
    // probably the interrupt routine takes too long and the MCU stops - Workaround: comment some code in routine
    if((value <= 1024) && (value > 950)){
        lcd_gotoxy(8, 1);
        lcd_puts("none  ");
        uart_puts("\n\rKey: none");
    }
    else if((value <= 950) && (value > 650)){
        lcd_gotoxy(8, 1);
        lcd_puts("SELECT");
        uart_puts("\n\rKey: SELECT");
    }
    else if((value <= 650) && (value > 440)){
        lcd_gotoxy(8, 1);
        lcd_puts("LEFT  ");
        uart_puts("\n\rKey: LEFT");
    }
    else if((value <= 440) && (value > 180)){
        lcd_gotoxy(8, 1);
        lcd_puts("DOWN  ");
        uart_puts("\n\rKey: DOWN");
    }
    else if((value <= 180) && (value > 60)){
        lcd_gotoxy(8, 1);
        lcd_puts("UP    ");
        uart_puts("\n\rKey: UP");
    }
    else if(value <= 60){
        lcd_gotoxy(8, 1);
        lcd_puts("RIGTH ");
        uart_puts("\n\rKey: RIGTH");
    }
}
```


### UART communication

1. (Hand-drawn) picture of UART signal when transmitting three character data `De2` in 4800 7O2 mode (7 data bits, odd parity, 2 stop bits, 4800&nbsp;Bd).

D -> 0x44 -> 0b0100_0100 parity 1; e -> 0x65 -> 0b0110_0101 parity 1; 2 -> 0x32 -> 0b0011_0010 parity 0; First MSB bit is omitted.
   ![UART](images/uart.jpg)

2. Flowchart figure for function `uint8_t get_parity(uint8_t data, uint8_t type)` which calculates a parity bit of input 8-bit `data` according to parameter `type`. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![flowchart](images/flowchart.png)


### Temperature meter

Consider an application for temperature measurement and display. Use temperature sensor [TC1046](http://ww1.microchip.com/downloads/en/DeviceDoc/21496C.pdf), LCD, one LED and a push button. After pressing the button, the temperature is measured, its value is displayed on the LCD and data is sent to the UART. When the temperature is too high, the LED will start blinking.

1. Scheme of temperature meter. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![schema](images/schema.svg)
   ![schema](images/04.svg)
