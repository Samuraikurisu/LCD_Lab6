//Chris Hilgenberg
//Used for Labs 6&7
//2-22/12
//Definitions for LCD.c and Main.
//Be sure not to include derivative/microprocessor.c file


typedef unsigned char UCHAR;

struct CONTROLLINES    //PortD used to Control LCD
{
  UCHAR Bit0 :1;
  UCHAR Bit1 :1;
  UCHAR Bit2 :1;
  UCHAR Bit3 :1;
  UCHAR Bit4 :1;
  UCHAR RSLINE :1;
  UCHAR RWLINE :1;
  UCHAR ENABLE :1;
} PORTD@0x05; 
struct DDataDirection    //DDRD used to flow IO for LCD
{
  UCHAR Bit0 :1;
  UCHAR Bit1 :1;
  UCHAR Bit2 :1;
  UCHAR Bit3 :1;
  UCHAR Bit4 :1;
  UCHAR Bit5 :1;
  UCHAR Bit6 :1;
  UCHAR Bit7 :1;
};// DDRD@0x07;
union DDATA_UNION
{
  UCHAR ddrd;
  struct DDataDirection ddatabits;
};
volatile union DDATA_UNION DDRD@0x07;

struct KDataDirection         //DDRK is used to flow IO for LCD
{
  UCHAR Bit0 :1;
  UCHAR Bit1 :1;
  UCHAR Bit2 :1;
  UCHAR Bit3 :1;
  UCHAR Bit4 :1;
  UCHAR Bit5 :1;
  UCHAR Bit6 :1;
  UCHAR Bit7 :1;
};// DDRK@0x33;
union KDATA_UNION
{
  UCHAR ddrk;
  struct KDataDirection kdatabits;
};
volatile union KDATA_UNION DDRK@0x33;    //PORTK writes to LCD

struct KPort
{
  UCHAR Bit0 :1;
  UCHAR Bit1 :1;
  UCHAR Bit2 :1;
  UCHAR Bit3 :1;
  UCHAR Bit4 :1;
  UCHAR Bit5 :1;
  UCHAR Bit6 :1;
  UCHAR Bit7 :1;
}; //PORTK@0x32; 
union KPORT_UNION
{
  UCHAR portk;
  struct KPort kportbits;
};
volatile union KPORT_UNION PORTK@0x32;