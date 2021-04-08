void setup()
{
Serial.begin(9600);
}

void loop()
  if (Serial.available()>0)
  // have I received any data?
  {
    Serial.write(Serial.read()); // read it and send it back?
    delay(250);
    // delay between transmitting characters?
  }
}
