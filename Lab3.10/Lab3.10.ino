/*
3.10 logical operators
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
  nibbleInit(5, 6, 7, 8, INPUT);
  nibbleInit(9, 10, 11, 12, INPUT);
  delay(3000);
  Serial.println("starting...");
}

void loop() {
  
  uint8_t a, b;
  uint8_t accumulator;
  a = digitalRead(5);
  b = digitalRead(9);
  Serial.print("a=");
  Serial.print(a, BIN);
  Serial.print(" b=");
  Serial.println(b, BIN);
  
  // logical NOT
  if( !a ) {
    digitalWrite(1, HIGH);
    Serial.println("NOT a is HIGH");
  }
  else {
    digitalWrite(1, LOW);
    Serial.println("NOT a is LOW ");
  }
  
  // NAND
  if( a != b || (a == 0 && b == 0)) {
    digitalWrite(2, HIGH);
    Serial.println("a NAND b is HIGH");
  }
  else {
    digitalWrite(2, LOW);
    Serial.println("a NAND b is LOW ");
  }
  
  // logical OR
  if (a || b){
    digitalWrite(3, HIGH);
    Serial.println("a OR b is HIGH");
  }
    else {
    digitalWrite(3, LOW);
    Serial.println("a OR b is LOW ");
  }

  // XOR
  if (a != b){
    digitalWrite(4, HIGH);
    Serial.println("a XOR b is HIGH");
  }
    else {
    digitalWrite(4, LOW);
    Serial.println("a XOR b is LOW ");
  }
  Serial.println("");
  Serial.println("");
  delay(100);
}
