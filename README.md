# brick_breaker
good ol' fashion brick breaker 

#include <HT1632.h>
int ran = 1;
int rose = 1;
int x = 8;
int y = 8;

#define DATA 2
#define WR   3
#define CS   4
#define CS2  5

HT1632LEDMatrix matrix = HT1632LEDMatrix(DATA, WR, CS);

byte rows[8]= { 1, 2, 3, 4, 5, 6, 7, 8};
byte cols[16]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
 11, 12, 13, 16};
 
void setup() {
   matrix.begin(HT1632_COMMON_16NMOS);  
}

void loop() {
 
  y= y + rose;
  x= x + ran;
  
   for(int x1 = 0; x <= 8; x1++) {
   for(int y1 = 0; y1 <= 15; y1++){
     matrix.drawPixel(rows[x1], cols[y1], 1);
    if(y == cols[y1] && x == rows[x1] ) {
    cols[y1] = 26;
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
  
  matrix.drawPixel(x, y, 1);
   matrix.writeScreen();
  delay(100);
  matrix.clearScreen();
}
