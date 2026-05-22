//tft setup
//Hosyond 3.2" TFT LCD
// 320 x 240 (48.6 x 64.8(mm))

#define ILI9341_DRIVER

#define TFT_WIDTH   240
#define TFT_HEIGHT  320
#define TFT_RGB_ORDER TFT_BGR

#define TFT_CS    1 //these numbers = pin numbers of esp32 connections 
#define TFT_RST   7
#define TFT_DC    8 
#define TFT_MOSI  4 //DOUBLE CHECK MOSI,SCLK,MISO,BL,BACKLIGHT & MAKE SURE THAT THEY'RE CORRECT
#define TFT_SCLK  26
#define TFT_MISO  13 
#define TFT_BL    11 
#define TFT_BACKLIGHT_ON HIGH

#define TOUCH_CS 1
#define TOUCH_CLK TFT_SCLK
#define TOUCH_DIN TFT_MOSI
#define TOUCH_DO TFT_MISO

#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF
#define SMOOTH_FONT

#define SPI_FREQUENCY 27000000
#define SPI_READ_FREQUENCY 20000000
#define SPI_TOUCH_FREQUENCY 2500000


