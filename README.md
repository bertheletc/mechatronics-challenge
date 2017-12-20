# Mechatronics Challenge

## Goal
Design a prototype can output GPS coordinates and accelerometer data via serial USB.

## Instructions
1. Clone this repo to your computer and then push to your own Github account. Don't fork it.
```sh
$ git clone git@github.com:voyage/mechatronics-challenge.git
```
2. Put your deliverables for **Part 1** in `electrical` and `src` folders and **Part 2** in the `mechanical` folder.
3. Once you've completed the challenge, please send an e-mail to alan@voyage.auto with the link to your Github repo containing the solution.

### Part 1: Electrical/Coding
At Voyage, we are always trying to improve sensor data quality.  The objective of this challenge is to build a module that can output GPS coordinates and accelerometer data.  Assume clean 5V, 3A power source is available.     

Using a Particle Photon microcontroller [https://docs.particle.io/datasheets/photon-(wifi)/photon-datasheet/#pin-and-button-definition](https://docs.particle.io/datasheets/photon-(wifi)/photon-datasheet/#pin-and-button-definition) and a Carloop GPS [https://store.carloop.io/products/carloop-gps?variant=4846877966372](https://store.carloop.io/products/carloop-gps?variant=4846877966372) provide the following deliverables:

- a very simple wiring schematic showing how the GPS, accelerometer, and microcontroller would be wired together to be functional.
- a program in C++ that sends GPS coordinates and accelerometer data via serial USB (heavy use of existing libraries is recommended).

### Part 2: Mechanical
Design simple box to house all components. No constraints on size.

## Remarks
If you prefer to use other microcontroller, accelerometer or GPS unit, feel free to do so.
