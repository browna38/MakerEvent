#include <Servo.h> //includes header file containing Servo code

Servo myServo; //instantiates Servo

int potPin = 2; //initializes data pin for potentiometer pin to pin 2
int val = 0; //variable that reads analog signal from potentiometer
int pos = 0; //variable that sets position for Servo

void setup() {
  myServo.attach(9); //initializes pin D9 for Servo
  Serial.begin(9600); //initializes serial monitor for debugging
}

void loop() {
  
  val = analogRead(potPin); //reads signal from potentiometer as int 0-1023 from pin A2
  Serial.print("Val: "); //for debugging
  Serial.print(val);
  pos = (int)((double)(val)/1023*180); //converts from int 0-1023 to int 0-180
  Serial.print("     Pos: "); //for debugging
  Serial.println(pos);
  myServo.write(pos); //moves Servo to new position
  delay(15); //delay to allow motor to turn
}
