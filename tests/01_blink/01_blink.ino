**Step 1: ESP32 LED Blink**

```cpp
// Anything after // is a comment. The ESP32 ignores it.

const int LED_PIN = 26;
// Named number for the pin the LED is on (P26).
// const = can't change. Change 26 here and it updates everywhere.

void setup() {
// Runs ONE time when the ESP32 powers on or resets.
  pinMode(LED_PIN, OUTPUT);
  // Pin 26 pushes voltage OUT (INPUT would read voltage in).
}

void loop() {
// Repeats forever after setup().
  digitalWrite(LED_PIN, HIGH); // 3.3 V out, LED on
  delay(500);                  // wait 500 ms (0.5 s)
  digitalWrite(LED_PIN, LOW);  // 0 V, LED off
  delay(500);                  // wait, then loop again
}
```

**Circuit:** P26 → 330 Ω resistor → LED anode (long leg) → LED cathode (short leg, flat edge) → GND
**Resistor math:** (3.3 V − 2.1 V) ÷ 330 Ω ≈ 3.6 mA
**Lower delay = faster blink.** Very low (about 5 ms) looks steady and dim, which is PWM.
