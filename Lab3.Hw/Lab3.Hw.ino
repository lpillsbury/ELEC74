/*
3 Homework counting up by a whole byte. 8 LEDs and 2^8 states
*/



// Initialize four pins at a time in a nibble
void nibbleInit(uint8_t pin_b3, uint8_t pin_b2, uint8_t pin_b1, uint8_t pin_b0, uint8_t mode)
{
  pinMode(pin_b3, mode);
  pinMode(pin_b2, mode);
  pinMode(pin_b1, mode);
  pinMode(pin_b0, mode);
}

// Read four pins at a time an store in the lower nibble of the result
uint8_t pinsToNibble(uint8_t pin_b3, uint8_t pin_b2, uint8_t pin_b1, uint8_t pin_b0)
{
  uint8_t nibble;
  nibble = digitalRead(pin_b3) << 3 |
  digitalRead(pin_b2) << 2 |
  digitalRead(pin_b1) << 1 |
  digitalRead(pin_b0) << 0;
  return nibble;
}

// Use the lower nibble in the in variable to write four pins at a time
void nibbleToPins(uint8_t in, uint8_t pin_b3, uint8_t pin_b2, uint8_t pin_b1, uint8_t pin_b0) {
// use bitwise & operator to create logic condition that is
// used to light bits as if in the same nibble.
  digitalWrite(pin_b0, in & 0b00000001);
  digitalWrite(pin_b1, in & 0b00000010);
  digitalWrite(pin_b2, in & 0b00000100);
  digitalWrite(pin_b3, in & 0b00001000);
}

// expanding on nibbleToPins and passing pinnames as an array
void byteToPins(uint8_t in, uint8_t bytepins[]){
  uint8_t a = 0b00000001;
  // we know that the array will have 8 values in it, not doing error checking here
  for(int i = 0; i < 8; i++){
    digitalWrite(bytepins[i], in & a);
    // left shift a
    a = a << 1;
    //Serial.print("a: ");
    //Serial.println(a, BIN);
  }
  
}

void setup() {
  nibbleInit(1,2,3,4, OUTPUT);
  nibbleInit(25, 26, 27, 28, OUTPUT);
  Serial.begin(9600);
  delay(3000);
  Serial.println("starting...");
}

void loop() {
  
  uint8_t b;
  uint8_t bytearray [8] = {28, 27, 26, 25, 1, 2, 3, 4};
  for(b = 0; b < 256; b++){
    //nibbleToPins(b, 4, 3, 2, 1);
    //nibbleToPins(b, 28, 27, 26, 25);
    byteToPins(b, bytearray);
    Serial.print("b = ");
    Serial.println(b, BIN);
    Serial.println();
    delay(200);
  }
}
