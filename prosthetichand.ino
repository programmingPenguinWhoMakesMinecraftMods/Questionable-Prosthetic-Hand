#include <Servo.h>

const int NUM_CHANNELS = 5;

// Signal Input (Sensors) & Output (Servos) Pins
const int ldrPins[NUM_CHANNELS]   = {A0, A1, A2, A3, A4};
const int servoPins[NUM_CHANNELS] = {2, 3, 4, 5, 6};

// Set light activation threshold for each sensor (0 to 1023)
// Adjust individual numbers based on Serial Monitor feedback
int lightThresholds[NUM_CHANNELS] = {500, 500, 500, 500, 500};

Servo servos[NUM_CHANNELS];

void setup() {
  Serial.begin(9600); // Initialize Serial Monitor for tuning

  for (int i = 0; i < NUM_CHANNELS; i++) {
    servos[i].attach(servoPins[i]);
    servos[i].write(0); // Set home position to 0 degrees
  }
}

void loop() {
  for (int i = 0; i < NUM_CHANNELS; i++) {
    int ldrValue = analogRead(ldrPins[i]);

    // Print values to Serial Monitor for calibration
    Serial.print("Ch");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(ldrValue);
    Serial.print("\t");

    // Action rule: Light detected -> Move to 90 degrees; Darkness -> Return to 0
    if (ldrValue > lightThresholds[i]) {
      servos[i].write(180);
    } else {
      servos[i].write(0);
    }
  }

  Serial.println(); // New line for monitor formatting
  delay(100);       // Small stability delay
}
