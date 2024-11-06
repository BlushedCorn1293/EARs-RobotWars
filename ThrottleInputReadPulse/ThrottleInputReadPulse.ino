const int throttlePin = 7;  // Pin connected to the throttle signal from the RC reciever
int throttleValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Initialise the serial communication
  pinMode(throttlePin, INPUT);
}

// can be used to test the pulse signal that the rc controller transmits to the reciever
void loop() {
  // put your main code here, to run repeatedly:

  // Measure the pulse width in microseconds
  throttleValue = pulseIn(throttlePin, HIGH);

  // Output throttle value
  Serial.print("Throttle pulse width: ");
  Serial.print(throttleValue);
  Serial.println(" µs");

  delay(200) //loop delay in milliseconds
}
