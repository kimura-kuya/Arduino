#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

float temperature;
float humidity;
int fukai;

DHT dht(12,DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  reading();
  fukai = 0.81 * temperature + 0.01 * humidity * (0.99 * temperature - 14.3) + 46.3;
  Serial.println(fukai);
  delay(3000);
}

void reading(){
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
}

