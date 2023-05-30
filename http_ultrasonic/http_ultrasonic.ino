#include <ThingSpeak.h>
#include <ESP8266WiFi.h>
char * SSID="realme 3 Pro";
char * password="password";
//char * server="api.thingspeak.com";
WiFiClient node;
char msg[50];
unsigned long channel id="846841";
const char * APIkey=SHEU010JFMDSI74X;
void setup() {
  // put your setup code here, to run once:
pinMode(D0,OUTPUT); 
  pinMode(D1,INPUT);
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

ThingSpeak.begin(node);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(D0,0);
  delayMicroseconds(2);
  digitalWrite(D0,1);
  delayMicroseconds(10);
  digitalWrite(D0,0);
  int duration=pulseIn(D1,1);
  float d=(0.034*duration)/2;
  Serial.println("the distance is:");
  Serial.println(d);
  delay(500);
ThingSpeak.setField(1,d);
ThingSpeak.writeFields(846841,SHEU010JFMDSI74X);
delay(15000);
}
