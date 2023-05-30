void setup() {
  // put your setup code here, to run once:
  pinMode(9,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);

}


void loop() {
  // put your main code here, to run repeatedly:
  
  
  {
  if(digitalRead(9)==1)
  {
    digitalWrite(13,1);
    Serial.println("object detected");
   
  }
  else
  {
    digitalWrite(13,0);
    Serial.println("not  detected");
  }
  }
  delay(1000);
}
