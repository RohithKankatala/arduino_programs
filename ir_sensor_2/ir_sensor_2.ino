void setup() {
  // put your setup code here, to run once:
  pinMode(9,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);

}
int c=0;

void loop() {
  // put your main code here, to run repeatedly:
  
  
  {
  if(digitalRead(9)==0)
  {
    if(digitalRead(9)==1)
    {
    digitalWrite(13,1);
    c++;
    }
    else
    {
      Serial.println("object not moving");
    }
   
  }
  else
  {
    digitalWrite(13,0);
    
  }
  }
  Serial.println("number of objects detected:");
  Serial.println(c);
  delay(500);
}
