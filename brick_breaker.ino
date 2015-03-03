
#include <HT1632.h>
int ran = 1;
int rose = 1;
int x = 8;
int y = 8;
const byte BRICK_WIDTH = 16;
const byte BRICK_HEIGHT = 8;
const byte BRICK_OFFSET =16;

const byte MATRIX_WIDTH = 16;
const byte MATRIX_HEIGHT= 24;

#define DATA 2
#define WR   3
#define CS   4
#define CS2  5


HT1632LEDMatrix matrix = HT1632LEDMatrix(DATA, WR, CS);

inline void pixelOut(byte x, byte y, byte v) {
 //matrix.drawPixel(x, y, v); //normal
  matrix.drawPixel(MATRIX_HEIGHT - x - 1, MATRIX_WIDTH - y - 1, v); //flipped
}

byte brick[BRICK_HEIGHT][BRICK_WIDTH]; // [rows][columns]
 
void setup() {
   memset(brick,1,sizeof(brick));
   matrix.begin(HT1632_COMMON_16NMOS);  
}

void loop()
{
  
   byte checkD = 0;
   byte checkY = 0;
   byte checkX = 0;
   byte checkW = 0;
   if(y >= 15 || y <= 0)
   {
     checkW = checkY = 1;
   }
   else
   {
     checkY = brick[x][y+rose];
   }
 
   if(x >= 23 || x <= 0)
   {  
     checkW = checkX = 1;
   }
   else
   {
     checkX = brick[x+ran][y];
   }
   if(checkW) 
   { 
     checkD = 1;
   }
   else
   {
     checkD = brick[x+ran][y+ rose];
   }

  
  
  if(checkD) 
  {
     if( !checkX && !checkY)
     {
       checkX = checkY = 1;
     }
     
    if(checkY) 
    {
      if(!checkW)
      { 
        brick[x][y+rose] = 0;
      }
      rose = -rose;
    }
    if(checkX)
    {
      if(!checkW) 
      {
        brick[x+ran][y] = 0;
      }
      ran = -ran; 
    }
  }

    y= y + rose;
  x= x + ran;
  //matrix.drawPixel(x, y, 1);
  pixelOut(x, y, 1 );
   matrix.writeScreen();
  delay(100);
  matrix.clearScreen();
}
