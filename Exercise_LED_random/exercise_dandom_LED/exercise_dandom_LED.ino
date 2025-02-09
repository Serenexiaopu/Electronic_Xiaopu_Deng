/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

int chosen = 7;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  chosen = random(7, 10);
   /*
   digitalWrite(9,HIGH);
   delay(200);
   digitalWrite(9,LOW);
   delay(200);
   */

  digitalWrite(chosen, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(random(1, 7) * 100);                    // wait for a second
  digitalWrite(chosen, LOW);    // turn the LED off by making the voltage LOW
  delay(random(10, 30));                      // wait for a second




}
