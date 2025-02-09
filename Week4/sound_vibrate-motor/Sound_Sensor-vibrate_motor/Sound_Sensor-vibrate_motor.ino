// www.elegoo.com
// 2018.10.24
/*
  LED1 should be lit, showing power. LED2 indicates sound input, and the sensitivity is adjusted by potentiometer.
  There is a tiny screw on the blue potentiometer block that you can use for adjustment. Turning that
  clockwise lowers the potentiometer value, while counter-clockwise raises the potentiometer value.
  Use the potentiometer to adjust the Sound Sensor sensitivity. Turn the potentiometer
  several rotations until you see the LED2 extinguish (or just faintly blink). This might be slightly greater than
  500, if you are also watching Serial Monitor (inital adjustment), or, Serial Plotter (the latter is prefererd for observation).
  Special thanks to user CRomer, for his input and hard work!
*/

//sound+vibrate
int  sensorAnalogPin = A0;    // Select the Arduino input pin to accept the Sound Sensor's analog output 
int  sensorDigitalPin = 7;    // Select the Arduino input pin to accept the Sound Sensor's digital output
int  analogValue = 0;         // Define variable to store the analog value coming from the Sound Sensor
int  realValue;
int  digitalValue;            // Define variable to store the digital value coming from the Sound Sensor
int  vib13 = 13;              // Define LED port; this is the LED built in to the Arduino (labled L)

//ballswitch
const int servoPin = 10;
int digitalVal = digitalRead(2);
//servo
#include <Servo.h>
Servo myservo; 
int pos = 0;                        

void setup()
{
  Serial.begin(9600);               // The IDE settings for Serial Monitor/Plotter (preferred) must match this speed
  pinMode(sensorDigitalPin,INPUT);  // Define pin 7 as an input port, to accept digital input
  pinMode(vib13,OUTPUT);  

  pinMode(servoPin,OUTPUT);//initialize the ledPin as an output
  pinMode(2,INPUT);
  digitalWrite(2, HIGH);
  
  myservo.attach(9); 
}

void loop(){
  analogValue = analogRead(sensorAnalogPin); // Read the value of the analog interface A0 assigned to digitalValue 
  //digitalValue=digitalRead(sensorDigitalPin); // Read the value of the digital interface 7 assigned to digitalValue 
 analogValue = map(analogValue, 0, 50, 0, 255);
  // analogWrite(Led13, analogValue);
Serial.println(analogValue); // Send the analog value to the serial transmit interface
  
  if(analogValue>4000)      // When the Sound Sensor sends signla, via voltage present, light LED13 (L)
  {
    digitalWrite(vib13,HIGH);
    delay(100);
  }
  else
  {
    digitalWrite(vib13,LOW);
  }
  
  delay(50);                  // Slight pause so that we don't overwhelm the serial interface

}


  //Serial.println(digitalVal);

/*
  if(HIGH == digitalVal)
  {
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  }
  else
  {

   for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
*/
