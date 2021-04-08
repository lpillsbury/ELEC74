void setup() {
Serial.begin(115200);
pinMode(0,OUTPUT);
pinMode(1,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
}
void loop() {
Serial.println("looping");
digitalWrite(0,HIGH);
delay(200);
digitalWrite(0,LOW);
digitalWrite(1,HIGH);
delay(200);
digitalWrite(1,LOW);
digitalWrite(2,HIGH);
delay(200);
digitalWrite(2,LOW);
digitalWrite(3,HIGH);
delay(200);
digitalWrite(3,LOW);

}
