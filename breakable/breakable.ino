
#include <HT1632.h>
int ran = 1;
int rose = 1;
int x = 0;
int y = 4;
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
 //matrix.drawPixel(y, x, v); //normal
  matrix.drawPixel(MATRIX_HEIGHT - y - 1, MATRIX_WIDTH - x - 1, v); //flipped
}

byte brick[BRICK_WIDTH][BRICK_HEIGHT]; /*= {    // [rows][columns]
 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};*/
void setup() {
   memset(brick,1,sizeof(brick));
   matrix.begin(HT1632_COMMON_16NMOS);  
}

void loop() {
 
  y += rose;
  x += ran;
  if( y >= BRICK_OFFSET ) {
   
    if(brick[x + ran][y]) 
    { brick[x + ran][y] = 0
    ran = -ran;
    }
    
    if(brick[x][y + rose]) {
      
      brick[x][y + rose] = 0;
      rose = -rose;
    }
   }
  
  }
   

  if(y  >= MATRIX_HEIGHT - 1 || y <= 0) {
   rose = - rose;
 }
 if(x >= MATRIX_WIDTH - 1 || x <= 0 ) {
   ran = -ran;
 }
 
  
 pixelOut(x, y, 1 );
   matrix.writeScreen();
  delay(100);
  matrix.clearScreen();
}

/* check future x and y if theres a block there it will flip it.
