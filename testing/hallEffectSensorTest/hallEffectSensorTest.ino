// Program to test the ESP32 can correctly read values from the Hall Effect Sensor

const int hallPin = 26;  // Pin connected to the sensor's signal output

int hallState;       // Variable to store the current state of the hall effect sensor
bool lastHallState;  // Variable to store the previous hall effect sensor state

void setup() {
  Serial.begin(115200);                  // Initialise the serial communication
  pinMode(hallPin, INPUT);               // Set the sensor pin as input
  lastHallState = !analogRead(hallPin);  // Set the last state to be different to current for first run of loop
  Serial.println("Setup Completed");
}

void loop() {
  int sensorValue = analogRead(hallPin);         // Read the sensor's state (HIGH/LOW)
  float voltage = sensorValue * (5.0 / 1023.0);  // Convert analog reading to voltage (for 5V Arduino)
  Serial.println(voltage);
  // if (hallState != lastHallState) {
  // if (hallState == HIGH) {
  //   Serial.println("Magnetic field detected");
  // } else {
  //   Serial.println("No magnetic field");
  // }
  // }

  // lastHallState = hallState;
}
