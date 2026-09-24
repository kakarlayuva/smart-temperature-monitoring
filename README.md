# Smart Temperature Monitoring and Alert System Using Arduino UNO

A simple embedded-systems simulation project developed using **Arduino UNO** and **Tinkercad**. The system continuously monitors temperature using an **LM35 temperature sensor**, displays the temperature on a **16x2 LCD**, and activates an alert when the temperature exceeds a predefined threshold.

## Project Overview

The system is designed to demonstrate basic sensor interfacing, analog data acquisition, LCD display, and threshold-based alert generation.

### Main Functions
- Reads temperature from the LM35 sensor.
- Converts the analog sensor output into temperature in °C.
- Displays the current temperature on a 16x2 LCD.
- Activates an LED and buzzer when the temperature crosses the configured limit.
- Runs continuously on an Arduino UNO.

## Components

| Component | Purpose |
|---|---|
| Arduino UNO R3 | Main microcontroller |
| LM35 | Temperature sensing |
| 16x2 LCD | Temperature display |
| Buzzer | Audible alert |
| LED | Visual alert |
| 220 Ω resistor | LED current limiting |
| 10 kΩ potentiometer | LCD contrast control |
| Breadboard & jumper wires | Circuit connections |

## Circuit Connections

### LM35
| LM35 Pin | Arduino UNO |
|---|---|
| VCC | 5V |
| OUT | A0 |
| GND | GND |

### 16x2 LCD (4-bit mode)
| LCD Pin | Arduino UNO |
|---|---|
| VSS | GND |
| VDD | 5V |
| V0 | Potentiometer wiper |
| RS | D12 |
| RW | GND |
| E | D11 |
| D4 | D5 |
| D5 | D4 |
| D6 | D3 |
| D7 | D2 |
| A (LED+) | 5V through suitable resistor |
| K (LED-) | GND |

### Alert Devices
| Device | Arduino UNO |
|---|---|
| Buzzer + | D8 |
| Buzzer - | GND |
| Alert LED anode | D9 through 220 Ω |
| Alert LED cathode | GND |

## Operating Principle

1. The LM35 produces an analog voltage proportional to temperature.
2. Arduino UNO reads this voltage through analog pin A0.
3. The ADC converts the sensor voltage into a digital value.
4. The program converts the ADC reading into temperature in °C.
5. The measured temperature is shown on the LCD.
6. If the temperature is greater than or equal to the alert threshold, the buzzer and LED are activated.
7. Otherwise, the alert devices remain OFF.

## Default Alert Threshold

The example code uses **30 °C** as the alert threshold. Change `TEMP_THRESHOLD` in the source code if a different threshold is required.

## Source Code

The Arduino source code is available in [`src/smart_temperature_monitor.ino`](src/smart_temperature_monitor.ino).

## Simulation

The project can be simulated in **Tinkercad Circuits** by recreating the circuit using the connections listed above and pasting the source code into the Arduino code editor.

## Project Structure

```text
smart-temperature-monitoring/
├── README.md
├── LICENSE
├── .gitignore
├── src/
│   └── smart_temperature_monitor.ino
├── docs/
│   └── project_notes.md
└── images/
    └── README.md
```

## Applications

- Room temperature monitoring
- Electronic equipment temperature warning
- Laboratory temperature indication
- Small-scale industrial monitoring demonstrations
- Educational embedded-systems projects

## Future Enhancements

- Add an ESP32/Wi-Fi module for remote monitoring.
- Store temperature readings in an SD card or cloud database.
- Add a temperature history graph.
- Replace the threshold alert with multiple temperature levels.
- Add a mobile/web dashboard.

## License

This project is provided for educational and academic use.
