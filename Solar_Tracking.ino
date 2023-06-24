//#include <Arduino.h>
#include <Servo.h>

// 180 MAX
Servo horizontal; 
int Horizontal_Servo = 180,   
    Horizontal_Servo_LimitHigh = 180,
    Horizontal_Servo_LimitLow = 65
;

// 65 MAX
Servo vertical;    
int Vertical_Servo = 45,    
    Vertical_Servo_LimitHigh = 80,
    Vertical_Servo_LimitLow = 15
;

int LDR_Top_Left = 0,  
    LDR_Top_Right = 1, 
    LDR_Down_Left = 3, 
    LDR_Down_Right = 2
;

int INT_Top_Left,
    INT_Top_Right,
    INT_Down_Left,
    INT_Down_Right,
    Delay_Time,
    INT_Tolerance,
    AVG_Top, 
    AVG_Down, 
    AVG_Left,
    AVG_Right, 
    Vertical_Difference,
    Horizontal_Difference
;

void setup() {
  Serial.begin(9600);

  horizontal.attach(9); 
  vertical.attach(10);
  horizontal.write(180);
  vertical.write(45);

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH); 
  delay(200);                      
  digitalWrite(13, LOW); 
                    
  delay(3000);
}

void loop() {
  INT_Top_Left = analogRead(LDR_Top_Left);
  INT_Top_Right = analogRead(LDR_Top_Right);
  INT_Down_Left = analogRead(LDR_Down_Left);
  INT_Down_Right = analogRead(LDR_Down_Right);

  Delay_Time = 10;
  INT_Tolerance = 50;

  AVG_Top = (INT_Top_Left + INT_Top_Right);
  AVG_Down = (INT_Down_Left + INT_Down_Right);
  AVG_Left = (INT_Top_Left + INT_Down_Left);
  AVG_Right = (INT_Top_Right + INT_Down_Right); 
    
  Vertical_Difference = AVG_Top - AVG_Down;
  Horizontal_Difference = AVG_Left - AVG_Right;
  
    
  if (-1*INT_Tolerance > Vertical_Difference || Vertical_Difference > INT_Tolerance){
    if (AVG_Top > AVG_Down){
        Vertical_Servo++;
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
    
  if (-1*INT_Tolerance > Horizontal_Difference || Horizontal_Difference > INT_Tolerance){
    if (AVG_Left > AVG_Right){
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