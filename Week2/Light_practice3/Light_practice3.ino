/* the yellow led work, the blue light doesn't work*/  

int yellowLedPin = 11;
int blueLedPin = 10;

int lightSensorPin = A0;
int analogValue = 0;



void setup() {
  // put your setup code here, to run once:
//  pinMode(yellowLedPin, OUTPUT);
 // pinMode(blueLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  analogValue = analogRead (lightSensorPin);
  Serial.println(analogValue);
  if(analogValue<600){
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(blueLedPin, HIGH);
    
  }
 

   if (analogValue>400){
    digitalWrite(blueLedPin, HIGH);
    }

    delay(1000);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(blueLedPin, LOW);
  /*
  delay(200);
  digitalWrite(blueLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(whiteLedPin, LOW);
*/
}
