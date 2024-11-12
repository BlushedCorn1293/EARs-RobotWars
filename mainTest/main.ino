// Main program to control BattleBot weapon
// Switch on arduino is used to arm BattleBot (if off then motor cannot spin up)
// A switch on the controller is then used to send a signal to the reciever to trigger the motor to start spinning
// When the hall effect sensor then detects the driven part of the flipper weapon, the motor is turned off

#include <ESP32Servo.h>

const int recieverPin = 7;  // Pin for reading throttle input from RC receiver
const int escPin = 9;       // PWM pin connected to the ESC signal wire
const int switchPin = 10;   // Pin where switch is connected
const int hallPin = 2;      // Pin where the hall effect sensor is connected

bool switchState;      // Variable to store the current state of the switch
bool switchOff;        // Variable to store the default off state of the switch
bool lastSwitchState;  // Variable to store the previous switch state

bool hallState;      // Variable to store the current state of the hall effect sensor
bool lastHallState;  // Variable to store the previous hall effect sensor state

const int minThrottlePulse = 995;   // Minimum Throttle pulse from Controller
const int maxThrottlePulse = 1867;  // Maximum Throttle pulse from Controller

const int minThrottle = 0;  // Min throttle as a percentage out of 100
const int maxThrottle = 5;  // Max throttle as a percentage out of 100
int outThrottle;            // Output throttle value (will equal min/max Throttle)


const int recieverTriggerValue = 1500;  // Pulse value from reciever which will trigger the motor to spin
int recieverOutput;

int escValue;
Servo esc;  // Create a Servo object to control the ESC

void setup() {
  Serial.begin(9600);  // Initialise the serial communication
  pinMode(hallPin, INPUT);
  pinMode(recieverPin, INPUT);
  pinMode(switchPin, INPUT);

  switchOff = digitalRead(switchPin);  // Capture the initial state as OFF
  lastSwitchState = !switchOff;        //  Set last state to be opposite initally

  lastHallState = !digitalRead(hallPin);  // Captures the initall state of the hall effect sensor

  esc.attach(escPin);  // Attach the ESC signal wire to the escPin

  // Initialise ESC with minimum throttle signal
  esc.writeMicroseconds(minThrottlePulse);
  delay(2000);  // Time for ESC to initialize
  Serial.println("ESC initialised");
  Serial.println("Setup Completed");
}


void loop() {

  switchState = digitalRead(switchPin);  // Read the current state of the switch
  hallState = digitalRead(hallPin);      // Read the sensor's state (HIGH/LOW)

  if ((switchState != lastSwitchState) || (hallState != lastHallState)) {
    if (switchState == switchOff) {  // If switch is ON (If OFF then will outThrotttle 0)
      outThrottle = minThrottle;
    } else {

      if (hallState == LOW) {                               // If sensor NOT yet triggered
        recieverOutput = pulseIn(recieverPin, HIGH, 2000);  // read pulse output from reciever (Timeout after 20ms if no signal which sets value to 0)
        if (recieverOutput > recieverTriggerValue) {        // If switch on controller has been turned on , max motor speed
          outThrottle = maxThrottle;
        }
      }
    }

    // Map the RC throttle signal to the range needed by the ESC
    escValue = map(outThrottle, 0, 100, minThrottlePulse, maxThrottlePulse);

    // Send the mapped value to the ESC
    esc.writeMicroseconds(escValue);

    // Print the throttle and mapped values for debugging
    Serial.print(" ESC output: ");
    Serial.print(escValue);
    Serial.println(" µs");

    lastSwitchState = switchState;
    lastHallState = hallState;
  }
}
