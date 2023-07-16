#ifndef CONFIG_H
#define CONFIG_H

bool debug=false;

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
    Vertical_Servo_LimitLow = 15,
    Delay_Time = 10,
    INT_Tolerance = 50
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
    AVG_Top, 
    AVG_Down, 
    AVG_Left,
    AVG_Right, 
    Vertical_Difference,
    Horizontal_Difference
;



#endif