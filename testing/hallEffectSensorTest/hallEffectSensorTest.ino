// Program to test the ESP32 can correctly read values from the Hall Effect Sensor

const int hallPin = 2;  // Pin connected to the sensor's signal output

bool hallState;      // Variable to store the current state of the hall effect sensor
bool lastHallState;  // Variable to store the previous hall effect sensor state

void setup() {
  Serial.begin(9600);                     // Initialise the serial communication
  pinMode(hallPin, INPUT);                // Set the sensor pin as input
  lastHallState = !digitalRead(hallPin);  // Set the last state to be different to current for first run of loop
  Serial.println("Setup Completed");
}

void loop() {
  hallState = digitalRead(hallPin);  // Read the sensor's state (HIGH/LOW)

  if (hallState != lastHallState) {
    if (hallState == HIGH) {
      Serial.println("Magnetic field detected");
    } else {
      Serial.println("No magnetic field");
    }
  }

  lastHallState = hallState;
}
