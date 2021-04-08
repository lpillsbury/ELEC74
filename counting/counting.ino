void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
delay(3000);
int16_t count;
count = 0;
while(count <= 300)
{
Serial.print("The count is: ");
Serial.println(count, DEC);
delay(1000);
count = count + 10;
}
}
void loop() {
}
