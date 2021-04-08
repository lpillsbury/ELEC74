//Serial Fubarino SD USB, Fubarino Mini USB
//Serial0 Fubarino SD tx 8 rx 9, Fubarino Mini tx 17 rx 18
//Serial1 Fubarino SD tx 28 rx 29, Fubarino Mini tx 26 rx 25
void setup()
{
Serial.begin(9600);
Serial0.begin(9600);
}
void loop()
{
if (Serial.available()>0)
{
Serial0.write(Serial.read());
}
if (Serial0.available()>0)
{
Serial.write(Serial0.read());
}
delay(200);
}
