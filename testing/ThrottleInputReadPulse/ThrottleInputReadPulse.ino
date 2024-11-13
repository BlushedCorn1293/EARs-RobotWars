// Program to read pulse signals which the RC Controller sends to the Reciever
// used to find min and max pulse values to control the motor
// also used to find the pulse value which is sent when a switch on the controller changes state

const int recieverPin = 13;  // Pin connected to the throttle signal from the RC reciever
int recieverPulseValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);  // Initialise the serial communication
  Serial.println("Starting");
  pinMode(recieverPin, INPUT);
}

void loop() {

  // Measure the pulse width in microseconds
  recieverPulseValue = pulseIn(recieverPin, HIGH);

  // Output throttle value
  Serial.print("Throttle pulse width: ");
  Serial.print(recieverPulseValue);
  Serial.println(" µs");

  delay(100);  //loop delay in milliseconds
}
