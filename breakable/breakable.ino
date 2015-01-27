
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

byte brick[MATRIX_HEIGHT][5] = {    // [rows][columns]
 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
void setup() {
   memset(brick,1,sizeof(brick));
   matrix.begin(HT1632_COMMON_16NMOS);  
}

void loop() {
 
  y= y + rose;
  x= x + ran;
  
   for(int x1 = 0; x1 <BRICK_HEIGHT; x1++) {
   for(int y1 = 0; y1 < BRICK_WIDTH; y1++){
    if(brick[x1][y1]) 
    {
    pixelOut(x1 + BRICK_OFFSET, y1, 1);
   }
 }
 }
  if(y >= 15 || y <= 0) {
   rose = - rose;
 }
 if(x >= 23) {
   ran = -ran;
 }
 if(x <= 0) {
   ran = -ran;
 }
  
  //matrix.drawPixel(x, y, 1);
   matrix.writeScreen();
  delay(100);
  matrix.clearScreen();
}
