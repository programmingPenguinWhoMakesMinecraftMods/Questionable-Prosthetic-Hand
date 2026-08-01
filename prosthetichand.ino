#include <Servo.h>

const int NUM_CHANNELS = 5; //Ring and pinky can be combined to reduce the amount of hardware needed. Reduce number of channels to 4 

// Signal Input (Sensors) & Output (Servos) Pins. A0 Controls Pin 2, A1 Controls Pin 3, so on and so forth. Adjust accordingly 
const int ldrPins[NUM_CHANNELS]   = {A0, A1, A2, A3, A4}; 
const int servoPins[NUM_CHANNELS] = {2, 3, 4, 5, 6}; 

// Set light activation threshold for each sensor (0 to 1023)
// Adjust individual numbers based on Serial Monitor feedback. Set at 500 as reference
int lightThresholds[NUM_CHANNELS] = {500, 500, 500, 500, 500};

Servo servos[NUM_CHANNELS];

void setup() {
  Serial.begin(9600); // Initialize Serial Monitor for tuning

  for (int i = 0; i < NUM_CHANNELS; i++) {
    servos[i].attach(servoPins[i]);
    servos[i].write(0); // Set home position to 0 degrees
  }
}

//Create separate loops if acutated position of servo motors differ considerably. Adjusting amount of string slack can also work
void loop() {
  for (int i = 0; i < NUM_CHANNELS; i++) {
    int ldrValue = analogRead(ldrPins[i]);

    // Print values to Serial Monitor for calibration. Based on the values, set light thresholds accordingly. You can remove it after calibration
    Serial.print("Ch");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(ldrValue);
    Serial.print("\t");

    // Action rule: Light detected -> Move to 180 degrees; Darkness -> Return to 0
    if (ldrValue > lightThresholds[i]) {
      servos[i].write(180); //Sets actuated position of the servo motor, typically 180 degrees works best. Test different values and set accordingly
    } else {
      servos[i].write(0); //Sets home position of the servo motor, typically 0 degrees works best
    }
  }

  Serial.println(); // New line for monitor formatting
  delay(100);       // Small stability delay
}
