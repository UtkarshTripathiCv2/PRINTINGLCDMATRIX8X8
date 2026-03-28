#include "LedControl.h"

// Pin 12 = DIN, Pin 11 = CLK, Pin 10 = CS, 4 = Number of matrices
LedControl lc = LedControl(12, 11, 10, 4);

// Manual Byte Definitions for "RISE"
// Each byte represents one row (8 bits)
byte R[8] = {0xFC, 0x46, 0x46, 0x7C, 0x4C, 0x46, 0x46, 0x00};
byte I[8] = {0x3C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3C};
byte S[8] = {0x3E, 0x60, 0x60, 0x3C, 0x06, 0x06, 0x7C, 0x00};
byte E[8] = {0x7E, 0x40, 0x40, 0x78, 0x40, 0x40, 0x7E, 0x00};

void setup() {
  for(int i=0; i<4; i++) {
    lc.shutdown(i, false);       // Wake up the MAX7219
    lc.setIntensity(i, 5);       // Set brightness
    lc.clearDisplay(i);          // Clear the matrix
  }
}

// Helper function to push the 8 bytes to a specific matrix address
void displayLetter(int address, byte character[]) {
  for(int row=0; row<8; row++) {
    lc.setRow(address, row, character[row]);
  }
}

void loop() {
  // Manually assigning one letter to each of the 4 matrices
  displayLetter(0, R); // First Matrix (leftmost)
  displayLetter(1, I); // Second Matrix
  displayLetter(2, S); // Third Matrix
  displayLetter(3, E); // Fourth Matrix (rightmost)
  
  delay(2000); 
}
