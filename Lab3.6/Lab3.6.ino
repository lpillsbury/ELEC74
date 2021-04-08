/*
3.6 light up 4 lights sequentially on button press
*/
uint16_t PIN_OUT1 = 1; 
uint16_t PIN_OUT2 = 2;
uint16_t PIN_OUT3 = 3;
uint16_t PIN_OUT4 = 4;
uint16_t PIN_IN = 16; 

void setup() {
pinMode(PIN_OUT1, OUTPUT);
pinMode(PIN_OUT2, OUTPUT);
pinMode(PIN_OUT3, OUTPUT);
pinMode(PIN_OUT4, OUTPUT);
pinMode(PIN_IN, INPUT);
}

void loop() {
  
  if( digitalRead(PIN_IN) == HIGH ) {
    delay(200);
  }   
  else {
    for(int i = 1; i <= 4; i++){
      digitalWrite(i, HIGH);
      delay(1000);
    }
    delay(1000);
    for(int i = 1; i <= 4; i++){
      digitalWrite(i, LOW);
    }
  }
}
