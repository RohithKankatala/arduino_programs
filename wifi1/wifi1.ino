
#include <ESP8266WiFi.h>
char * SSID="realme 3 Pro";
char * password="password";
void setup() {
 pinMode(16,OUTPUT);                //or pinMode(D0,output); 
  // put your setup code here, to run once:
Serial.begin(9600);
WiFi.begin(SSID,password);
while(WiFi.status()!=WL_CONNECTED)
{
  Serial.printf(".");
  delay(200);
}
Serial.print("\n");
Serial.println("WiFi Connected");

Serial.print("the  IP: ");
Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
 
digitalWrite(16,0);
delay(500);
digitalWrite(16,1);
delay(500);

}
