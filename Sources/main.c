//Chris Hilgenberg
//Lab 6
//2-22-12
//Main funtion for Lab 6

#include <hidef.h>      /* common defines and macros */
     /* derivative-specific definitions */
//#include "defs.h"
#include "protos.h"





void main(void) {
InitializeLCDIO();
InitializeDisplay();
SendData("My Message Longer stuff");
Delay(300000);
SendData("My Short Message");
Delay(300000);

 
}
