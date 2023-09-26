# Maturaarbeit-8-bit-Computer
This repository will contain files of any relevance to my Matura project. 

The Arduino code used for the control logic and output register is in these files. The programming into the EEPROMs was done with an Arduino Nano and a makeshift shift register for outputting the address of the data. The data was directly sent to the EEPROM by the Arduino Nano (see photo in Arduino EEPROM file set).

The Arduino code for the output register simply has 11 functions for 10 decimal numbers and nothing, which are written into the corresponding address of the binary number. There are a total of three files with Arduino code for the output register, being named eepromcode1s.ino, eepromcode10s.ino and eepromcode100sv2.ino showing the code for the 1s, 10s and 100s place value respectively.

The Arduino code for the control logic have different functions depending on what microinstruction they are representing. They are programmed into the EEPROMs in the same way done for the output register. There are a total of three files with Arduino code for the output register, being named eepromlogic1.ino, eepromlogic2.ino and eepromlogic3.ino showing the code for the leftmost EEPROM (first 8 control signals), middle EEPROM (9th to 16th control signals) and the rightmost EEPROM (last 5 control signals).

Furthermore, there is a labeled picture of the breadboard circuit used to program the EEPROM with the Arduino Nano with the title eeprom2.JPG.


The Logisim file is a prototype of my simulated 8-bit computer. This file can be opened with the latest version of Logisim available on http://www.cburch.com/logisim/ 
The file with my simulated 8-bit computer is named 8-bit computerv2.circ. It can be opened with Logisim and then programmed in the bottom right of the circuit using the shown controls to do all instructions except the instant instruction.
