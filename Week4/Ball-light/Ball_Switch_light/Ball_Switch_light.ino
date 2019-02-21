//www.elegoo.com
//2016.12.08
/*****************************************/
const int ledPin = 10;//the led attach to
int digitalVal;
void setup()
{ 
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);//initialize the ledPin as an output
  pinMode(2,INPUT);
  digitalWrite(2, HIGH);
} 
/******************************************/
void loop() 
{  


digitalVal = digitalRead(2);
    Serial.println(digitalVal);
  if(HIGH == digitalVal)
  {
    digitalWrite(ledPin,HIGH);//turn the led off
  }
  else
  {
    digitalWrite(ledPin,LOW);//turn the led on 
  }
}
/**********************************************/
