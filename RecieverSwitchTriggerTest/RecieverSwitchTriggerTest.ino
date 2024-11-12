// Program to simulate using a switch on the controller to trigger the flipper weapon
// by sending a pulse signal to the esc through the ESP32
// Mainly used to test for the optimal recieverTriggerValue


const int recieverPin = 7;              // Pin for reading throttle input from RC receiver
const int recieverTriggerValue = 1500;  // Pulse value from reciever which will trigger the motor to spin
int recieverOutput;

const int minThrottlePulse = 995;   // Minimum Throttle pulse from Controller
const int maxThrottlePulse = 1867;  // Maximum Throttle pulse from Controller

const int minThrottle = 0;  // Min throttle as a percentage out of 100
const int maxThrottle = 5;  // Max throttle as a percentage out of 100
int outThrottle;            // Output throttle value (will equal min/max Throttle)
int escValue;

void setup() {
  Serial.begin(9600);
  pinMode(recieverPin, INPUT);
  Serial.println("Starting...");
}

void loop() {

  recieverOutput = pulseIn(recieverPin, HIGH, 2000);  // read pulse output from reciever (Timeout after 20ms if no signal)

  if (recieverOutput > recieverTriggerValue) {  // If switch on controller has been turned on, max motor speed
    outThrottle = maxThrottle;
  }else{
    outThrottle = minThrottle;
  }
  // Map the RC throttle signal to the range needed by the ESC
  escValue = map(outThrottle, 0, 100, minThrottlePulse, maxThrottlePulse);

  Serial.print("Pulse value which would be sent to esc: ");
  Serial.println(escValue);
}
