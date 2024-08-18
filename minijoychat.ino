/*
*
* Joystick Example Code For Mini JoyC Hat For Use With M5 StickC Plus2.
* displays joystick status - waiting, up, down, left, right, button press on display
* Joystick direction base on x and y position,  could be different on yours
* 
* I am not a good programmer - comments and suggestions welcome
* but I may not implement them, cause i probably won't understand what you are saying
* Dead Hiccups
*/

#include <M5StickCPlus2.h>
#include "Wire.h"

#define JOY_ADDR 0x54  // define Joystick I2C address
#define BUTTON_ADDR 0x30 // button status register
#define XVALUE_ADDR 0x20 // x value status register
#define YVALUE_ADDR 0x21 // y value status register

void setup() {
    M5.begin();
    M5.Power.begin();
    M5.Lcd.setTextSize(2);
    M5.Lcd.setRotation(1);
    M5.Lcd.setCursor(7, 20, 2);
    dacWrite(25, 0);  // disable speaker noise
    // sda 0 scl 26
    Wire.begin(0, 26, 100000UL);
    
}




void loop() {
    uint8_t  button_data;
    uint8_t x_data;
    uint8_t  y_data;
    

    Wire.beginTransmission(JOY_ADDR);
    Wire.write(BUTTON_ADDR);
    Wire.endTransmission();
    
    Wire.requestFrom(
        JOY_ADDR,
        1);  // Request 1 bytes from the slave device. 
    while (Wire.available()){
        button_data = Wire.read();

    }
    Wire.beginTransmission(JOY_ADDR);
    Wire.write(XVALUE_ADDR);
    Wire.endTransmission();
    Wire.requestFrom(
        JOY_ADDR,
        1);  // Request 1 bytes from the slave device. 
    while (Wire.available()){
      x_data = Wire.read();

    }
    Wire.beginTransmission(JOY_ADDR);
    Wire.write(YVALUE_ADDR);
    Wire.endTransmission();
    Wire.requestFrom(
        JOY_ADDR,
        1);  // Request 1 bytes from the slave device. 
    while (Wire.available()){
      y_data = Wire.read();

    }
 
    M5.Lcd.setCursor(7, 20, 2);
//    uncomment this if you want you x and y value of your joystick    
//    M5.Lcd.setCursor(7, 55, 2);
//    M5.Lcd.printf("xvalue:  %d ",x_data);
//    M5.Lcd.setCursor(7, 85, 2);
//    M5.Lcd.printf("yvalue:  %d ",y_data);
    M5.Lcd.printf("WAITING         ");
    M5.Lcd.setCursor(7, 20, 2);
    if (x_data > 49 & x_data <110){
      M5.Lcd.printf("right       ");
    }
    if (x_data > 125 & x_data <190){
      M5.Lcd.printf("left        ");
    }
    if (y_data > 45 & y_data <115){
      M5.Lcd.printf("down        ");
    }
    if (y_data > 140 & y_data <200){
      M5.Lcd.printf("up          ");
    }
    if (button_data == 0){
      M5.Lcd.printf("button press");
    }
    delay(200);
}
