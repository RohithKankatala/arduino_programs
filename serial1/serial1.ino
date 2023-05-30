void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
char mydata=Serial.read();
if(mydata=='i')
{
  digitalWrite(13,1);
}
else if(mydata=='o')
{
  digitalWrite(13,0);
}
delay(1000);
}
