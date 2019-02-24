/* Crash Collision Sensor Detection Module [S230] : http://rdiot.tistory.com/335 [RDIoT Demo] */

int ledPin = 13;                // choose the pin for the LED
int inputPin = 3;               // connect sensor to input pin 3

void setup() {
  Serial.begin(9600);           // Init the serial port
   
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare Micro switch as input
}
 
void loop(){
  int val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {                // check if the input is HIGH
    digitalWrite(ledPin, HIGH);      // turn LED OFF
  } else {
    digitalWrite(ledPin,LOW);     // turn LED ON
    Serial.println("Switch Pressed!");
  }
  delay(50);
}
