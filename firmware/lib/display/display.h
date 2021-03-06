#ifndef DISPLAY_H
#define DISPLAY_H

#include <inttypes.h>

namespace PIOC {

/*
https://learn.adafruit.com/adafruit-2-8-and-3-2-color-tft-touchscreen-breakout-v2/pinouts
CLK - this is the SPI clock input pin
MISO - this is the SPI Microcontroller In Serial Out pin, its used for the SD card mostly, and for debugging the TFT display. It isn't necessary for using the TFT display which is write-only
MOSI - this is the SPI Microcontroller Out Serial In pin, it is used to send data from the microcontroller to the SD card and/or TFT
CS - this is the TFT SPI chip select pin
D/C - this is the TFT SPI data or command selector pin
RST - this is the TFT reset pin. There's auto-reset circuitry on the breakout so this pin is not required but it can be helpful sometimes to reset the TFT if your setup is not always resetting cleanly. Connect to ground to reset the TFT
*/
// DISPLAY
// https://github.com/adafruit/TFTLCD-Library

//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

#define TOUCH_Y1 A2//34
#define TOUCH_X1 A3//39
#define TOUCH_Y2 A4//36
#define TOUCH_X2 A5//4

// SPI Display
#define TFT_RST 15
#define TFT_DC 32
#define TFT_CS 14
#define TFT_MOSI 18
#define TFT_MISO 19
#define TFT_CLK 5

// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

class PIOC_Display {
    public:
        PIOC_Display(){};

        void displayInit();
        void startScreen();
        void debugScreen();
        void updateDebugScreen(char s);
        void valveState(uint32_t vs, uint8_t state);
        void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
        uint16_t color_convert(uint8_t red, uint8_t green, uint8_t blue);
        void drawButton();
        void updateGraph();
};

}
#endif
