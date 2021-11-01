EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:+5V #PWR01
U 1 1 61802C4F
P 4750 1750
F 0 "#PWR01" H 4750 1600 50  0001 C CNN
F 1 "+5V" H 4765 1923 50  0000 C CNN
F 2 "" H 4750 1750 50  0001 C CNN
F 3 "" H 4750 1750 50  0001 C CNN
	1    4750 1750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR03
U 1 1 61802FB4
P 4850 1750
F 0 "#PWR03" H 4850 1600 50  0001 C CNN
F 1 "+5V" H 4865 1923 50  0000 C CNN
F 2 "" H 4850 1750 50  0001 C CNN
F 3 "" H 4850 1750 50  0001 C CNN
	1    4850 1750
	1    0    0    -1  
$EndComp
$Comp
L MCU_Microchip_ATmega:ATmega328P-MMH U1
U 1 1 61801C78
P 4750 3250
F 0 "U1" H 4106 3296 50  0000 R CNN
F 1 "ATmega328P-MMH" H 4106 3205 50  0000 R CNN
F 2 "Package_DFN_QFN:QFN-28-1EP_4x4mm_P0.45mm_EP2.4x2.4mm" H 4750 3250 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 4750 3250 50  0001 C CNN
	1    4750 3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 61803CC0
P 4750 4750
F 0 "#PWR02" H 4750 4500 50  0001 C CNN
F 1 "GND" H 4755 4577 50  0000 C CNN
F 2 "" H 4750 4750 50  0001 C CNN
F 3 "" H 4750 4750 50  0001 C CNN
	1    4750 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 2050 5600 2050
Wire Wire Line
	5350 2950 5600 2950
Wire Wire Line
	5350 4150 5600 4150
Wire Wire Line
	5350 4250 5600 4250
Wire Wire Line
	5350 4350 5600 4350
Wire Wire Line
	5350 4450 5600 4450
Text Label 5600 4150 0    50   ~ 0
PD4[4]-LCD_D4
Text Label 5600 4250 0    50   ~ 0
PD5[5]-LCD_D5
Text Label 5600 4350 0    50   ~ 0
PD6[6]-LCD_D6
Text Label 5600 4450 0    50   ~ 0
PD7[7]-LCD_D7
Text Label 5600 2050 0    50   ~ 0
PB0[8]-LCD_RS
Text Label 5600 2950 0    50   ~ 0
PC0[A0]-Buttons
Wire Wire Line
	5350 3550 5600 3550
Text Label 5600 3550 0    50   ~ 0
PC6[RESET]-RST_BTN
$Comp
L Device:R R1
U 1 1 61808270
P 5650 2350
F 0 "R1" V 5550 2350 50  0000 C CNN
F 1 "1k" V 5750 2350 50  0000 C CNN
F 2 "" V 5580 2350 50  0001 C CNN
F 3 "~" H 5650 2350 50  0001 C CNN
	1    5650 2350
	0    1    1    0   
$EndComp
$Comp
L Device:LED D1
U 1 1 6180858D
P 6050 2350
F 0 "D1" H 6050 2450 50  0000 C CNN
F 1 "LED" H 6050 2250 50  0000 C CNN
F 2 "" H 6050 2350 50  0001 C CNN
F 3 "~" H 6050 2350 50  0001 C CNN
	1    6050 2350
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR04
U 1 1 6180B7AC
P 6300 2350
F 0 "#PWR04" H 6300 2200 50  0001 C CNN
F 1 "+5V" V 6315 2478 50  0000 L CNN
F 2 "" H 6300 2350 50  0001 C CNN
F 3 "" H 6300 2350 50  0001 C CNN
	1    6300 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	6200 2350 6300 2350
Wire Wire Line
	5900 2350 5800 2350
Wire Wire Line
	5500 2350 5350 2350
Text Label 5600 2150 0    50   ~ 0
PB1[9]-LCD_E
Wire Wire Line
	5350 2150 5600 2150
$EndSCHEMATC
