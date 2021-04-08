uint16_t PIN_OUT = 3; 
uint16_t PIN_IN = 8; 

void setup() {
Serial.begin(9600);
pinMode(PIN_OUT, OUTPUT);
pinMode(PIN_IN, INPUT);
}

// Configure PIN_OUT as OUTPUT
// Configure PIN_IN as INPUT
void loop() {
uint8_t value;
value = digitalRead(PIN_IN); // read PIN_IN and store it in value
digitalWrite(PIN_OUT, value); // write value out to PIN_OUT
Serial.println(value, BIN);
delay(100);
}
