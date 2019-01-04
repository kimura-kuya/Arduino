#include <MozziGuts.h> 
#include <Oscil.h>
#include <tables/sin2048_int8.h>
#include <tables/saw2048_int8.h>

Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin(SIN2048_DATA);
Oscil <SAW2048_NUM_CELLS, AUDIO_RATE> aSaw(SAW2048_DATA);

#define CONTROL_RATE 64

void setup() {
  startMozzi(CONTROL_RATE);
}

void updateControl() {
  int Sin = random(300,2000); //サイン波の周波数
  int Saw = random(300,2000); //ノコギリ波の周波数
  aSin.setFreq(Sin); 
  aSaw.setFreq(Saw); //それぞれ周波数決定
}

int updateAudio() {
  EventDelay(1000);
  return  (aSin.next() + aSaw.next()) / 2;
}

void loop() {
  audioHook();
}

