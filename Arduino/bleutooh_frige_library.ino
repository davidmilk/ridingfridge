#include <AccelStepper.h>

// Define some steppers and the pins the will use
AccelStepper stepper1(AccelStepper::DRIVER, 11, 9);
AccelStepper stepper2(AccelStepper::DRIVER, 10, 8);

void setup()
{  
  pinMode(12, OUTPUT); // motor 1 enable
  pinMode(13, OUTPUT); // motor 2 enable
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
    stepper1.setMaxSpeed(-500.0);
    stepper1.setSpeed(-500);
    
    stepper2.setMaxSpeed(-500.0);
    stepper2.setSpeed(-500);
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
   
