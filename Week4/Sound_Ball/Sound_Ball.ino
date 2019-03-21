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
//int  sensorDigitalPin = 7;    // Select the Arduino input pin to accept the Sound Sensor's digital output
int  analogValue = 0;         // Define variable to store the analog value coming from the Sound Sensor
int  realValue;
int  digitalValue;            // Define variable to store the digital value coming from the Sound Sensor
int  vib13 = 13;              // Define LED port; this is the LED built in to the Arduino (labled L)

//ballswitch
int BallSwitchPin= 2;
const int ledPin = 10;
int digitalVal;

                   

void setup()
{
  Serial.begin(9600);               // The IDE settings for Serial Monitor/Plotter (preferred) must match this speed
  pinMode(sensorAnalogPin,INPUT);  // Define pin 7 as an input port, to accept digital input
  pinMode(BallSwitchPin,INPUT);
  
  pinMode(vib13,OUTPUT);  
  pinMode(ledPin,OUTPUT);//initialize the ledPin as an output

  digitalWrite(sensorAnalogPin, HIGH);
  digitalWrite(BallSwitchPin, HIGH);
  
  
  
  
  
}

void loop(){
  analogValue = analogRead(sensorAnalogPin); // Read the value of the analog interface A0 assigned to digitalValue 
  //digitalValue=digitalRead(sensorDigitalPin); // Read the value of the digital interface 7 assigned to digitalValue 
  analogValue = map(analogValue, 0, 50, 0, 255);
  // analogWrite(Led13, analogValue);
  Serial.println(analogValue); // Send the analog value to the serial transmit interface

 
 
  if(analogValue>=3000)      // When the Sound Sensor sends signla, via voltage present, light LED13 (L)
  {
    digitalWrite(vib13,HIGH);
    delay(100);
  }
  else
  {
    digitalWrite(vib13,LOW);
  }

   //ball switch
   digitalVal = digitalRead(BallSwitchPin);
   Serial.print("BallSwitch=");
   Serial.println(digitalVal);
   delay(100);
   
   if(digitalVal == HIGH){
    digitalWrite(ledPin,HIGH);
    }
   else
   {
    digitalWrite(ledPin,LOW);
   }
  
 
}
