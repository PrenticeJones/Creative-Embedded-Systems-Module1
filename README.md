# Creative-Embedded-Systems-Module1
Generative Art Display for Valentine's Day


This project is a generative art piece designed for the ESP32 TTGO T-display. It features a dynamic display of the song lyric "In a club with you in 1973" as a tribute to James Blunt's song. Accompanied by a changing color display and a heart shape, this installation was created for Valentine's Day to evoke nostalgia and celebrate love.

Installation
1. Ensure you have the Arduino IDE installed on your computer.
2. Install the TFT_eSPI library using the Library Manager in the Arduino IDE.
3. Clone this repository to your local machine or download the code.
4. Open the `.ino` file in the Arduino IDE.

Usage
1. Connect the ESP32 TTGO T-display to your computer via USB.
2. Select the correct board and port in the Arduino IDE.
3. Upload the code to your ESP32 device.
4. Once uploaded, the device will display the art for the first 10 minutes of every half-hour.
5. After the display time, the device will automatically go into deep sleep mode to conserve battery, waking up after 20 minutes to repeat the cycle.

Reproducing the Design
To recreate this project, you will need the following components:
- ESP32 TTGO T-display
- A 130mAh battery capable of providing at least 67mA current

Follow these steps to set up your environment:
1. Assemble the hardware: Connect the ESP32 TTGO T-display to the battery.
2. Configure the TFT_eSPI library according to your display driver.
3. Modify the pin definitions in the code if they differ from your hardware configuration.
4. Adjust the `DISPLAY_TIME_MS` and `SLEEP_TIME_US` constants in the code to change the display and sleep durations as needed.

Notes
- The generateRandomColor() function produces a random color for the text display.
- The drawHeart() function creates a heart shape on the screen using geometric shapes.
- The goToDeepSleep() function puts the ESP32 into deep sleep mode to save battery life.
