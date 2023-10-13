

/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.

 */

#include <Servo.h>

#include <Stepper.h>


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

const int stepsPerRevolution = 1000;  // change this to fit the number of steps per revolution

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution,8, 10, 9, 11);
int buttonpin1 = 3;
int buttonpin2 = 6;
int val1;
int val2;
void setup() {
  // set the speed at 20 rpm:
  myStepper.setSpeed(10);
  pinMode(buttonpin1,INPUT);
  pinMode(buttonpin2,INPUT);
  myservo.attach(5);  
  // initialize the serial port:

  //Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  //Serial.println("clockwise");
  val2=digitalRead(buttonpin2); 
  if(val2==LOW){
    myStepper.step(stepsPerRevolution);
    val1 = digitalRead(buttonpin1);
    if(val1==LOW){
    for (pos = 80; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
       myservo.write(pos);              // tell servo to go to position in variable 'pos'
       delay(15);                       // waits 15ms for the servo to reach the position
     }
     /*
     for (pos = 180; pos >= 80; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
     }*/
  
    }
  
   
    myStepper.step(-stepsPerRevolution);
  

  }

  // step one revolution in the other direction:
  //Serial.println("counterclockwise");
  
}
