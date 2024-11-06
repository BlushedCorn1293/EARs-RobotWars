#incluse < Servo.h>

const int throttlePin = 7;            // Pin for reading throttle input from RC receiver
const int escPin = 9;                 // PWM pin connected to the ESC signal wire
int throttleValue;                    // Variable to store the throttle signal pulse width
const int minInThrottlePulse = ;  // Minimum Throttle pulse from Controller (DONT CHANGE AFTER SET)
const int maxInThrottlePulse = ;  // Maximum Throttle pulse from Controller (DONT CHANGE AFTER SET)

const int minOutThrottlePulse = ;
const int maxOutThrottlePulse = ;

Servo esc;  // Create servo object to control the ESC

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600)  // Initialise the serial communication
    pinMode(throttlePin, Input);

  esc.attatch(escPin)  // Attach the ESC signal wire to the escPin

    // Initialise ESC with minimum throttle signal
    esc.writeMicroseconds(minInThrottlePulse);
  delay(2000)  // Time for ESC to initialize
    Serial.println("ESC initialised");
}

void loop() {
  // put your main code here, to run repeatedly:
  // Read the pulse width from the RC throttle signal
  throttleValue = pulseIn(throttlePin, HIGH);

  // Map the RC throttle signal to the range needed by the ESC
  int escValue = map(throttleValue, minInThrottlePulse, maxInThrottlePulse, minOutThrottlePulse, maxOutThrottlePulse);

  // Send the mapped value to the ESC
  esc.writeMicroseconds(escValue);

  // Print the throttle and mapped values for debugging
  Serial.print("Throttle input: ");
  Serial.print(throttleValue);
  Serial.print(" µs, ESC output: ");
  Serial.print(escValue);
  Serial.println(" µs");

  delay(50);  // Delay to allow for suitablereadings
}
