//Chris Hilgenberg
//Used for Labs 6&7
//2/22/12
//LCD.c is used to initialize the LCD and Read/Write Data and commands to it.

#include "defs.h"
#include "protos.h"

#define HOME_DISPLAY 0x02
#define CLEAR_DISPLAY 0x01
#define SECOND_LINE 0xC0

void InitializeLCDIO()  //Initializes the starting state of the I/O for LCD.
{
  DDRK.ddrk=0xff;
  DDRD.ddrd=0xe0;
  InitializeDisplay();
}

void InitializeDisplay() //Creates blinking cursor after sending code to LCD.
{
  int count = 0;
  unsigned char Initialize[] = {0x30,0x30,0x30,0x38,0x0f,0x01,0x06}; //The bits required to initialize the display
  for(count=0;count<7;++count)
  {
    Write();
    Command();
    PORTK.portk = Initialize[count];
    Toggle();
    Delay(1000);
  }
}

void Toggle()   //Used to toggle enable of LCD PORTD
{
  PORTD.ENABLE=1;
  PORTD.ENABLE=0;
  Delay(1000);
}

void Write()  //Changes LCD to Write Enable
{
  PORTD.RSLINE = 1;
  PORTD.RWLINE = 0;
}
void Command() //Changes LCD to accept Writing Commands
{
  PORTD.RWLINE = 0;
  PORTD.RSLINE = 0;
}
void Read()     //Changes LCD to Read Enable
{
  PORTD.RWLINE = 1;
  PORTD.RSLINE = 0;
}

void Delay(long time) //Delays for time value sent to it
{
  while(time!=0)
  {
    --time;
  }
}
void Data()  //Changes LCD to accept Writing Data to the display
{
  PORTD.RSLINE = 1;
}
void SendData(char* message)  //Accepts a message and writes it to the LCD.
{
  int index = 0;
  while (message[index]!=0x00)
  {
    if(index==0)
    {
     ResetDisplay();
    }
    if(index==16) //16 characters fit on a line
    {
      SecondLine();
      Delay(30000);
    }
    
    Write();
    Data();
    PORTK.portk = message[index];
    BusyCheck();
    
    Toggle();
    
    ++index;
  }
}
 void ResetDisplay() //This will clear the display and return the cursor back to the home position
 {
  Write();
  Command();
  PORTK.portk = CLEAR_DISPLAY;
  Toggle();
  PORTK.portk = HOME_DISPLAY;
  Toggle();
  Delay(1000);
 }
 
 void ReadK() //Sets Port K to be read
 {
  DDRK.ddrk = 0x00;
 }
 
 void WriteK() //Sets Port K to be written
 {
  DDRK.ddrk = 0xff;
 }
 
 void ELOW() //Takes the enable line for commands low
 {
  PORTD.ENABLE=0;
 }
 
 void EHIGH() //Takes the enable line for commands high
 {
  PORTD.ENABLE=1;
 }
 
 void SecondLine() //After reaching end of first line of LCD, this will start the second line for a message
 {
  Write();
  Command();
  PORTK.portk = SECOND_LINE;
  Toggle();
  Delay(1000);
 }
 void BusyCheck() //This function will send one character to the LCD at a time and will wait for the next chatacter if the function is waiting on writing to be completed.
 {
   char doneFlag = 0;
   Read();
   ReadK();
   Command();
   ELOW();
   while(doneFlag==0)
   {
    EHIGH();
    if(PORTK.kportbits.Bit7==0)
    {
      doneFlag = 1;
    }
    ELOW();
    WriteK();
   }
 }

   


  
  