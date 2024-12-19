#include <BleKeyboard.h> // BLE Keyboard library

BleKeyboard bleKeyboard("ESP32 Steering", "Eshal's Setup", 100); // BLE Keyboard setup
int potentiometerPin = 34; // Connect potentiometer to GPIO34 (ADC1_CH6)

int minValue = 0;     // Minimum potentiometer value
int maxValue = 4095;  // Maximum potentiometer value
int neutralValue = 2048; // Neutral position (centered)

void setup() {
  Serial.begin(115200);
  pinMode(potentiometerPin, INPUT);

  Serial.println("Starting BLE Keyboard...");
  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) {
    int potValue = analogRead(potentiometerPin); // Read potentiometer value
    Serial.print("Potentiometer Value: ");
    Serial.println(potValue);

    // Determine steering action based on potentiometer value
    if (potValue < (neutralValue - 100)) {
      // Steering Left
      int intensity = map(potValue, minValue, neutralValue - 100, 100, 10); // Map to intensity
      Serial.print("Turning Left with Intensity: ");
      Serial.println(intensity);
      bleKeyboard.press(KEY_LEFT_ARROW);
      delay(intensity); // Hold key based on intensity
      bleKeyboard.releaseAll();
    } else if (potValue > (neutralValue + 100)) {
      // Steering Right
      int intensity = map(potValue, neutralValue + 100, maxValue, 10, 100); // Map to intensity
      Serial.print("Turning Right with Intensity: ");
      Serial.println(intensity);
      bleKeyboard.press(KEY_RIGHT_ARROW);
      delay(intensity); // Hold key based on intensity
      bleKeyboard.releaseAll();
    } else {
      // Neutral (centered) - release keys
      Serial.println("Neutral Position");
      bleKeyboard.releaseAll();
    }

    delay(10); // Minimal delay for smooth updates
  }
}
