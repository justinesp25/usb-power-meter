#include <Wire.h>              // I2C (SDA/SCL) communication
#include <Adafruit_GFX.h>      // drawing text and shapes
#include <Adafruit_SSD1306.h>  // the OLED driver

Adafruit_SSD1306 display(128, 64, &Wire, -1); // 128x64 screen, no reset pin
const int TEMP_PIN = 34;                     // MCP9701 output

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);  // SDA = P21, SCL = P22
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // 0x3C = OLED's I2C address
    Serial.println("OLED not found - check wiring");
    while (true);      // stop here if the screen isn't detected
  }
}

void loop() {
  int mV = analogReadMilliVolts(TEMP_PIN);
  float tempC = (mV - 400) / 19.5;     // MCP9701 formula
  float tempF = tempC * 9 / 5 + 32;

  display.clearDisplay();              // wipe the last frame
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Temperature");
  display.setTextSize(2);              // bigger text for the numbers
  display.setCursor(0, 20);
  display.print(tempC, 1); display.println(" C");
  display.print(tempF, 1); display.println(" F");
  display.display();                   // push the frame to the screen

  Serial.println(tempC);
  delay(1000);
}
