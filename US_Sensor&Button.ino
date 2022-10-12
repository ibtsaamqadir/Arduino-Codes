void setup() {
Serial.begin(9600);
pinMode(10,INPUT);
pinMode(11,OUTPUT);
pinMode(12,INPUT);

}

void loop() {
long duration, distance;
digitalWrite(11,LOW);
delayMicroseconds(10);
digitalWrite(11,HIGH); //sends out a signal, trigger the sound wave
delayMicroseconds(10);
digitalWrite(11,LOW); //stop sending the soundwave so that the echo is received without any interferance 
duration=pulseIn(10,HIGH);
distance=duration / 29 / 2;
Serial.print(String(distance));
Serial.print(",");
if(digitalRead(12) == HIGH){
  Serial.print(HIGH);
  }
if(digitalRead(12) == LOW){
  Serial.print(LOW);
  }
Serial.println();
delay(1000);
}
