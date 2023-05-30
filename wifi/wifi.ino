void setup() {
  // put your setup code here, to run once:
pinMode(16,OUTPUT);
pinMode(5,OUTPUT);
pinMode(4,OUTPUT);
pinMode(2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(16,1);
delay(1000);
digitalWrite(16,0);
delay(1000);
for (int i=0;i<2;i++)
{
  for (int j=0;j<2;j++)
  {
    for (int k=0;k<2;k++)
    {
digitalWrite(5,i);
digitalWrite(4,j);
digitalWrite(2,k);
delay(1000);
    }
  }
}
delay(1000);
}
