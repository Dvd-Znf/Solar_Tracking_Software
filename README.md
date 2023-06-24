# Solar Tracking Software  
## Simple and readable software made for a simple solar tracker.    
Just as the title says this is a repo containing software for a simple solar tracker.   
## Hardware:  
- Arduino UNO compatible microcontroller board (Anything may work but it would need changes)   
- Optional: Some kind of expansion board, tested on sensor shield v5.0   
- 4 Photoresistors(LDR), prefarably in a single Photosensitive array   
- 2 PWM controlled micro-servomotors     
## Default Pinout:  
The Pinout can and should be changed, depending on your circumstances, from the source code.      
The following will describe connection for a tippical Arduino UNO board:    
     
Built in LED (pin 13) is used for debugging, because serial monitoring is always broken.   
Feel free to connect a small speaker to it for nice audio feedback.    
     
Horizontal servomotor -> pin 9 (PWM)   
Vertical servomotor -> pin 10 (PWM)   
These can be changed from the source code where `Servo horizontal;` and `Servo vertical;` are parsed to `atach(/*value of pin here*/)`    
      
LDR Top Left   -> A0 (Analog IN)    
LDR Top Right  -> A1 (Analog IN)    
LDR Down Left  -> A3 (Analog IN)    
LDR Down Right -> A2 (Analog IN)    
These can be changed from where they are initially declared:   
```
int LDR_Top_Left = /*value of pin here*/,  
    LDR_Top_Right = /*value of pin here*/, 
    LDR_Down_Left = /*value of pin here*/, 
    LDR_Down_Right = /*value of pin here*/
;
```
      
VCC is connected to 5V (Or whatever you need) and GND is connected to Ground like ussually.   
    
## Software dependencies:   
| Library | Header File | Reason |
| ------------- | ------------- | ------------- |
| Arduino C++ librarys | `//#include <Arduino.h>` | Included with most compillers (Normally commented out)  |     
| Arduino Servomotor library | `#include <Servo.h>` | Provides neccessary functions and methods for controlling servomotors  |    
 
## Important Notes regarding IDE and Compiler:
| Text Editor | Compiler | OS | Vscode extension | Board Config | Serial Port |
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
| Vscode | avr-gcc | GNU/Linux | Arduino from Microsoft | Arduino UNO | /dev/ttyACM0 |   
    
The workspace provided is configured for _Vscode_ on _Linux_ using _avr-gcc_ and _Arduino extension from Microsoft_.   
The board config is set to _Arduino UNO_ and Serial Port is on _`/dev/ttyACM0`_     
You should delete and reconfigure config files stored under `.vscode` using the Arduino extension if you are on a different envierment.   
*Warning:* Untested on Arduino IDE, wierd things might happen if you try to open this workspace.    

## Credit:
Blog post providing initial information and instruction for dual-axis solar tracking: [Original Blog Post](https://www.instructables.com/Simple-Dual-Axis-Solar-Tracker/)