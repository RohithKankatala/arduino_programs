void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
char mydata=Serial.read();
if(mydata=='i')
{
  Serial.println("led on");
}
else if(mydata=='o')
{
  Serial.println("led off");
}
delay(1000);
}
