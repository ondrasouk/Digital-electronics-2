# Lab 5: YOUR_FIRSTNAME FAMILYNAME

Link to your `Digital-electronics-2` GitHub repository:

   [https://github.com/ondrasouk/Digital-electronics-2/](https://github.com/ondrasouk/Digital-electronics-2/)


### 7-segment library

1. In your words, describe the difference between Common Cathode and Common Anode 7-segment display.
   * CC SSD - The common pin is connected to typically VCC. The input to LEDs in SSD is in mode 'active low' (active when input pin is connected to GND).
   * CA SSD - The common pin is connected to GND. The input to LEDs in SSD is in mode 'active high' (active when input pin is connected to VCC).

2. Code listing with syntax highlighting of two interrupt service routines (`TIMER0_OVF_vect`, `TIMER0_OVF_vect`) from counter application with at least two digits, ie. values from 00 to 59:

```c
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Increment counter value from 00 to 59.
 **********************************************************************/
uint8_t x = 0, y = 0;
ISR(TIMER1_OVF_vect)
{
    x++;
    if (x == 10){
        x = 0;
        y++;
        if (y == 6){
            y = 0;
        }
    }
}
```

```c
/**********************************************************************
 * Function: Timer/Counter0 overflow interrupt
 * Purpose:  Display tens and units of a counter at SSD.
 **********************************************************************/
ISR(TIMER0_OVF_vect)
{
    static uint8_t pos = 0;
    if (pos == 0){
        SEG_update_shift_regs(x,0);
    }
    else if (pos == 1){
        SEG_update_shift_regs(y,1);
    }
    pos++;
    if (pos > 1) {
        pos = 0;
    }
}
```

3. Flowchart figure for function `SEG_clk_2us()` which generates one clock period on `SEG_CLK` pin with a duration of 2&nbsp;us. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![flowchart](images/flowchart_clk_2us.png)


### Kitchen alarm

Consider a kitchen alarm with a 7-segment display, one LED and three push buttons: start, +1 minute, -1 minute. Use the +1/-1 minute buttons to increment/decrement the timer value. After pressing the Start button, the countdown starts. The countdown value is shown on the display in the form of mm.ss (minutes.seconds). At the end of the countdown, the LED will start blinking.

1. Scheme of kitchen alarm; do not forget the supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![schema](images/schema_kitchen_alarm.svg)
