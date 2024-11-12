// Program to test that the ESP32 can control the ON/ON SPDT switch correctly
// so that when the program starts the switch is read as off no matter it's position

const int switchPin = 10;  // Pin where the switch is connected
bool switchState;          // Variable to store the state of the switch (OFF by default)
bool switchOff;
bool lastSwitchState;

void setup() {
  Serial.begin(9600);                  // Initialize the serial communication
  pinMode(switchPin, INPUT);           // Set the switch pin as input
  switchOff = digitalRead(switchPin);  // Capture the initial state as OFF
  lastSwitchState = !switchOff;        //  Set last state to be opposite initally
  Serial.println("Setup Completed");
}

void loop() {
  // Read the state of the switch
  switchState = digitalRead(switchPin);

  if (switchState != lastSwitchState) {
    if (switchState == switchOff) {
      Serial.println("Switch is off");
    } else {
      Serial.println("Switch is on");
    }
  }
  lastSwitchState = switchState;
}
