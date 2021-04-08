void setup()
{
Serial.begin(115200); // Open the Serial Port
delay(3000); // Give us a chance to open the serial terminal
}
void loop()
{
static uint32_t count = 1;
Serial.print("base 10 = ");
Serial.print(count, DEC);
// DEC constant implies base 10
Serial.println(".");
// Print . and new line
delay(1000);
count = count * 10;
// Increment the count variable
}
