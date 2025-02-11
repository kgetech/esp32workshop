//Embedded Systems for Everyone esp32_cardDisplay.ino
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
//Include SPI, SD, and FS libraries
#include "lcdgfx.h"
#include "SPI.h"
#include "SD.h"
#include "FS.h"


//Define values for pins
#define SD_CS 5
#define SD_SCK 18
#define SD_MOSI 21
#define SD_MISO 19

//create a global error handling flag
int error_level = 0;

// Initialize I2C Display
DisplaySSD1306_128x32_I2C display(-1);

// Instantiate NanoCanvas
NanoCanvas<128,32,1> canvas;
NanoCanvas<32,128,1> rCanvas;

// Instantiate file handler.
File file;

// Create text pointer
char* text_ptr = NULL;

// Initialize Text Length Value
int size_file = 0;

void working_anim() {
  Serial.print("|");
  Serial.write('\r');
  delay(125);
  Serial.print("/");
  Serial.write('\r');
  delay(125);
  Serial.print("\\");
  Serial.write('\r');
  delay(125);
}

void setup() {
  //Initialize Display
  display.begin();
  display.fill(0x00);

  //Initialize canvas
  canvas.setMode( CANVAS_MODE_TRANSPARENT );
  canvas.clear();
  
  //Set font to use on canvas.
  canvas.setFixedFont(ssd1306xled_font8x16);
  
  // Initialize Serial for debugging
  Serial.begin(115200);
  while (!Serial) working_anim();
  Serial.println("Serial Initialized.");
  
  // Initialize SPI for SD Card
  Serial.println("Initializing SPI connection to SD Card");
  int sd_flag = 0;
  SPI.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);
  while(!SD.begin(SD_CS)){
    working_anim();
    sd_flag++;
    if(sd_flag > 9) {
      Serial.println("\r\n SD Failed to connect.");
      error_level++;
      while(true){
        Serial.println("Check connections and pin assignments, then reset the microcontroller.");
        delay(1000); //wait 1 second (1000ms)
      }
    }
  }
  if(sd_flag <= 9){
    Serial.println("SD Card Connected!");
    Serial.println("Testing card.");
    file = SD.open("/test", FILE_WRITE);
    if (SD.exists("/test")){
      Serial.println("Write test was successful.");
      SD.remove("/test");
    } else {
      Serial.println("Write test FAILED.");
      error_level++;
    }
    file.close();
  }
  if(!SD.exists("/displayText.txt")){
    file = SD.open("/displayText.txt", FILE_WRITE);
    file.println("When learning the complicated process of embedded systems development, it is good to recall the famous words written in Douglas Adams' The Hitchhiker's Guide to the Galaxy: \"DON'T PANIC!\"");
  }else{
    file = SD.open("/displayText.txt", FILE_READ);
  }
  size_file = file.size();
  if(size_file){
    text_ptr =(char*)malloc(size_file*sizeof(char));
    file.read((uint8_t*)text_ptr, size_file);
  } else {
    Serial.println(" ");
    Serial.println("displayText.txt was empty, or did not exist.");
    error_level++;
  }
  file.close();
}

void loop() {
  // put your main code here, to run repeatedly:for(int i=0; i < 30; i++){
  if(!error_level){  
    for(int i=0; i < size_file; i++){
      delay(100);
      canvas.clear();
      canvas.printFixed (-8*i, 16, text_ptr, STYLE_NORMAL);
      canvas.rotateCW(rCanvas);
      rCanvas.rotateCW(canvas);
      lcd_delay(40);
      display.drawCanvas(0,0,canvas);
    }
  }  
}
