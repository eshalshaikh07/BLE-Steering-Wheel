# BLE Steering Wheel Simulation with ESP32

This project simulates a steering wheel using an ESP32 microcontroller and a potentiometer. By rotating the potentiometer, you can simulate left or right keypresses (e.g., arrow keys) that can be used to control games or applications requiring keyboard input. The ESP32 communicates as a Bluetooth Low Energy (BLE) keyboard, making it a versatile solution for gaming and other applications.

## 📋 Description
The ESP32 reads the position of a potentiometer connected to its analog pin. Depending on the value, the program simulates:

- Left steering by pressing the Left Arrow key when the potentiometer moves left.
- Right steering by pressing the Right Arrow key when the potentiometer moves right.
- A neutral position when the potentiometer is centered, releasing all keys.
- The intensity of the turn is dynamically mapped to the potentiometer's rotation, allowing for smooth and realistic steering simulation.

## 📌 Pin Configuration

| Pin     | Description                               |
|---------|-------------------------------------------|
| GPIO 34 | Connected to the potentiometer output (signal pin). |
| GND     | Connected to the potentiometer ground (GND). |
| 3.3V    | Connected to the potentiometer power (VCC). |

## 🔧 Setup
1. **Connect the potentiometer** to the ESP32 as described in the pin configuration above.
2. **Upload the code** to the ESP32 using the Arduino IDE. Ensure the **BLE Keyboard** library is installed.
3. **Pair the ESP32** with your computer or gaming device as a Bluetooth keyboard.

## 🎯 Motive
The main goal of this project is to create a cost-effective and compact steering wheel simulation for gaming or testing applications. It leverages the ESP32's BLE capabilities to interact wirelessly with devices, eliminating the need for additional hardware or software.

## 💡 Applications
- **Gaming**: Use as a steering wheel for car simulation games.
- **Accessibility Tools**: Assist users who require alternative input methods for keyboard controls.
- **DIY Projects**: Experiment with BLE capabilities and analog input mapping.
- **Prototyping**: Test dynamic input-to-action systems with adjustable sensitivity.

## 🛠 How It Works
- The potentiometer's analog value (0-4095) is read via the ESP32's ADC (Analog-to-Digital Converter).
- A neutral zone (center position) is defined to avoid unintentional key presses.
- Depending on the potentiometer value:
  - Values below the neutral zone simulate left steering with increasing intensity.
  - Values above the neutral zone simulate right steering with increasing intensity.
  - Values within the neutral zone release all keys, simulating no input.
- The ESP32 uses the **BLE Keyboard** library to send corresponding keypresses (e.g., Left Arrow and Right Arrow) to the paired device.

## ⚙ Code Highlights
- **Dynamic Mapping**: The potentiometer value is mapped to an intensity value that determines the duration of the keypress for smoother turns.
- **BLE Connectivity**: The ESP32 acts as a Bluetooth keyboard, sending key events directly to the connected device.
- **Serial Monitoring**: Real-time potentiometer values and actions are logged to the serial monitor for debugging and calibration.

## 🚀 Future Improvements
- Add support for more complex steering controls (e.g., braking or acceleration).
- Implement configurable sensitivity or thresholds through a companion app or UI.
- Integrate with advanced gaming setups for enhanced realism.

---

Enjoy building your custom BLE steering wheel! 🛞✨
