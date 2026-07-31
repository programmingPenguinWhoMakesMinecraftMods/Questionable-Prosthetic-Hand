# Questionable-Prosthetic-Hand (Aid)
Simple, Affordable Prosthetic Aid

Ever injured your hand, especially your fingers? Your fingers become incredibly stiff and difficult to move - very frustrating, and a common issue for my injury-prone personality. But notice one thing: your fingers can still move slightly... so why not take advantage of that and use it to trigger a motor to complete the full motion! Genius, I know. And thus, I began my endeavor. And since I'm a high school student, it's on a dirt cheap budget. Bear with me... it's not pretty but it's a proof of concept! Further development of this idea can create a very affordable prosthetic hand which can be used by anyone experiencing permanent or temporary difficulties with hand movement. 

# Basic Principle
The design for this prosthetic aid revolves around a simple sensor you've probably glossed over in physics - the humble Light Dependent Resistor (LDR). It's usually difficult for people to conceptualize why it would be necessary, but they're dirt-cheap and take advantage of a stimulus all around us - light! The design takes advantage of the fact that the user still retains limited movement, which allows the user to move their fingers to change the amount of light that can strike the sensor! 

# Main Circuit Design
This will be divided into three segments:
- The control and power segment: This consists of the development board, breadboard and power delivery
- The detection segment: This consists of an LDR and a high resistance resistor set up in a voltage divider circuit - this allows the variability in the resistance of the LDR to be quantified properly. It is connected to the control and power segment via an analogue pin (and necessary power)
- The actuation segment: This consists of a servo motor, connected to a string, which connects to an individual finger. It is connected to the control and power segment via a PWM pin (and necessary power)

# Basic Flow of Design
The basic flow of the design is very simple as well, and minor movements of the fingers can dictate the contraction and relaxation of each individual finger
      
      [Finger Covers Sensor] --(Light hitting sensor decreases]--> [Detection Segment] --(Detects Decreased Light)--> [Control and Power Segment] --(Triggers Servo Motors)--> [Actuation Segment] --(Servo Motors pull string)--> [Finger Fully Contracted]

      
      [Finger Uncovers Sensor] --(Light hitting sensor increases]--> [Detection Segment] --(Detects Increased Light)--> [Control and Power Segment] --(Triggers Servo Motors)--> [Actuation Segment] --(Servo Motors relax string)--> [Finger Fully Relaxed]

# Parts Selection
Now, we want it to be quite affordable, so common off the shelf components are preferred
- Control board: Arduino UNO - it's a tried and tested platform, and readily available. While the ESP32 platform offers more features (like Bluetooth and WiFi), its 3.3V platform is not as common as the UNO's 5V platform, and such buck converters are not necessary (a cost saving!). For this, it cost me **939BDT**
- Actuators: The SG90 servo motors are easily obtainable no matter where you are, and have a lot of documentation. Its operating voltage of 4.8V to 6.0V allows for easy powering through the onboard power output of the Arduino, however because we are using 5 of them (one for each digit on one hand), the maximum current draw requires that we use an external power source for it. For this, it cost me **900BDT** (180BDT per motor)
- Power: The Arduino UNO can provide 5V on its own through its power pins, and can accept a wide range of power inputs. And as the operating voltage for the servo motors are 6V, I've decided to go with a 6V Battery Pack using 4x AA batteries in series. The AA batteries are abundant no matter where you are, and provide a consistent 1.5V (so 4 in series gives 6.0V), and aren't a big fire risk, unlike 18650s - and believe me, you don't want a fire next to your hand. For this, it cost me **95BDT** (55BDT for the holder, and 40BDT for the batteries)
- Detectors: Simple LDRs were used, it really doesn't matter which one, as long as it's small in size, and 10kOhm resistors to create the voltage divider circuit. For this, it cost me **115BDT** (20BDT per LDR, 15BDT for a set of resistors (10Pcs))
- Light Source: To make the system more reliable, a consistent light source in the form of an LED is introduced. For this, we need a LED and a resistor to regulate current. This will be powered by the arduino power, so we use 5V. For my case, the forward current is 30mA (0.030A), and as the LED is white, the forward voltage is 3.2V. Hence, using R=(V-V')/I, Where V is the power source voltage, and V' is the forward voltage of the LED, and I is the forward current of the LED, we can calculate that R=(5.0-3.2)/0.030=60 Ohm. We can round up to 68 Ohms, which is the closest film resistor size that fits the bill. For this, it cost me **40BDT**
- Connections: As this is a proof of concept, I've decided to go with a simple breadboard and jumper cable setup. For this, it cost me **150BDT**
- Housing for the prosthetic hand and string: As it is a proof of concept, I've elected to use a simple cardboard housing and hot glue. Flexible cardboard provides an affordable, yet sturdy housing that allows for adequate  movement. And strings are used to allow for finger contraction. For this, it cost me **30BDT**

In total, it cost me roughly **2229BDT** (or in more familiar terms, 18.11USD, 15.69EUR, 25.85AUD, 25.40CAD, 13.43GBP)
