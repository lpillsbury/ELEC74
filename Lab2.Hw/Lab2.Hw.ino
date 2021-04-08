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
void count_down() {
  static int8_t count = 10; // declare count and set its value to 0
  nibbleToPins(count,0,1,2,3); //call a function that sets all 4 pins
  Serial.println(count);
  count = count - 1;
  if (count == -1){
    count = 10;
    delay(1000);
  }
}

void chase(void)
{
static uint8_t i=0;
uint8_t pattern1[]={ 0b00000001,
0b00000010,
0b00000100,
0b00001000,
0b00000100,
0b00000010};
nibbleToPins(pattern1 [i],0,1,2,3);
i = (i + 1) % sizeof(pattern1);
}

void loop() {
count_down();
delay(300);
}
