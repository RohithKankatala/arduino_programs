void setup() {
  // put your setup code here, to run once:
  pinMode(9,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);

}

boolean flag=false;
void loop() {
  // put your main code here, to run repeatedly:
  char mode=Serial.read();
  if(mode=='s')
  {
    Serial.println("secured mode");
    flag=true;
  }
  
  else if(mode=='u')
  {
    Serial.println("unsecured mode");
    flag=false;
 
  }

   if(digitalRead(9)==1 && flag==true)
    {
    digitalWrite(13,1);
    Serial.println("object detected");
   
    }
//    else
//    {
//      Serial.println("not found");
//    }
  delay(1000);
}
