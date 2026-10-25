void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

#include <LiquidCrystal.h>

// TMP36 temperature sensor connected to A0
const int temperaturePin = A0;

// LED pin assignments
const int greenLED = 8;
const int yellowLED = 9;
const int redLED = 10;

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Initialize LCD
  lcd.begin(16, 2);

  // Configure LEDs as outputs
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  // Initially turn all LEDs OFF
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);

  // Startup message
  lcd.setCursor(0, 0);
  lcd.print("SMART TEMP");
  lcd.setCursor(0, 1);
  lcd.print("AUTO CONTROL");

  Serial.println("Smart Temperature Control System");

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
  Serial.print(temperature, 2);
  Serial.print(" C | ");

  // Clear LCD and display temperature
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TEMP:");
  lcd.print(temperature, 1);
  lcd.print(" C");

  // AUTOMATIC TEMPERATURE CONTROL
  if (temperature < 25.0)
  {
    // NORMAL: Green LED ON
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);

    Serial.println("Status: NORMAL | Green LED ON");

    lcd.setCursor(0, 1);
    lcd.print("STATUS: NORMAL");
  }
  else if (temperature <= 35.0)
  {
    // WARNING: Yellow LED ON
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);

    Serial.println("Status: WARNING | Yellow LED ON");

    lcd.setCursor(0, 1);
    lcd.print("STATUS: WARNING");
  }
  else
  {
    // CRITICAL: Red LED ON
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);

    Serial.println("Status: CRITICAL | Red LED ON");

    lcd.setCursor(0, 1);
    lcd.print("STATUS: ALERT!");
  }

  // Take a new reading every second
  delay(1000);
}
