#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <adt7410.h>

Adafruit_SSD1306 display(128, 64, &Wire, 4);

adt7410 adt = adt7410(0x48);

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
  adt.begin();
}

void loop() {
  float t = adt.read();
  Serial.println(t);
  display.clearDisplay();
  display.setTextSize(3);             
  display.setTextColor(WHITE);        
  display.setCursor(0,0);            
  display.println(String(t) + "*C");
  display.display();
  delay(5000);
}
