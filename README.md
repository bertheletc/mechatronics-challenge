# Mechatronics Challenge

### Goal
Design a prototype can output GPS coordinates and accelerometer data via serial USB.

## Instructions
1. Fork this repo
2. Please put your deliverables for **Part 1** in `electrical` and `src` folders and **Part 2** in the `mechanical` folder.
3. Once you've completed the challenge, please send an e-mail to alan@voyage.auto with the link your Github repo.

### Part 1: Electrical/Coding
At Voyage, we are always trying to improve sensor data quality.  The objective of this challenge is to build a module that can output GPS coordinates and accelerometer data.  Assume clean 5V, 3A power source is provided and available.    

Using a Particle Photon microcontroller [https://docs.particle.io/datasheets/photon-(wifi)/photon-datasheet/#pin-and-button-definition](https://docs.particle.io/datasheets/photon-(wifi)/photon-datasheet/#pin-and-button-definition) and a Carloop GPS [https://store.carloop.io/products/carloop-gps?variant=4846877966372](https://store.carloop.io/products/carloop-gps?variant=4846877966372) provide the following deliverables:

- a very simple wiring schematic showing how the GPS, accelerometer, and microcontroller can be wired together.
- a program in C++ that sends GPS coordinates and accelerometer data via serial USB (heavy use of existing libraries is recommended) 

### Part 2: Mechanical
Design simple box to house all components. No constraints on size.

### Remarks
If you'd prefer to use other microcontroller, accelerometer or GPS unit, feel free to do so.
