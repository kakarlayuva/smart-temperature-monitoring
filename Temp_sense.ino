#include <LiquidCrystal.h>
	// TMP36 connected to A0
const int temperaturePin = A0;
// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
	void setup()
{
  // Initialize Serial Monitor
  Serial.begin(9600);
  // Initialize LCD
  lcd.begin(16, 2);
  // Startup message
  lcd.setCursor(0, 0);
  lcd.print("SMART TEMP");
  lcd.setCursor(0, 1);
  lcd.print("MONITOR");
  Serial.println("Smart Temperature Monitor");
  delay(2000);
  lcd.clear();
}
void loop()
{
  // Read TMP36 analog value
  int sensorValue = analogRead(temperaturePin);
  // Convert ADC reading into voltage
  float voltage = sensorValue * (5.0 / 1023.0);
  // Convert voltage into temperature in Celsius
  float temperature = (voltage - 0.5) * 100.0;
  // Display temperature in Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C | ");
  lcd.clear();
  if (temperature < 25.0)
  {
    // Normal temperature
    Serial.println("Status: NORMAL");
    lcd.setCursor(0, 0);
    lcd.print("TEMP:");
    lcd.print(temperature);
    lcd.print(" C");
    lcd.setCursor(0, 1);
    lcd.print("STATUS: NORMAL");
  }
  else if (temperature <= 35.0)
  {
    // Warning temperature
    Serial.println("Status: WARNING");
		    lcd.setCursor(0, 0);
    lcd.print("TEMP:");
    lcd.print(temperature);
    lcd.print(" C");
    lcd.setCursor(0, 1);
    lcd.print("STATUS: WARNING");
  }
  else
  {
    // Critical temperature
    Serial.println("Status: CRITICAL");
    lcd.setCursor(0, 0);
    lcd.print("TEMP:");
    lcd.print(temperature);
    lcd.print(" C");
    lcd.setCursor(0, 1);
    lcd.print("STATUS: ALERT!");
  }
	// Take a new reading every 1 second
  delay(1000);
}
