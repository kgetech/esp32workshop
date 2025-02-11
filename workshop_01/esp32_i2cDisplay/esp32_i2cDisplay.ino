//Embedded Systems for Everyone esp32_i2cDisplay.ino
//    Copyright (C) 2025  Kyle Goodman
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.

//Include the graphics library that will help us print to the display
#include "lcdgfx.h"

//instantiate a "display" object that has the parameters of the SSD1306_128x32 IIC Display 
DisplaySSD1306_128x32_I2C display(-1);

NanoCanvas<128,32,1> canvas; //instantiate a "canvas" object that is 128 x 32 pixels, monochrome

void setup() {
  // put your setup code here, to run once:
  display.begin(); //initialize the "display" object
  display.fill(0x00); //fill the display with black
  canvas.setMode( CANVAS_MODE_TRANSPARENT ); //define the canvas as having a transparent property (we could layer multiple canvases, but for now we'll stick with one)
  canvas.clear(); //empty the canvas
  
  canvas.setFixedFont(ssd1306xled_font8x16); //define the font shapes that we'll be using to print text to the canvas
  //You can also print directly to the display, but we are using the canvas to allow us to rotate the text, when printing to the display, it is fixed to the display's orientation.
  //display.printFixed (0,  8, "Line 1. Normal text", STYLE_NORMAL);
  //display.printFixed (0, 16, "Line 2. Bold text", STYLE_BOLD);
  //display.printFixedN (0, 32, "Line 4. Double size", STYLE_BOLD, FONT_SIZE_2X);
}

void loop() {
  char test_str[30] = "TESTIG TESING 1 2 4"; //create an array of characters (this is known as a "string", hence "str"), and store text in the array
  for(int i=0; i < 30; i++){ //for the number of characters in test_str
    delay(100); //delay 100ms
    canvas.clear(); //clear the canvas
    canvas.printFixed (-8*i, 16, test_str, STYLE_NORMAL); //write the string's characters to the canvas, but start the string "i" number of characters off the canvas.
    lcd_delay(40); //delay 40ms
    display.drawCanvas(0,0,canvas); //print the current canvas to the display (it's not rotated now, but we'll use that feature later).
  }  
}
