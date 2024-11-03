# Digital Multimeter

## Overview
This project demonstrates a Digital Multimeter using an AVR microcontroller (ATMEGA32A) interfacing with an LCD to display measurement values and a Keypad to select the active mode: Ammeter (Up to 200mA), Voltmeter (Up to 50V), or Ohmmeter. The circuit processes input through a differential Op-Amp and then a range selector, also utilizing an Op-Amp. Finally, the processed signal is sent to the AVR's ADC pins, which allows the measurement value to be displayed on the LCD.
  
## Software Used
- **Proteus:** Schematic Design
- **Microchip Studio:** Coding
- **EasyEDA:** PCB Design

## Setup and Installation
- Install Proteus.
- Install Microchip Studio(Optional: if you want to edit the code).
- Clone this repository: 
  ```bash
  git clone https://github.com/mo2menwael/Digital-Multimeter.git
  ```
- Open "Digital Multimeter.pdsprj". You can find it in Schematic folder.
- Double click on the AVR and in Program File option, choose "Digital Multimeter.hex". You can find it in Code/Digital Multimeter/Debug folder.
- Run the simulation.
