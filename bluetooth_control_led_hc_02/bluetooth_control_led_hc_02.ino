// This app is using:
// 1. Bluetooth Module HC-02 connected to PIN RX/0 (TX), PIN TX/1 (RX), 5V (VCC), GND (GND)
// 2. LED connected to PIN 10 (plus), GND (GND)
// This app tested using an android app found on Playstore which sends 0 to turn off light and 1 to turn on light

#define ledPin 10

int lastState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}

void loop() {
  if(Serial.available() > 0) { // Checks whether data is comming from the serial port
    int currentState = -1;
    currentState = Serial.read(); // Reads the data from the serial port
    Serial.println(currentState);
    if (shouldChangeLedStatus(currentState)) {
      lastState = currentState;
      changeLedStatus(currentState);
    }
  }
}

boolean shouldChangeLedStatus(int currentState) {
  return currentState > -1 && lastState != currentState;
}

void changeLedStatus(int state) {
  int hlState = LOW; // high/low state
  String s = "OFF";
  if (state == 1) {
    hlState = HIGH;
    s = "ON";
  }
  digitalWrite(ledPin, hlState);
  Serial.println("LED: " + s);
}
