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
#include <Servo.h>
Servo servo;
Servo servo2;
//sound+servo
int  sensorAnalogPin = A0;    // Select the Arduino input pin to accept the Sound Sensor's analog output 
//int  sensorDigitalPin = 7;    // Select the Arduino input pin to accept the Sound Sensor's digital output
int  analogValue = 0;         // Define variable to store the analog value coming from the Sound Sensor
int  realValue;
int  digitalValue;            // Define variable to store the digital value coming from the Sound Sensor
         // Define LED port; this is the LED built in to the Arduino (labled L)

//ballswitch
int BallSwitchPin= 2;
const int ledPin = 10;
const int ledPin2 = 11;
int digitalVal;

                   

void setup()
{
  Serial.begin(9600);               // The IDE settings for Serial Monitor/Plotter (preferred) must match this speed
  pinMode(sensorAnalogPin,INPUT);  // Define pin 7 as an input port, to accept digital input
  pinMode(BallSwitchPin,INPUT);
  servo.attach(9);  
  servo2.attach(8);  
  
  servo.write(90);  
  servo2.write(90);  
  pinMode(ledPin,OUTPUT);//initialize the ledPin as an output
  pinMode(ledPin2,OUTPUT); 

  digitalWrite(sensorAnalogPin, HIGH);
  digitalWrite(BallSwitchPin, HIGH);
  
  
  
  
  
}

void loop(){
  analogValue = analogRead(sensorAnalogPin); // Read the value of the analog interface A0 assigned to digitalValue 
  //digitalValue=digitalRead(sensorDigitalPin); // Read the value of the digital interface 7 assigned to digitalValue 
  analogValue = map(analogValue, 0, 50, 0, 255);
  // analogWrite(Led13, analogValue);
  Serial.println(analogValue); // Send the analog value to the serial transmit interface

 
 
  if(analogValue>=4000)      // When the Sound Sensor sends signla, via voltage present, light LED13 (L)
  {
    servo.write(90);// move servos to center position -> 90°
  delay(100);
  servo2.write(90);// move servos to center position -> 90°
  delay(100);
  
    servo.write(60);// move servos to center position -> 60°
  delay(100);
    servo2.write(60);// move servos to center position -> 60°
  delay(100);
   
  }
  else
  {
   servo.write(0);
   servo2.write(0);
  }

   //ball switch
   digitalVal = digitalRead(BallSwitchPin);
   Serial.print("BallSwitch=");
   Serial.println(digitalVal);
   delay(20);
   
   if(digitalVal == HIGH){
    digitalWrite(ledPin,LOW);
    delay(50);
    digitalWrite(ledPin2,LOW);
    delay(50);
    }
   else
   {
    digitalWrite(ledPin,HIGH);
    digitalWrite(ledPin2,HIGH);
   }
  
 
}
