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
L MySymbols:TACTILE-NAV-SWITCH J1
U 1 1 6167DB3B
P 4550 2800
F 0 "J1" H 4550 3265 50  0000 C CNN
F 1 "TACTILE-NAV-SWITCH" H 4550 3174 50  0000 C CNN
F 2 "MyFootprints:JS1300AQ" H 4900 3200 50  0001 C CNN
F 3 "https://sten-eswitch-13110800-production.s3.amazonaws.com/system/asset/product_line/data_sheet/21/JS1300.pdf" H 4900 3200 50  0001 C CNN
	1    4550 2800
	1    0    0    -1  
$EndComp
$Comp
L MCU_Module:WeMos_D1_mini U1
U 1 1 616A6F86
P 1100 1700
F 0 "U1" H 1100 811 50  0000 C CNN
F 1 "WeMos_D1_mini" H 1100 720 50  0000 C CNN
F 2 "Module:WEMOS_D1_mini_light" H 1100 550 50  0001 C CNN
F 3 "https://wiki.wemos.cc/products:d1:d1_mini#documentation" H -750 550 50  0001 C CNN
	1    1100 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 616AB4D4
P 1800 1250
F 0 "R1" H 1870 1296 50  0000 L CNN
F 1 "4.7k" H 1870 1205 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 1730 1250 50  0001 C CNN
F 3 "~" H 1800 1250 50  0001 C CNN
	1    1800 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 616AC4CC
P 6350 1000
F 0 "C1" H 6465 1046 50  0000 L CNN
F 1 "0.1uF" H 6465 955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 6388 850 50  0001 C CNN
F 3 "~" H 6350 1000 50  0001 C CNN
	1    6350 1000
	0    -1   -1   0   
$EndComp
$Comp
L BAW56:BAW56 U8
U 1 1 616D14AA
P 10600 950
F 0 "U8" H 11500 1315 50  0000 C CNN
F 1 "BAW56" H 11500 1224 50  0000 C CNN
F 2 "SOT95P240X110-3N" H 10600 950 50  0001 L BNN
F 3 "" H 10600 950 50  0001 L BNN
F 4 "BAW56" H 10600 950 50  0001 L BNN "MPN"
F 5 "1902423" H 10600 950 50  0001 L BNN "OC_FARNELL"
F 6 "-" H 10600 950 50  0001 L BNN "OC_NEWARK"
F 7 "SOT-23-3" H 10600 950 50  0001 L BNN "PACKAGE"
F 8 "DIODES INC." H 10600 950 50  0001 L BNN "SUPPLIER"
	1    10600 950 
	0    1    1    0   
$EndComp
$Comp
L BAW56:BAW56 U7
U 1 1 616D22B9
P 9800 950
F 0 "U7" H 10700 1315 50  0000 C CNN
F 1 "BAW56" H 10700 1224 50  0000 C CNN
F 2 "SOT95P240X110-3N" H 9800 950 50  0001 L BNN
F 3 "" H 9800 950 50  0001 L BNN
F 4 "BAW56" H 9800 950 50  0001 L BNN "MPN"
F 5 "1902423" H 9800 950 50  0001 L BNN "OC_FARNELL"
F 6 "-" H 9800 950 50  0001 L BNN "OC_NEWARK"
F 7 "SOT-23-3" H 9800 950 50  0001 L BNN "PACKAGE"
F 8 "DIODES INC." H 9800 950 50  0001 L BNN "SUPPLIER"
	1    9800 950 
	0    1    1    0   
$EndComp
$Comp
L BAW56:BAW56 U5
U 1 1 616D2801
P 9000 950
F 0 "U5" H 9900 1315 50  0000 C CNN
F 1 "BAW56" H 9900 1224 50  0000 C CNN
F 2 "SOT95P240X110-3N" H 9000 950 50  0001 L BNN
F 3 "" H 9000 950 50  0001 L BNN
F 4 "BAW56" H 9000 950 50  0001 L BNN "MPN"
F 5 "1902423" H 9000 950 50  0001 L BNN "OC_FARNELL"
F 6 "-" H 9000 950 50  0001 L BNN "OC_NEWARK"
F 7 "SOT-23-3" H 9000 950 50  0001 L BNN "PACKAGE"
F 8 "DIODES INC." H 9000 950 50  0001 L BNN "SUPPLIER"
	1    9000 950 
	0    1    1    0   
$EndComp
$Comp
L BAW56:BAW56 U6
U 1 1 616D309F
P 8200 950
F 0 "U6" H 9100 1315 50  0000 C CNN
F 1 "BAW56" H 9100 1224 50  0000 C CNN
F 2 "SOT95P240X110-3N" H 8200 950 50  0001 L BNN
F 3 "" H 8200 950 50  0001 L BNN
F 4 "BAW56" H 8200 950 50  0001 L BNN "MPN"
F 5 "1902423" H 8200 950 50  0001 L BNN "OC_FARNELL"
F 6 "-" H 8200 950 50  0001 L BNN "OC_NEWARK"
F 7 "SOT-23-3" H 8200 950 50  0001 L BNN "PACKAGE"
F 8 "DIODES INC." H 8200 950 50  0001 L BNN "SUPPLIER"
	1    8200 950 
	0    1    1    0   
$EndComp
Wire Wire Line
	1000 900  1000 750 
$Comp
L power:+5V #PWR0101
U 1 1 616E34AC
P 1000 750
F 0 "#PWR0101" H 1000 600 50  0001 C CNN
F 1 "+5V" H 1015 923 50  0000 C CNN
F 2 "" H 1000 750 50  0001 C CNN
F 3 "" H 1000 750 50  0001 C CNN
	1    1000 750 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 616E3FDE
P 1100 2650
F 0 "#PWR0102" H 1100 2400 50  0001 C CNN
F 1 "GND" H 1105 2477 50  0000 C CNN
F 2 "" H 1100 2650 50  0001 C CNN
F 3 "" H 1100 2650 50  0001 C CNN
	1    1100 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 2650 1100 2500
$Comp
L Device:R R2
U 1 1 616E5F64
P 2000 1350
F 0 "R2" H 2070 1396 50  0000 L CNN
F 1 "4.7k" H 2070 1305 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 1930 1350 50  0001 C CNN
F 3 "~" H 2000 1350 50  0001 C CNN
	1    2000 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 1100 1900 1100
Wire Wire Line
	2000 1100 2000 1150
Connection ~ 1900 1100
Wire Wire Line
	1900 1100 2000 1100
Wire Wire Line
	1200 900  1900 900 
Wire Wire Line
	1900 900  1900 1100
Wire Wire Line
	1500 1400 1800 1400
Wire Wire Line
	1800 1400 2300 1400
Connection ~ 1800 1400
Wire Wire Line
	1500 1500 2000 1500
Wire Wire Line
	2000 1500 2400 1500
Connection ~ 2000 1500
$Comp
L power:GND #PWR0103
U 1 1 616EEA72
P 3200 2150
F 0 "#PWR0103" H 3200 1900 50  0001 C CNN
F 1 "GND" H 3205 1977 50  0000 C CNN
F 2 "" H 3200 2150 50  0001 C CNN
F 3 "" H 3200 2150 50  0001 C CNN
	1    3200 2150
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0104
U 1 1 616EF66D
P 6200 850
F 0 "#PWR0104" H 6200 700 50  0001 C CNN
F 1 "+5V" H 6215 1023 50  0000 C CNN
F 2 "" H 6200 850 50  0001 C CNN
F 3 "" H 6200 850 50  0001 C CNN
	1    6200 850 
	1    0    0    -1  
$EndComp
$Comp
L MySymbols:PTS526-tactile-button U2
U 1 1 616EFDB3
P 4550 3650
F 0 "U2" H 4550 3965 50  0000 C CNN
F 1 "PTS526-tactile-button" H 4550 3874 50  0000 C CNN
F 2 "MyFootprints:pts526-tactile-button" H 4550 3400 50  0001 C CNN
F 3 "" H 4550 3400 50  0001 C CNN
	1    4550 3650
	1    0    0    -1  
$EndComp
$Comp
L MySymbols:PTS526-tactile-button U3
U 1 1 616F082F
P 4550 4150
F 0 "U3" H 4550 4465 50  0000 C CNN
F 1 "PTS526-tactile-button" H 4550 4374 50  0000 C CNN
F 2 "MyFootprints:pts526-tactile-button" H 4550 3900 50  0001 C CNN
F 3 "" H 4550 3900 50  0001 C CNN
	1    4550 4150
	1    0    0    -1  
$EndComp
$Comp
L MySymbols:I2C_128x64_OLED U9
U 1 1 61706D78
P 2650 900
F 0 "U9" H 2828 1021 50  0000 L CNN
F 1 "I2C_128x64_OLED" H 2828 930 50  0000 L CNN
F 2 "MyFootprints:I2C_128x64_OLED" H 2650 1250 50  0001 C CNN
F 3 "" H 2650 1250 50  0001 C CNN
	1    2650 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 1400 2300 900 
Wire Wire Line
	2300 900  2450 900 
Wire Wire Line
	2450 1000 2400 1000
Wire Wire Line
	2400 1000 2400 1300
$Comp
L power:GND #PWR0105
U 1 1 61709FF3
P 2100 700
F 0 "#PWR0105" H 2100 450 50  0001 C CNN
F 1 "GND" H 2105 527 50  0000 C CNN
F 2 "" H 2100 700 50  0001 C CNN
F 3 "" H 2100 700 50  0001 C CNN
	1    2100 700 
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0106
U 1 1 6170B2B6
P 2250 800
F 0 "#PWR0106" H 2250 650 50  0001 C CNN
F 1 "+5V" H 2265 973 50  0000 C CNN
F 2 "" H 2250 800 50  0001 C CNN
F 3 "" H 2250 800 50  0001 C CNN
	1    2250 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 800  2250 800 
Wire Wire Line
	2100 700  2450 700 
$Comp
L Display_Character:SM420561N U10
U 1 1 6171F3B6
P 2200 5400
F 0 "U10" H 2200 6067 50  0000 C CNN
F 1 "5611AH" H 2200 5976 50  0000 C CNN
F 2 "Display_7Segment:7SegmentLED_LTS6760_LTS6780" H 2250 4800 50  0001 C CNN
F 3 "http://www.xlitx.com/datasheet/5611AH.pdf" H 1700 5875 50  0001 L CNN
	1    2200 5400
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:HDSP-7503 U13
U 1 1 61736909
P 7500 5400
F 0 "U13" H 7500 6067 50  0000 C CNN
F 1 "LSHD-7803" H 7500 5976 50  0000 C CNN
F 2 "Display_7Segment:HDSP-A151" H 7500 4850 50  0001 C CNN
F 3 "https://docs.broadcom.com/docs/AV02-2553EN" H 7100 5950 50  0001 C CNN
	1    7500 5400
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:SM420561N U11
U 1 1 61740107
P 4000 5400
F 0 "U11" H 4000 6067 50  0000 C CNN
F 1 "5611AH" H 4000 5976 50  0000 C CNN
F 2 "Display_7Segment:7SegmentLED_LTS6760_LTS6780" H 4050 4800 50  0001 C CNN
F 3 "http://www.xlitx.com/datasheet/5611AH.pdf" H 3500 5875 50  0001 L CNN
	1    4000 5400
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:SM420561N U12
U 1 1 61740A75
P 5700 5400
F 0 "U12" H 5700 6067 50  0000 C CNN
F 1 "5611AH" H 5700 5976 50  0000 C CNN
F 2 "Display_7Segment:7SegmentLED_LTS6760_LTS6780" H 5750 4800 50  0001 C CNN
F 3 "http://www.xlitx.com/datasheet/5611AH.pdf" H 5200 5875 50  0001 L CNN
	1    5700 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 5700 2500 5700
Wire Wire Line
	2500 5800 2500 5700
Connection ~ 2500 5700
Wire Wire Line
	6000 5800 6000 5700
Wire Wire Line
	2750 7050 4300 7050
Wire Wire Line
	4300 5700 4300 5800
Connection ~ 4300 5800
Wire Wire Line
	4300 5800 4300 7050
Wire Wire Line
	2900 6900 6000 6900
Wire Wire Line
	6000 6900 6000 5800
Connection ~ 6000 5800
Wire Wire Line
	3100 6750 7800 6750
Wire Wire Line
	7800 6750 7800 5800
Wire Wire Line
	7800 5700 7800 5800
Connection ~ 7800 5800
Wire Wire Line
	1900 5700 1250 5700
Wire Wire Line
	1250 5700 1250 6500
Wire Wire Line
	1250 6500 2900 6500
Connection ~ 2900 6500
Wire Wire Line
	2900 6500 2900 6900
Wire Wire Line
	1900 5500 3700 5500
Wire Wire Line
	5400 5500 6250 5500
Wire Wire Line
	5400 5500 3700 5500
Connection ~ 5400 5500
Connection ~ 3700 5500
Wire Wire Line
	1900 5400 3700 5400
Wire Wire Line
	3700 5400 5400 5400
Connection ~ 3700 5400
Wire Wire Line
	5400 5400 6350 5400
Connection ~ 5400 5400
Wire Wire Line
	1900 5300 3700 5300
Wire Wire Line
	5400 5300 3700 5300
Connection ~ 3700 5300
Wire Wire Line
	5400 5300 6450 5300
Connection ~ 5400 5300
Wire Wire Line
	7200 5200 6550 5200
Wire Wire Line
	5400 5200 3700 5200
Connection ~ 5400 5200
Wire Wire Line
	3700 5200 1900 5200
Connection ~ 3700 5200
Wire Wire Line
	1900 5100 3700 5100
Wire Wire Line
	5400 5100 3700 5100
Connection ~ 3700 5100
Wire Wire Line
	7200 5100 6650 5100
Connection ~ 5400 5100
Wire Wire Line
	3700 5700 2900 5700
Connection ~ 2900 5700
Wire Wire Line
	2900 5700 2900 6500
Wire Wire Line
	3700 5600 3100 5600
Connection ~ 3100 5600
Wire Wire Line
	2600 5700 2600 6000
Wire Wire Line
	2600 6000 5000 6000
Wire Wire Line
	5000 6000 5000 5700
Wire Wire Line
	5000 5700 5400 5700
Connection ~ 2600 5700
Wire Wire Line
	5400 5600 4300 5600
Wire Wire Line
	4300 5600 4300 5700
Connection ~ 4300 5700
Wire Wire Line
	5000 6000 6800 6000
Wire Wire Line
	6800 6000 6800 5700
Wire Wire Line
	6800 5700 7200 5700
Connection ~ 5000 6000
Wire Wire Line
	5400 5600 7200 5600
Connection ~ 5400 5600
Wire Wire Line
	3100 5600 3100 6750
Wire Wire Line
	1900 5600 3100 5600
Wire Wire Line
	6200 1800 6250 1800
Wire Wire Line
	6250 1800 6250 5500
Connection ~ 6250 5500
Wire Wire Line
	6250 5500 7200 5500
Wire Wire Line
	6200 1700 6350 1700
Wire Wire Line
	6350 1700 6350 5400
Connection ~ 6350 5400
Wire Wire Line
	6350 5400 7200 5400
Wire Wire Line
	6200 1600 6450 1600
Wire Wire Line
	6450 1600 6450 5300
Connection ~ 6450 5300
Wire Wire Line
	6450 5300 7200 5300
Wire Wire Line
	6200 1500 6550 1500
Wire Wire Line
	6550 1500 6550 5200
Connection ~ 6550 5200
Wire Wire Line
	6550 5200 5400 5200
Wire Wire Line
	6200 1400 6650 1400
Wire Wire Line
	6650 1400 6650 5100
Connection ~ 6650 5100
Wire Wire Line
	6650 5100 5400 5100
$Comp
L 2021-10-18_05-36-44:MAX6959BAEE+ U4
U 1 1 6178E201
P 3200 1300
F 0 "U4" H 4700 1793 60  0000 C CNN
F 1 "MAX6959BAEE+" H 4700 1687 60  0000 C CNN
F 2 "MyFootprints:MAX6959BAEE&plus_" H 4700 1540 60  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX6958-MAX6959.pdf" H 4700 1581 60  0000 C CNN
	1    3200 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 2150 3200 2000
Wire Wire Line
	2300 1400 3200 1400
Connection ~ 2300 1400
Wire Wire Line
	2600 1600 3200 1600
Wire Wire Line
	2750 1700 3200 1700
Wire Wire Line
	3200 1900 3100 1900
Wire Wire Line
	3200 1800 2900 1800
Wire Wire Line
	1500 1700 2550 1700
Wire Wire Line
	2550 1700 2550 1500
Wire Wire Line
	2400 1300 3200 1300
Connection ~ 2400 1300
Wire Wire Line
	2400 1300 2400 1500
$Comp
L Device:R R3
U 1 1 617CA66A
P 2950 1350
F 0 "R3" H 3020 1396 50  0000 L CNN
F 1 "4.7k" H 3020 1305 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 2880 1350 50  0001 C CNN
F 3 "~" H 2950 1350 50  0001 C CNN
	1    2950 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 1500 2950 1500
Wire Wire Line
	3200 1500 2950 1500
Connection ~ 2950 1500
Wire Wire Line
	2000 1150 2950 1150
Wire Wire Line
	2950 1150 2950 1200
Connection ~ 2000 1150
Wire Wire Line
	2000 1150 2000 1200
$Comp
L Device:R R4
U 1 1 617D73B4
P 6900 1900
F 0 "R4" H 6970 1946 50  0000 L CNN
F 1 "39k" H 6970 1855 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 6830 1900 50  0001 C CNN
F 3 "~" H 6900 1900 50  0001 C CNN
	1    6900 1900
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R5
U 1 1 617D9E3F
P 6900 2000
F 0 "R5" H 6970 2046 50  0000 L CNN
F 1 "39k" H 6970 1955 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 6830 2000 50  0001 C CNN
F 3 "~" H 6900 2000 50  0001 C CNN
	1    6900 2000
	0    1    1    0   
$EndComp
Wire Wire Line
	6200 2000 6750 2000
Wire Wire Line
	6200 1900 6750 1900
Wire Wire Line
	7050 1900 7250 1900
Wire Wire Line
	7250 1900 7250 550 
Wire Wire Line
	7250 550  9800 550 
Wire Wire Line
	10600 550  10600 950 
Wire Wire Line
	9800 950  9800 550 
Connection ~ 9800 550 
Wire Wire Line
	9800 550  10600 550 
Wire Wire Line
	7050 2000 7550 2000
Wire Wire Line
	7550 2000 7550 950 
Wire Wire Line
	7550 950  8200 950 
Wire Wire Line
	8200 950  9000 950 
Connection ~ 8200 950 
$Comp
L power:GND #PWR0107
U 1 1 61832C82
P 6550 1100
F 0 "#PWR0107" H 6550 850 50  0001 C CNN
F 1 "GND" H 6555 927 50  0000 C CNN
F 2 "" H 6550 1100 50  0001 C CNN
F 3 "" H 6550 1100 50  0001 C CNN
	1    6550 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 1000 6200 1300
Wire Wire Line
	6200 850  6200 1000
Connection ~ 6200 1000
Wire Wire Line
	6550 1100 6550 1000
Wire Wire Line
	6550 1000 6500 1000
Wire Wire Line
	4300 2650 2600 2650
Wire Wire Line
	4300 2800 2750 2800
Wire Wire Line
	4300 2950 2900 2950
Wire Wire Line
	4300 3100 3100 3100
Wire Wire Line
	4400 3600 2750 3600
Connection ~ 2750 3600
Wire Wire Line
	2750 3600 2750 7050
Wire Wire Line
	4300 3250 2600 3250
Wire Wire Line
	4400 4100 2900 4100
Connection ~ 2900 4100
Wire Wire Line
	2900 4100 2900 5700
Wire Wire Line
	7050 2650 4800 2650
Connection ~ 2600 2650
Connection ~ 2600 3250
Wire Wire Line
	2600 3250 2600 5700
Connection ~ 2750 2800
Wire Wire Line
	2750 2800 2750 3600
Connection ~ 2900 2950
Wire Wire Line
	2900 2950 2900 4100
Connection ~ 3100 3100
Wire Wire Line
	3100 3100 3100 5600
Wire Wire Line
	3100 1900 3100 3100
Wire Wire Line
	2900 1800 2900 2950
Wire Wire Line
	2600 1600 2600 2650
Wire Wire Line
	2750 1700 2750 2800
Wire Wire Line
	2600 2650 2600 3250
Wire Wire Line
	4800 2800 8200 2800
Wire Wire Line
	8200 2800 8200 2750
Wire Wire Line
	8000 2750 7050 2750
Wire Wire Line
	7050 2750 7050 2650
Wire Wire Line
	4800 2950 8800 2950
Wire Wire Line
	8800 2950 8800 2750
Wire Wire Line
	4800 3100 9000 3100
Wire Wire Line
	9000 3100 9000 2750
Wire Wire Line
	4800 3250 9600 3250
Wire Wire Line
	9600 3250 9600 2750
Wire Wire Line
	10400 3600 10400 2750
Wire Wire Line
	4700 3600 10400 3600
Wire Wire Line
	10600 4100 10600 2750
Wire Wire Line
	4700 4100 10600 4100
$EndSCHEMATC
