# Welcome to Embedded Systems for Everyone
We'll be learning how to program an ESP32 Microcontroller, but we're not going to start with blinky. Often, people fear programming because it seems too complicated, and after learning the basics, they just stop. While this workshop is aimed at teaching anyone to develop basic embedded systems, it won't be easy, but I hope it will be more fun than blinking an LED.

## Repository Structure
You will notice that the repository will be broken down by workshop sessions, and in each session there will typically be several folders that each include a component part of the workshop in the form of an Arduino .ino project. I will not sugar-coat this, these .ino files are basically Arudino-flavored C++. What this means is that I hope you will leave here with some knowledge and experience in programming one of the most widely used programming languages in the world. Understanding C++ will give you the capacity to learn other similar languages, like C, C#, or even languages like Cg/GLSL/HLSL which can be used to create complex graphics shaders for video games and even GPU-accelerated data processing. Of course, this is not a plug for Computer Science, or for Electrical and Computer Engineering: these skills can benefit any profession, because they allow for one of the most impressive inventions of human kind: automation. Not too long ago, entire buildings were filled with people manually performing basic arithmetic for businesses, but now this can all be handled by a single computer with a spreadsheet software. With automation, we can hand off tasks that we don't want to do, or simply can't do to a computer system that can perform these tasks for us.

### Goal
This leads us to the goal of this workshop, to teach you how to use these tiny computers known as microcontrollers to create IoT (internet of things) ready devices to perform basic tasks for you, like take measurements of soil moisture level, atmospheric humidity, or even to turn your livingroom into an RGB-LED lit gaming zone. But most of all, I hope you learn that programming can be fun, and that these electronic devices can not only be understood, but can be used by anyone to ***create awesome things!***

## Workshop 1: SD Cards and LCD Displays
Let me begin by repeating that this will not be easy, but this is our "blinky", our "Hello World" of this workshop series. You will not necessarily walk away understanding every line of code you will see, but you will at-least be able to print custom text to a little monochrome display. I chose this, because this is where I first stopped. Yes, everyone can blink an LED, and many people go on to spin a fan motor, or turn a servo's arm--but that SD Card, **that thing is scary.** 

#### SD Cards
Well, ***scary-cool*** that is! The ESP32 microcontrollers have embedded memory , that is, memory that is included right on the same microchip as the processor. The embedded memory is only a few MB at most, and while a few million bytes is still very useful, by adding a small 2GB SD card, we've multiplied how much data we can store by a factor of 1000. The only caveat is that the data write and read speeds are much slower. So, why is this so cool? Well, it means that we can store years worth of simple weather data on our tiny embedded system, and with the WiFi features available in the ESP32, we can request those measurements from any computer connected to the same network (provided that we write software capable of sending files over WiFi). To take this idea further, we could attach a camera to our system, and register users by taking pictures of their faces and storing them to the SD card. Then, we could use a facial recognition software to allow those users to unlock a door controlled by our embedded system. Not to sound hyperbolic, but the possibilities are really quite endless. There's no better way to demonstrate the power of information, than to allow yourself to dream of what you could do with so much ***storage spaaaace!***

#### Displays
Okay, so memory is cool, because you can do stuff with data. So, let's do something with data, let's write a basic text file to the SD Card and...
...print it to a display! For those who are initiated into the world of Arduino-based embedded systems development, we can use something called the "Serial Monitor" to read messages sent via USB (universal serial bus) to our computer from the microcontroller. So, technically, we could just use our computers as displays to read the text stored on the SD Card connected to our microcontroller--but where's the fun in that? Isn't the point of these devices to have independent systems that operate without needing to be directly connected to another computer? Well, yes, that's the point! So, we're going to set-up our first **HID** (Human Interface Device). These are devices that allow humans to interact with computers, and ours is an LCD display. This LCD Display is 128x32 pixels, and it's monochrome ("mono" meaning one "chrome" meaning color, this one happens to be cyan). In order to do so, we'll be using a library called **lcdgfx** (https://github.com/lexus2k/lcdgfx), which is a highly optimized graphics display driver framework for printing to small LCD displays like the one we'll be using for this workshop. Now, you might be wondering, "what's this about a library?" Well, in programming, a **library** is a bundle of pre-written code that enables you to do very complex tasks with very little programming. In other words, some other programmer has taken their work, and made it available for you to use. Libraries can serve a number of functions, including providing support for **peripheral devices** like the LCD display we'll be using in this workshop. To use a term from Computer Science, libraries are **Abstraction Layers** which "abstract away" the complicated "boilerplate" portions of code, so that you can spend more time building cool stuff. Now, that's not to say it isn't important to understand the conecepts that are "abstracted away" in libraries, and we will get there eventually, but for a beginner, a good metaphor is that you first need to learn how to drive a car. If you like what you see, you can learn how to rebuild the engine later.

Okay, enough talking...

Let's start with our:
### Bill of Materials
- 1x DOIT ESP32 DevKit V1(or Elegoo, or any of the similar ESP32 development board clones)
- 1x SSD1306 128x32 IIC LCD display
- 1x SPI MicroSD Card Adaptor
- 1x 2GB MicroSD Card
- 1x Small Solderless Breadboard
- 1x ESP32 Breakout board
- 1x IEEE HKN Theta Pi Base-board
- 10 or so Male to Female DuPont Connector Jumper Cables
- 1x USB to USB-C data-capable Cable

### Process 
#### Setting-up the IDE
1. Install Git, Git for windows, or Github's application (there are plenty of instructions online, google wisely).
2. git clone this repository to a folder on your computer.
3. Install the Arduino IDE (https://docs.arduino.cc/software/ide/).
4. Navigate to "Tools" > "Board" > "Boards Manager".
5. Search for "esp32 by Espressif Systems".
6. Select version 2.0.17, and install (you may select a newer version, or for a different ESP32 board, but I cannot guarantee that the workshop's code will work correctly).
7. Navigate to "Tools" > "Manage Libraries".
8. Install version 1.1.5 (again, you may select a newer version if one exists, but I cannot guarantee that the workshop's code will work).
9. Plug in your ESP32 via USB-C (or other cable).
10. Click on the "Select Board" drop-down menu, and click on the "Unknown Board", select "DOIT ESP32 DevKit 1" (or whatever board you installed).
11. Check in the bottom right hand corner of the window, and ensure it says "DOIT ESP32 DEVKIT V1 on COM[n]" (Where [n] represents a number specified arbitrarily by your operating system).
12. Select "File" > "Open" and navigate to the directory where you cloned the repository for this workshop, and open "workshop_01/esp32_i2cDisplay/esp32_i2cDisplay.ino".
#### Working with the display
The first thing you will notice is that at the top we have used an #include preprocessor directive. This basically tells the compiler to "copy everything in the directory that has been included at the top of this code." It's a little more complicated, but that's the general idea. This allows us to use features of the lcdgfx library.

Now read through the rest of the comments, and get a feel for what the code intends to do. If you have any questions, feel free to ask!

Next, plug-in the LCD display to the breadboard , making sure that each pin lines up with a different numbered row, and leave enough space on the column that you can plug in at-least one dupont jumper wire in the same rows as your display's pins. 

Now, unplug your ESP32 from USB (it's best to make connections when the device is unpowered). 

Using the dupont jumpers, connect from the LCD display:
- GND to one of the GND pins on the breakout board. 
- VCC to a 5V pin on the breakout board.
- SCL to D22 on the breakout board.
- SDA to D21 on the breakout board. 

Now, go back to the Arduino IDE, and press the --> arrow key (Upload) in the upper left hand of the window, and wait for it to upload. If it does not upload, you may need to press the "Boot" button on the ESP32 to kick it into "bootloader" mode for it to program successfully. If this also fails, please ask for help.

You should now see a test message displayed, scrolling across the small LCD screen. 

Now, you can go down to line 24, and edit the message inside the parentheses, and re-upload the program. Try a few different things, and see what you can do. 
#### Working with the SD Card
After you've had a chance to play around a little, open the file "workshop_01/esp32_cardRead/esp32_cardRead.ino", and close the previous Arduino IDE window. You may need to "Select Board" again, but the rest of the set-up will remain installed. 


Note the values for the pins that are specified in the #define preprocessor directive (the define preprocessor directive basically copies whatever is placed after the first keyword in place of wherever that keyword is used later on. It's common practice to use ALL_CAPS, and these are referred to as "macros", and yes, they can do a whole lot more than store number values--but more on that in another workshop. For now, just know that these represent our SPI data pins.

Similar to the LCD display, place the SD Card Adapter into the breadboard, and connect the GND and Power pins to GND and 5V, just like the display.
Next, use the macro definitions to figure out where the other pins should connect (hint: MOSI stands for Master-Out Slave-In, and MISO stands for Master-In Slave-Out, so MOSI on the adapter should not be connected to the MOSI pin on the microcontroller, feel free to ask if you're still lost).

Now, as before, read through the rest of the code comments, and try to understand the code. If you have any questions, feel free to ask, there's a lot here.

Now, reconnect the USB-C cable, and make sure that the bottom right corner displays "DOIT ESP32 DEVKIT V1 on COM[n]", then upload the code as before.

Now, open "Tools" > "Serial Monitor".

Select "115200 Baud".

You will probably see an error "Check connections and pin assignments, then reset the microcontroller."

Now, insert the MicroSD card into the slot, and press the "EN" button the ESP32 board to reset the device.

Now, you should see the desired message displayed to the Serial Monitor.

Feel free to play around with the code more, and ask questions if needed--or if you are unable to get anything working.

### FINALLY

Open the file "workshop_01/esp32_cardDisplay/esp32_cardDisplay.ino", and read through the code. Then, upload the code, and watch as our text is displayed to the LCD. 

Feel free to play around with this code, it's encouraged!
