
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define ANALOG_PIN_0 36

#define GSM_RX 25
#define GSM_TX 0
//#define GSM_RESET 21

int analog_value = 0;

int readLightSensor(){
  analog_value = analogRead(ANALOG_PIN_0);
  return analog_value; //Read analog
}
unsigned int keyval=0;
String adcString;
String incoming = "";

void setup() {
  Wire.begin(16,17);
  Serial.begin(9600);
  Serial1.begin(9600, SERIAL_8N1, GSM_RX, GSM_TX); 
     
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.display();

  display.clearDisplay();
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0,0); 
  display.println("Hello "); 
  display.display();
  delay(300);

  adcAttachPin(36);
  delay(1000);
}

void loop() {
Serial1.println("AT");

   while (Serial1.available()) {
    int inByte = Serial1.read();
    Serial.write(inByte);
  }

  // read from port 0, send to port 1:
  while (Serial.available()) {
    int inByte = Serial.read();
    Serial1.write(inByte);
  }
  delay(1000);
}
