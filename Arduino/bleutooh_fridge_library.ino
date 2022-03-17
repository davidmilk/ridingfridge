#include <AccelStepper.h>
#include <RGBLed.h>
RGBLed led(6,k,i,k;; 5, 3, RGBLed::COMMON_CATHODE);
const int redPin = 6;
const int greenPin = 5;
const int bluePin = 3;
// Define some steppers and the pins the will use
AccelStepper stepper1(AccelStepper::DRIVER, 11, 9);
AccelStepper stepper2(AccelStepper::DRIVER, 10, 8);

void setup()
{  

  pinMode(12, OUTPUT); // motor 1 enable
  pinMode(13, OUTPUT); // motor 2 enable
  //leds
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(3, OUTPUT); 
  digitalWrite(redPin, HIGH);
digitalWrite(greenPin, HIGH);
digitalWrite(bluePin, HIGH);
  Serial.begin(9600);
    digitalWrite(2, HIGH); //led
          stepper1.setMaxSpeed(0);
          stepper1.setSpeed(0);
    
          stepper2.setMaxSpeed(0);
          stepper2.setSpeed(0);
    
}

void loop() {
  
          stepper1.runSpeed();
          stepper2.runSpeed();
  // put your main code here, to run repeatedly:
 if(Serial.available()>0)
   {     
      char data= Serial.read(); // reading the data received from the bluetooth module
      switch(data)
      {
        case '0':{
digitalWrite(redPin, HIGH);
digitalWrite(greenPin, HIGH);
digitalWrite(bluePin, HIGH);
          break;
        }
case '1':{
digitalWrite(redPin, LOW);
digitalWrite(greenPin, HIGH);
digitalWrite(bluePin, HIGH);
          break;
        }
        case '2':{
digitalWrite(redPin, HIGH);
digitalWrite(greenPin, LOW);
digitalWrite(bluePin, HIGH);
          break;
        }
        case '3':{
digitalWrite(redPin, HIGH);
digitalWrite(greenPin, HIGH);
digitalWrite(bluePin, LOW);
          break;
        }
                case '4':{
digitalWrite(redPin, LOW);
digitalWrite(greenPin, HIGH);
digitalWrite(bluePin, LOW);
          break;
        }
        case '5':{
digitalWrite(redPin, LOW);
digitalWrite(greenPin, LOW);
digitalWrite(bluePin, HIGH);
          break;
        }  
        case '6':{
digitalWrite(redPin, HIGH);
digitalWrite(greenPin, LOW);
digitalWrite(bluePin, LOW);
          break;
        }
                case '7':{
  led.flash(RGBLed::RED, 100);

  // Flash green color, interval 100ms
  led.flash(0, 255, 0, 100);

  // Flash red color, during 250ms with interval 100ms
  led.flash(RGBLed::RED, 250, 100);

  // Flash green color, during 250ms with interval 100ms
  led.flash(0, 255, 0, 250, 100);
          break;
        }
        case 'a':{//vooruit aan
    stepper1.setMaxSpeed(-900.0);
    stepper1.setSpeed(-900);
    
    stepper2.setMaxSpeed(900.0);
    stepper2.setSpeed(900);
          break;
        }
        case 'b':{//vooruit uit
          stepper1.setMaxSpeed(0);
          stepper1.setSpeed(0);
    
          stepper2.setMaxSpeed(0);
          stepper2.setSpeed(0);
          break;
        }
                case 'c':{//lings aan
    stepper1.setMaxSpeed(-500.0);
    stepper1.setSpeed(-500);
    
    stepper2.setMaxSpeed(-500.0);
    stepper2.setSpeed(-500);
          break;
        }
        case 'd':{//lings uit
          stepper1.setMaxSpeed(0);
          stepper1.setSpeed(0);
    
          stepper2.setMaxSpeed(0);
          stepper2.setSpeed(0);
 break;
        }
                case 'e':{//recht aan
    stepper1.setMaxSpeed(500.0);
    stepper1.setSpeed(500);
    
    stepper2.setMaxSpeed(500.0);
    stepper2.setSpeed(500);
          break;
        }
        case 'f':{//rechts uit
          stepper1.setMaxSpeed(0);
          stepper1.setSpeed(0);
    
          stepper2.setMaxSpeed(0);
          stepper2.setSpeed(0);
          break;
      }
                      case 'g':{//achteruit aan
    stepper1.setMaxSpeed(400.0);
    stepper1.setSpeed(400);
    
    stepper2.setMaxSpeed(-400.0);
    stepper2.setSpeed(-400);
          break;
        }
        case 'h':{//acheruit uit
          stepper1.setMaxSpeed(0);
          stepper1.setSpeed(0);
    
          stepper2.setMaxSpeed(0);
          stepper2.setSpeed(0);
        break;
        }
    case 'i':{//enable motor
    digitalWrite(13, LOW); //enable motor1
    digitalWrite(12, LOW); //enable motor2
          break;
        }
        case 'j':{//disable motor
    digitalWrite(13, HIGH); //disable motor1
    digitalWrite(12, HIGH); //disable motor2
        default : break;
        }
      }
      Serial.println(data);
   }
   }
   
