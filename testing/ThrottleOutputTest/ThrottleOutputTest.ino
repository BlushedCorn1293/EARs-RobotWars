// Program to test that the ESP32 is able to control the motor via a switch
// When the switch is on, the motor spins to max speed and when off stop

#include <ESP32Servo.h>

const int escPin = 9;       // PWM pin connected to the ESC signal wire
const int switchPin = 10;   // Pin where the switch is connected

// Can be treated as a percentage of throttle value
const int minThrottlePulse = 995;   // Minimum Throttle pulse from Controller
const int maxThrottlePulse = 1867;  // Maximum Throttle pulse from Controller
const int highThrottle = 5;         // Max throttle as a percentage out of 100

int outThrottle = minThrottlePulse;  // Set default throttle to 0

int escValue;
Servo esc;  // Create servo object to control the ESC

bool switchState;  // Variable to store the state of the switch
bool switchOff;
bool lastSwitchState;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);         // Initialise the serial communication
  pinMode(switchPin, INPUT);  // Set the switch pin as input

  switchOff = digitalRead(switchPin); // Capture the initial state as OFF
  lastSwitchState = !switchOff; //  Set last state to be opposite initally

  esc.attach(escPin);  // Attach the ESC signal wire to the escPin

  // Initialise ESC with minimum throttle signal
  esc.writeMicroseconds(minThrottlePulse);
  delay(2000);  // Time for ESC to initialize
  Serial.println("ESC initialised");
}

void loop() {
  switchState = digitalRead(switchPin);  // Read the current state of the switch
  if (switchState != lastSwitchState) {
    if (switchState == switchOff) {
      Serial.println("Switch is off");
      outThrottle = 0;
    } else {
      Serial.println("Switch is on");
      outThrottle = highThrottle;
    }
  }

  // Map the RC throttle signal to the range needed by the ESC
  escValue = map(outThrottle, 0, 100, minThrottlePulse, maxThrottlePulse);

  // Send the mapped value to the ESC
  esc.writeMicroseconds(escValue);

  // Print the throttle and mapped values for debugging
  Serial.print("Throttle input: ");
  Serial.print(outThrottle);
  Serial.print(" µs, ESC output: ");
  Serial.print(escValue);
  Serial.println(" µs");
  lastSwitchState = switchState;
  delay(50);  // Delay to allow for suitablereadings
}
