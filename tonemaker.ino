int sound[] = {262, 294, 330 , 0, 262, 294, 330 , 0, 392, 330, 294, 262, 294, 330, 294, 0, 262, 294, 330 , 0, 262, 294, 330 , 0, 392, 330, 294, 262, 294, 330, 262};
int tonetime[] = {500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500};
const int buzzer = 12;
const int controll = 11;

int soundsize = 30;

void setup() {
  pinMode(controll,OUTPUT);
  
}

void loop() {
  digitalWrite(controll,HIGH);
  for (int i = 0; i <= soundsize; i++){
    if  (sound[i] == 0){
      digitalWrite(controll,LOW);
    }else{
      digitalWrite(controll,HIGH);
    }
    tone(buzzer,sound[i]);
    delay(tonetime[i]);
  }
  digitalWrite(controll,LOW);
  noTone(buzzer);
  delay(1000);
}
