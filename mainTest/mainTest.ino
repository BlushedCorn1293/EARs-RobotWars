#include < Servo.h>

const int throttlePin = ;  // Pin for reading throttle input from RC receiver
const int escPin = ;       // PWM pin connected to the ESC signal wire
int throttleValue;         // Variable to store the throttle signal pulse width
int outThrottle;

// Can be treated as a percentage of throttle value
const int minThrottlePulse = ;  // Minimum Throttle pulse from Controller
const int maxThrottlePulse = ;  // Maximum Throttle pulse from Controller
const int highThrottle = 50;    // Max throttle as a percentage out of 100

const int hallPin = ;
int hallState = 0;  // Variable to store the sensor state

const int switchPulseTriggerValue = ;

void setup() {
  Serial.begin(9600);  // Initialise the serial communication
  pinMode(hallPin, INPUT);
  pinMode(throttlePin, INPUT);

  esc.attach(escPin);  // Attach the ESC signal wire to the escPin

  // Initialise ESC with minimum throttle signal
  esc.writeMicroseconds(minInThrottlePulse);
  delay(2000);  // Time for ESC to initialize
  Serial.println("ESC initialised");
}
int escValue;

void loop() {
  // default to low throttle in case an error occurs
  outThrottle = 0;

  hallState = digitalRead(hallPin)  // Read the sensor's state (HIGH/LOW)
    // If sensor NOT triggered
    if (hallState == LOW) {
    // Reset the re-read throttle value
    throttleValue = 0;
    throttleValue = pulseIn(throttlePin, HIGH, 2000);  // Timeout after 20ms if no signal
    // Check if switch has been turned on or not via throttle value
    if (throttleValue > switchPulseTriggerValue) {
      //Switch turned on so max out throttle
      outThrottle = highThrottle;
    }

    // Map the RC throttle signal to the range needed by the ESC
    escValue = map(outThrottle, 0, 100, minThrottlePulse, maxThrottlePulse);

    // Send the mapped value to the ESC
    esc.writeMicroseconds(escValue);

    // Print the throttle and mapped values for debugging
    Serial.print(" ESC output: ");
    Serial.print(escValue);
    Serial.println(" µs");
  }
