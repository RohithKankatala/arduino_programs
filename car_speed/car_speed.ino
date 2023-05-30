void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(8,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(9,0);
  delayMicroseconds(2);
  digitalWrite(9,1);
  delayMicroseconds(10);
  digitalWrite(9,0);
  int duration=pulseIn(8,1);
  float distance=(0.034*duration)/2;
  if(distance<=80)
  {
    Serial.println("decrease the car speed");
  }
  else
  {
    Serial.println("maintain the same speed");
  }
  delay(500);
  
}
