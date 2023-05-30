void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT);
  pinMode(10,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(11,0);
  delayMicroseconds(2);
  digitalWrite(11,1);
  delayMicroseconds(10);
  digitalWrite(11,0);
  int duration=pulseIn(10,1);
  float distance=(0.034*duration)/2;
  Serial.println("the distance is:");
  Serial.println(distance);
  delay(500);
  
}
