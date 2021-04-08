/*
Blink with a Decision
*/
uint16_t PIN_OUT = 3; // pin 1 for Fubarino Mini, pin 21 for Fubarino SD
uint16_t PIN_IN = 8; // pin 16 for Fubarino Mini, pin 23 for Fubarino SD

void setup() {
pinMode(PIN_OUT, OUTPUT);
pinMode(PIN_IN, INPUT);
}

void loop() {
  digitalWrite(PIN_OUT, !digitalRead(PIN_OUT));
  if( digitalRead(PIN_IN) == LOW ) {
    delay(200);
  }   
  else {
    delay(1000);
  }
}
