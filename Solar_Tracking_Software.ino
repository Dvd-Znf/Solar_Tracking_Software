//#include <Arduino.h>
#include <Servo.h>
#include "config.h"

void setup() {
  Serial.begin(9600);

  horizontal.attach(9); 
  vertical.attach(10);
  horizontal.write(180);
  vertical.write(45);
  
  if(debug){
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH); 
  delay(200);                      
  digitalWrite(13, LOW);
  }
                     
  delay(3000);
}




void loop() {
  INT_Top_Left = analogRead(LDR_Top_Left);
  INT_Top_Right = analogRead(LDR_Top_Right);
  INT_Down_Left = analogRead(LDR_Down_Left);
  INT_Down_Right = analogRead(LDR_Down_Right);


  AVG_Top = (INT_Top_Left + INT_Top_Right);
  AVG_Down = (INT_Down_Left + INT_Down_Right);
  AVG_Left = (INT_Top_Left + INT_Down_Left);
  AVG_Right = (INT_Top_Right + INT_Down_Right); 
    
  Vertical_Difference = AVG_Top - AVG_Down;           //Use less cpu time but more memory? 
  Horizontal_Difference = AVG_Left - AVG_Right;
  
    
  if (-1*INT_Tolerance > Vertical_Difference || Vertical_Difference > INT_Tolerance){           //why????
    if (AVG_Top > AVG_Down){                                                                    //Put && here and at 49 
        Vertical_Servo++;                                                                       //TODO  ^^^
        switch((Vertical_Servo > Vertical_Servo_LimitHigh)){
          case 1: Vertical_Servo = Vertical_Servo_LimitHigh; break;
          default: break;
        } 
    }
    else if (AVG_Top < AVG_Down){
      Vertical_Servo--;
      switch((Vertical_Servo < Vertical_Servo_LimitLow)){
          case 1: Vertical_Servo = Vertical_Servo_LimitLow; break;
          default: break;
        }
    }
    vertical.write(Vertical_Servo);
  }
    
  if (-1*INT_Tolerance > Horizontal_Difference || Horizontal_Difference > INT_Tolerance){     //This seems redundant
    if (AVG_Left > AVG_Right){                                                                //TODO: make one function
      Horizontal_Servo--;
      switch((Horizontal_Servo < Horizontal_Servo_LimitLow)){
        case 1: Horizontal_Servo = Horizontal_Servo_LimitLow; break;
        default: break;
      }
    }
    else if (AVG_Left < AVG_Right){
      Horizontal_Servo++;
      switch((Horizontal_Servo > Horizontal_Servo_LimitHigh)){
        case 1: Horizontal_Servo = Horizontal_Servo_LimitHigh; break;
        default: break;
      }
    }
    horizontal.write(Horizontal_Servo);
  }
  
  delay(Delay_Time);
}