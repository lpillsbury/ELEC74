void setup()
{
Serial.begin(9600);
}

void loop(){
  uint8_t received;
  if (Serial.available()>0)//have I received any data
  {
    received = Serial.read();
    Serial.print("Received: \""); // Backslash used here \"\"\"
    Serial.write(received);
    Serial.print("\" base 10 = ");
    Serial.print(received, DEC);
    // DEC constant implies base 10
    Serial.print(", base 16 = ");
    Serial.print(received, HEX);
    // HEX constant implies base 16
    Serial.print(", base 8: ");
    Serial.print(received, OCT);
    // OCT constant implies base 8
    Serial.print(", base 2: ");
    Serial.println(received, BIN);
    // BIN constant implies base 2
  }
}
