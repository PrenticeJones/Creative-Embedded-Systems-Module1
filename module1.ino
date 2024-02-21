#include <TFT_eSPI.h> //Graphics and font lib
#include <SPI.h>
#include "esp_sleep.h" //ESP32 sleep functionality

TFT_eSPI tft = TFT_eSPI();  //Invoke library, pins defined in User_Setup.h

#define DISPLAY_TIME_MS 10 * 60 * 1000 // 10 minutes in milliseconds
#define SLEEP_TIME_US (20 * 60 * 1000000ULL) // 20 minutes in microseconds

//generate a random color
unsigned int generateRandomColor() {
  return rand() % 0xFFFF;
}

void setup() {
  tft.init();
  tft.setRotation(1);
  //black background
  tft.fillScreen(TFT_BLACK);

  //deep sleep timer
  esp_sleep_enable_timer_wakeup(SLEEP_TIME_US);
}

void loop() {
  //record start time 
  unsigned long startMillis = millis();

  //ensuring that current time is less than 10 minutes
  while (millis() - startMillis < DISPLAY_TIME_MS) {
    // Display the text with randomly generated colors
    displayTextWithRandomColors();

    //draw heart after updating the text
    int heartSize = 10; 
    int x = 120;
    int y = 20; 
    drawHeart(x, y, heartSize); 

    //change text color every 2 secs
    delay(2000); //
  }

  //post display for the 10 mins, go to deep sleep 
  //for energy consumption
  goToDeepSleep();
}

void displayTextWithRandomColors() {
  //black background
  tft.fillScreen(TFT_BLACK); 

  //"In a club" with random color
  tft.setCursor(0, 0, 2);
  tft.setTextColor(generateRandomColor(), TFT_BLACK);
  tft.setTextFont(4);
  tft.println("In a club");

  //"with you" with another random color
  tft.setCursor(0, 30, 2); // Adjust Y position as needed
  tft.setTextColor(generateRandomColor(), TFT_BLACK);
  tft.setTextFont(4);
  tft.println("with you");

  //"in 1973" with another random color
  tft.setCursor(0, 60, 2); // Adjust Y position as needed
  tft.setTextColor(generateRandomColor(), TFT_BLACK);
  tft.setTextFont(4);
  tft.println("in 1973");
}

void drawHeart(int x, int y, int size) {
  //top left circle
  tft.fillCircle(x, y, size, TFT_RED); 
  //top right circle
  tft.fillCircle(x + 2*size, y, size, TFT_RED); 
  //Bottom triangle to fill heart
  tft.fillTriangle(x - size, y, x + 3*size, y, x + size, y + 3*size, TFT_RED);
}

void goToDeepSleep() {
  //deep sleep mode
  esp_deep_sleep_start();
}
