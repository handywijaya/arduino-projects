// This code is using Ultrasonic sensor HC-SR04

const int triggerPin = 6;
const int echoPin = 7;

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
  long duration, inches, cm;
  
  // clean up the pin
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  // send ultrawave pulse (set to HIGH for 10 microsecs)
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
}

// kind of magic number result
// we measure speed of sound with microsecs traveled
// to get the inches or centimeters
long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
