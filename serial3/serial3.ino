void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int mydata=Serial.parseInt();
//char mydata=Serial.readString();
if(mydata==1)
//if(mydata=='on')
{
  Serial.println("led on");
}
else if(mydata==2)//default value in a for int is zero
//else if(mydata=='off')//default value for string is null
{
  Serial.println("led off");
}
delay(1000);
}
