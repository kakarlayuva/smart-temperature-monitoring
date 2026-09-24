#include <LiquidCrystal.h>

// ---------------- Pin Definitions ----------------
const int LM35_PIN = A0;
const int BUZZER_PIN = 8;
const int ALERT_LED_PIN = 9;

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Temperature at or above this value triggers the alert.
const float TEMP_THRESHOLD = 30.0;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(ALERT_LED_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(ALERT_LED_PIN, LOW);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp Monitor");
  delay(1500);
  lcd.clear();
}

void loop() {
  // Read the LM35 analog output.
  int adcValue = analogRead(LM35_PIN);

  // Arduino UNO uses a 10-bit ADC and a 5 V reference by default.
  float voltage = adcValue * (5.0 / 1023.0);

  // LM35 output is approximately 10 mV per degree Celsius.
  float temperatureC = voltage * 100.0;

  // Display temperature.
  lcd.setCursor(0, 0);
  lcd.print("Temperature:   ");
  lcd.setCursor(0, 1);
  lcd.print(temperatureC, 1);
  lcd.print((char)223); // Degree symbol
  lcd.print("C        ");

  // Threshold-based alert.
  if (temperatureC >= TEMP_THRESHOLD) {
    digitalWrite(ALERT_LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000);
  } else {
    digitalWrite(ALERT_LED_PIN, LOW);
    noTone(BUZZER_PIN);
  }

  delay(500);
}
