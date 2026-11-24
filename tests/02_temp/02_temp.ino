const int TEMP_PIN = 34;  // sensor output goes to P34

void setup() {
  Serial.begin(115200);   // open a text link to the laptop
}

void loop() {
  int mV = analogReadMilliVolts(TEMP_PIN); // read sensor voltage
  float tempC = (mV - 400) / 19.5;         // MCP9701: 400 mV = 0°C, +19.5 mV per °C
  float tempF = tempC * 9 / 5 + 32;        // convert to °F
  Serial.print(mV); Serial.print(" mV  |  ");
  Serial.print(tempC); Serial.print(" C  |  ");
  Serial.print(tempF); Serial.println(" F");
  delay(1000);                             // once per second
}
