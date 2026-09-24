# Project Notes

## Title
Smart Temperature Monitoring and Alert System Using Arduino UNO

## Objective
To design and simulate a basic embedded system that measures temperature, displays the measured value, and generates a visual and audible warning when the temperature exceeds a predefined threshold.

## Sensor
The LM35 is an analog temperature sensor whose output voltage changes approximately linearly with temperature. In the common 5 V Arduino configuration, the example program uses approximately 10 mV/°C.

## Arduino ADC
The Arduino UNO's ATmega328P provides a 10-bit ADC. With the default 5 V reference, an ADC reading from 0 to 1023 is converted to an input voltage using:

Voltage = ADC Reading × 5.0 / 1023

For the LM35 approximation used in this project:

Temperature (°C) = Voltage × 100

## Alert Logic
- Temperature < 30 °C: LED OFF, buzzer OFF.
- Temperature >= 30 °C: LED ON, buzzer ON.

## Expected Demonstration
During the Tinkercad simulation, changing the LM35 temperature should change the displayed temperature. When the measured value reaches the threshold, the alert LED should turn ON and the buzzer should sound.

## Academic Scope
This project demonstrates:
- Analog sensor interfacing
- ADC-based measurement
- LCD interfacing
- Digital output control
- Threshold-based embedded control
- Simulation using Tinkercad
