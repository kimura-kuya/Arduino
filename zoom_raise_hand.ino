#include <BleKeyboard.h>
#include "M5Atom.h"

BleKeyboard bleKeyboard("M5Atom raise hand");

int state = 0;

void setup() {
  Serial.begin(115200);
  bleKeyboard.begin();
  M5.begin(true, false, true);
  M5.dis.drawpix(0, 0x000000);
}

void loop() {
  if (M5.Btn.wasPressed()){
    Serial.println("push");
    state = !state;
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press('y');
    delay(100);
    bleKeyboard.releaseAll();
    if (state){
      M5.dis.drawpix(0, 0x0000ff);
    }else{
      M5.dis.drawpix(0, 0x000000);
    }
  }
  delay(50);
  M5.update();
}
