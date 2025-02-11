//Embedded Systems for Everyone readme.md
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
#include "SPI.h"
#include "SD.h"
#include "FS.h"


//Define values for pins
#define SD_CS 5
#define SD_SCK 18
#define SD_MOSI 17
#define SD_MISO 19

//create a global error handling flag
int error_level = 0; //if an error happens, the value will be nonzero.

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
 
  // Initialize Serial for debugging
  Serial.begin(115200);
  while (!Serial) working_anim();
  Serial.println("Serial Initialized.");
  
  // Initialize SPI for SD Card
  Serial.println("Initializing SPI connection to SD Card");
  int sd_flag = 0; //sd_flag will increment in the while loop below, every time the loop is unsuccsessful.
  SPI.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);
  while(!SD.begin(SD_CS)){
    working_anim();
    sd_flag++;
    if(sd_flag > 9) { //once sd_flag has incremented to 9, the failed message will print to the serial monitor.
      Serial.println("\r\n SD Failed to connect.");
      error_level++;
      while(true){ // Prints error message until the end of time. 
        Serial.println("Check connections and pin assignments, then reset the microcontroller.");
        delay(1000); //wait 1 second (1000ms)
      }
    }
  }
  if(sd_flag <= 9){ //if the above loop terminated, the SD card connected. So we can begin testing the SD Card.
    Serial.println("SD Card Connected!");
    Serial.println("Testing card.");
    file = SD.open("/test", FILE_WRITE); //creates an empty file "test" to the root directory of the device
    if (SD.exists("/test")){ //tests to see if the file was successfully created.
      Serial.println("Write test was successful.");
      SD.remove("/test"); //removes the test file.
    } else {
      Serial.println("Write test FAILED.");
      error_level++;
    }
    file.close(); //closes the file, which disconnects the file handler from the test file. 
  } 
  //////////Preparing the text file we'll be displaying to the screen.
  if(!SD.exists("/displayText.txt")){ //if the file "displayText.txt does not exist"
    file = SD.open("/displayText.txt", FILE_WRITE); // create file displayText.txt and attach it to the file handler
    //write the following text to the open file displayText.txt
    file.println("When learning the complicated process of embedded systems development, it is good to recall the famous words written in Douglas Adams' The Hitchhiker's Guide to the Galaxy: \"DON'T PANIC!\"");
  }else{ //if the file displayText.txt already exists
    file = SD.open("/displayText.txt", FILE_READ); //open the file displayText.txt for a read operation and associate it with the file handler.
  }
  size_file = file.size(); //get length of the open file displayText.txt in bytes
  if(size_file){ //if the file has text (its length will not be zero and a nonzero value is treated as "true")
    text_ptr =(char*)malloc(size_file*sizeof(char)); //allocate a memory area in the microcontroller to store an array of characters the same size as the file.
    file.read((uint8_t*)text_ptr, size_file); //read the file displayText.txt and store the data into the microcontroller's memory.
  } else { //if the size of the file was 0, print error message:
    Serial.println(" ");
    Serial.println("displayText.txt was empty, or did not exist.");
    error_level++;
  }
  file.close(); //close the file handler, disassociating it with the opened displayText.txt file
}

void loop() {
  // put your main code here, to run repeatedly (same as while(true))
  if(!error_level){ //if no error occurred
    Serial.println(text_ptr); //prnt the text stored at text_ptr position in microcontroller memory to the serial monitor.
  }
  delay(1000); //wait 1 second (1000ms)
}
