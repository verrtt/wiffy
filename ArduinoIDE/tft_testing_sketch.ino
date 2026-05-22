#include "tft_setup.h"
#include <TFT_eSPI.h>

/*
setup code is from: https://www.makerguides.com/interface-tft-ili9341-touch-display-with-esp32/#ESP32_lite and modified based on my project needs

libraries used:
  - TFT_eSPI
*/

TFT_eSPI tft = TFT_eSPI();
uint16_t cal[5] = { 0,0,0,0,0 } ; // CALIBRATION VALUES: to recalibrate, set all values to 0

void calibrate_touch() { //calibration using TFT_eSPI library
  if (!cal[1]){
    tft.fillScreen(TFT_BLACK);
    tft.calibrateTouch(cal, TFT_YELLOW, TFT_BLACK, 20); //
    Serial.printf("cal[5] = { %d, %d, %d, %d, %d}\n", cal[0], cal[1], cal[2], cal[3], cal[4]) //prints the cal data
  }
}

void setup(void) { //make sure no parameters are passed
  Serial.begin(115200);

  tft.init();
  tft.setRotation(1);
  calibrate_touch();
  tft.setTouch(cal);

  tft.fillScreen(TFT_BLACK);
  tft.setTextFont(1);
  tft.setTextSize(2);
  tft.setTextColor(TFT_WHITE,TFT_BLACK);
  tft.setTextDatum(CC_DATUM);

  tft.drawString("Your code works!", TFT_HEIGHT / 2, TFT_WIDTH / 2); //displays the text, y, x
}

void loop() {
  uint16_t x,y;
  if (tft.getTouch(&x, &y)) {
    Serial.printf("%d %d\n", x , y);
    tft.fillCircle(x,y,1, TFT_YELLOW);
  }
}
