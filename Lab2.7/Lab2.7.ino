void nibbleToPins(uint8_t in, uint8_t pin3, uint8_t pin2, uint8_t pin1,
uint8_t pin0) {
// use bitwise & operator to create logic condition that is
// used to light bits as if in the same nibble.
digitalWrite(pin0, in & 0b00000001);
digitalWrite(pin1, in & 0b00000010);
digitalWrite(pin2, in & 0b00000100);
digitalWrite(pin3, in & 0b00001000);
}
void setup() {
Serial.begin(115200);
pinMode(0,OUTPUT);
pinMode(1,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
}
void count_up() {
static uint8_t count = 0; // declare count and set its value to 0
nibbleToPins(count,0,1,2,3); //call a function that sets all 4 pins
delay(1000);
count = count + 1;
}
void loop() {
Serial.println("looping");
count_up();
}
