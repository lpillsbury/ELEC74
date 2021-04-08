/*
3.7 demonstrate bit shifting
*/

uint8_t s; // shift bits

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

// Use the lower nibble in the in variable to write four pints at a time
void nibbleToPins(uint8_t in, uint8_t pin_b3, uint8_t pin_b2, uint8_t pin_b1, uint8_t pin_b0) {
// use bitwise & operator to create logic condition that is
// used to light bits as if in the same nibble.
  digitalWrite(pin_b0, in & 0b00000001);
  digitalWrite(pin_b1, in & 0b00000010);
  digitalWrite(pin_b2, in & 0b00000100);
  digitalWrite(pin_b3, in & 0b00001000);
}

void setup() {
  nibbleInit(1,2,3,4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  Serial.println("looping");
  int s = 0x80; // 0b10000000
  while( s != 0x00 )
  {
    nibbleToPins(s,1,2,3,4);
    s = s >> 1;
    delay(1000);
  }
}
