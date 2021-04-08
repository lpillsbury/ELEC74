void setup() {
  Serial.begin(115200);
  Serial.println("pre communications");
  delay(3000);
  Serial.println("3 seconds later");

}

void loop() {
  unsigned char count = 0;
  Serial.print(" base 10: ");
  Serial.print(count, DEC);
  Serial.print(" base 16: ");
  Serial.print(count, HEX);
  Serial.print(" base 8: ");
  Serial.print(count, OCT);
  Serial.print(" base 2: ");
  Serial.print(count, BIN);
  Serial.println();
  delay(250);
  count = count + 1;
  
}
