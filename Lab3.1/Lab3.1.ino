void setup() {
// initialize the digital pin as an output.
// Pin 13 has an LED connected on most Arduino boards:
pinMode(LED_BUILTIN, OUTPUT);
digitalWrite(LED_BUILTIN, HIGH);
// set the LED on
delay(1000);
// wait for a second
digitalWrite(LED_BUILTIN, LOW);
// set the LED off
delay(1000);
// wait for a second
digitalWrite(LED_BUILTIN, HIGH);
// set the LED on
delay(1000);
// wait for a second
digitalWrite(LED_BUILTIN, LOW);
// set the LED off
delay(1000);
// wait for a second
digitalWrite(LED_BUILTIN, HIGH);
// set the LED on
delay(1000);
// wait for a second
digitalWrite(LED_BUILTIN, LOW);
// set the LED off
delay(1000);
// wait for a second
}
void loop() {
digitalWrite(LED_BUILTIN, HIGH);
delay(250);
digitalWrite(LED_BUILTIN, LOW);
delay(250);
}
