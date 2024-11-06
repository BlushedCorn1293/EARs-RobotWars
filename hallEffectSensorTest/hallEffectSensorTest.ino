const int hallPin = ;  // Pin connected to the sensor's signal output
int hallState = 0;     // Variable to store the sensors state

void setup() {
  pinMode(hallPin, INPUT);  // Set the sensor pin as input
  serial.begin(9600);       // Initialise the serial communication
}

void loop() {
  hallState = digitalRead(hallPin);  // Read the sensor's state (HIGH/LOW)

  if (hallState == HIGH) {
    Serial.println("Magnetic field detected")
  } else {
    Serial.println("No magnetic field")
  }

  delay(100);  // Delay for readability
}
