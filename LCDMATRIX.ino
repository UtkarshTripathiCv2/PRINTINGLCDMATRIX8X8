#include "LedControl.h"

// Pin 12 = DIN, Pin 11 = CLK, Pin 10 = CS, 4 = Number of matrices
LedControl lc = LedControl(12, 11, 10, 4);

byte R[8] = {0xFC, 0x46, 0x46, 0x7C, 0x4C, 0x46, 0x46, 0x00};
byte I[8] = {0x3C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3C};
byte S[8] = {0x3E, 0x60, 0x60, 0x3C, 0x06, 0x06, 0x7C, 0x00};
byte E[8] = {0x7E, 0x40, 0x40, 0x78, 0x40, 0x40, 0x7E, 0x00};

// This function flips the bits in a byte (Mirrors it horizontally)
byte reverseBits(byte b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return b;
}

void setup() {
  for(int i=0; i<4; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i, 5);
    lc.clearDisplay(i);
  }
}

void displayLetterFlipped(int address, byte character[]) {
  for(int row = 0; row < 8; row++) {
    // We reverse the bits and send them to the opposite row index (7 - row)
    byte flippedByte = reverseBits(character[row]);
    lc.setRow(address, 7 - row, flippedByte);
  }
}

void loop() {
  // If your matrices are physically wired 0-1-2-3 but the 
  // word is backwards, you might need to change these addresses too!
  displayLetterFlipped(0, R); 
  displayLetterFlipped(1, I); 
  displayLetterFlipped(2, S); 
  displayLetterFlipped(3, E); 
  
  delay(2000);
}
