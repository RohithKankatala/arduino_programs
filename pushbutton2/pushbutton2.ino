void setup() {
  // put your setup code here, to run once:

  pinMode(9,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);

}

boolean flag=true;

void loop() {
  // put your main code here, to run repeatedly:

  if((digitalRead(9)==1)&&flag==true)
  {
    digitalWrite(13,1);
    Serial.println("on");
    flag=false;
    delay(500);
  }

  if((digitalRead(9)==1)&& flag==false)
  {
    digitalWrite(13,0);
    Serial.println("off");
    flag=true;
    delay(500);
  }

}
