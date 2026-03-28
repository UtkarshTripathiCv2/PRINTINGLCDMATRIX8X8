#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Define hardware type (Most 4-in-1 modules use FC16_HW)
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4 // You have 4 matrices

#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

// Hardware SPI setup (faster and smoother)
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  myDisplay.begin();           // Initialize the object
  myDisplay.setIntensity(5);   // Set brightness (0-15)
  myDisplay.displayClear();    // Clear the display
  
  // print(text, alignment, speed, pause, effectIn, effectOut)
  myDisplay.displayText("RISE", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
}

void loop() {
  if (myDisplay.displayAnimate()) {
    myDisplay.displayReset();
  }
}
