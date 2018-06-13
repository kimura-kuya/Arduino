#include "DHT.h"
DHT dht11(12,DHT11);
void setup() {
  dht11.begin();
  Serial.begin(9600);
}

void loop() {
  float t = dht11.readTemperature();
  Serial.println(t);
}
