/**
 * Seven Segment Simple Project
 * This project use seven segment common anode which connected to arduino's digital pin no. 2-8
 * Binary or no binary is basically the same output, just different code, because TIL binary, shifting, and friends
*/
int numberCombination[10][7] = {
//  a  b  c  d  e  f  g
  { 1, 1, 1, 1, 1, 1, 0},  // 0
  { 0, 1, 1, 0, 0, 0, 0},  // 1
  { 1, 1, 0, 1, 1, 0, 1},  // 2
  { 1, 1, 1, 1, 0, 0, 1},  // 3
  { 0, 1, 1, 0, 0, 1, 1},  // 4
  { 1, 0, 1, 1, 0, 1, 1},  // 5
  { 1, 0, 1, 1, 1, 1, 1},  // 6
  { 1, 1, 1, 0, 0, 0, 0},  // 7
  { 1, 1, 1, 1, 1, 1, 1},  // 8
  { 1, 1, 1, 1, 0, 1, 1},  // 9
};
int numberCombinationBinary[10] = {
  (0b0111111),  // 0
  (0b0000110),  // 1
  (0b1011011),  // 2
  (0b1001111),  // 3
  (0b1100110),  // 4
  (0b1101101),  // 5
  (0b1111101),  // 6
  (0b0000111),  // 7
  (0b1111111),  // 8
  (0b1101111),  // 9
};

void setup() {
  // set the arduino's digital pin to output
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {
  // change this value freely
  boolean useBinaryVersion = false;
  
  if (useBinaryVersion) {
    displayWithBinary();
  } else {
    displayWithoutBinary();
  }
}

void displayWithoutBinary () {
  int lenNum = sizeof(numberCombination)/sizeof(numberCombination[0]);
  for (int i=0; i<lenNum; i++) {
    int lenNumSegment = sizeof(numberCombination[i])/sizeof(numberCombination[i][0]);
    for (int j=0; j<lenNumSegment; j++) {
      if (numberCombination[i][j]) {
        // set to LOW for common anode type to send power to a segment
        // use +2 because the start pin is 2
        digitalWrite(j+2, LOW);
      } else {
        digitalWrite(j+2, HIGH);
      }
    }
    delay(500);
  }
}

void displayWithBinary () {
  for (int i=0; i<10; i++) { // number 0 to 9
    for (int j=0; j<7; j++) { // values
      if((numberCombinationBinary[i]) & (1<<j)) { 
        digitalWrite(j+2, LOW); 
      }
      else {
        digitalWrite(j+2, HIGH);
      }
    }
    delay(500);
  }
}

