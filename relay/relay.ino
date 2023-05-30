void setup() {
  // put your setup code here, to run once:
  pinMode(12,OUTPUT);
  Serial.begin(9600);
}
boolean flag=true;

void loop() {
  // put your main code here, to run repeatedly:
  char i=Serial.read();
  
  if(i=='1'&&flag==true)
  {
   Serial.println("on");
  digitalWrite(12,0);
  delay(1000);
  flag=false;
  }
  else  if(i=='0'&&flag==false)
  {
    Serial.println("off");
  digitalWrite(12,1);
  delay(1000);
  flag=true;
  }
  
  

}
