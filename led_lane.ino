int pin[6] = {13,12,11,10,9,8};
int test[6] = {0,0,1,1,0,1};


void led(int state[6]){
  for (int j = 0; j <= 5; j++){
    digitalWrite(pin[j], state[j]);
  }
}

void setup() {
  for (int i = 0; i <= 5; i++){
    pinMode(pin[i],OUTPUT);
  }
  led(test);
}


void loop() {

}
