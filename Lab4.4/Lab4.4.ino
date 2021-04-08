//Arduino Uno talks to Fubarino!
// digital 0 is RX and 1 is TX on arduino
#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1);
void setup()
{
Serial.begin(9600);
mySerial.begin(9600);
}
void loop()
{
if (mySerial.available()>0)
{
Serial.write(mySerial.read());
}
if (Serial.available()>0)
{
mySerial.write(Serial.read());
}
delay(200);
}
