/**
 * Seven Segment Simple Project
 * This project use seven segment common anode which connected to arduino's digital pin no. 2-8
 * Binary or no binary is basically the same output, just different code, because TIL binary, shifting, and friends
*/
int numberCombination[10];
int numberCombinationBinary[10];

void setup() { 
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  
  setupNumberCombination();
  setupNumberCombinationBinary();
}

void loop() {
  boolean useBinaryVersion = true;
  
  if (useBinaryVersion) {
    displayWithBinary();
  } else {
    displayWithoutBinary();
  }
}

void setupNumberCombination () {
}

void setupNumberCombinationBinary () {
  numberCombinationBinary[0]= (0b0111111);
  numberCombinationBinary[1]= (0b0000110);
  numberCombinationBinary[2]= (0b1011011);
  numberCombinationBinary[3]= (0b1001111);
  numberCombinationBinary[4]= (0b1100110);
  numberCombinationBinary[5]= (0b1101101);
  numberCombinationBinary[6]= (0b1111101);
  numberCombinationBinary[7]= (0b0000111);
  numberCombinationBinary[8]= (0b1111111);
  numberCombinationBinary[9]= (0b1101111);
}

void displayWithoutBinary () {
}

void displayWithBinary () {
  for (int j=0; j<10; j++) { // number 0 to 9
    for (int i=0; i<7; i++) { // values
      if((numberCombination[j]) & (1<<i)) digitalWrite(i+2, LOW);
      else digitalWrite(i+2, HIGH);
    }
    delay(1000);
  }
}

