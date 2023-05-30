#include <ESP8266WiFi.h>
#include<PubSubClient.h>
char * SSID="friend";
char * password="11111111";
char * server = "iot.eclipse.org";
WiFiClient node1;
boolean flag=true;
PubSubClient client(node1);

char msg[50];
void setup() {
 pinMode(D0,OUTPUT);   //or pinMode(D0,output); 
  pinMode(D1,INPUT);
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
client.setServer(server,1883);
client.subscribe("iotstars");
client.setCallback(callback);
}
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  if((char)payload[0]=='1')
  {
    flag=true;
  }
  if((char)payload[0]=='0')
  {
    flag=false;
  }
  }
void reconnect()
{
  while(!client.connected())
  {
    Serial.print("connecting");
    if(client.connect("node1"))
    {
      client.subscribe("iotstars");
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
 if(!client.connected())
 {
  reconnect();
 }
 client.loop();
 if(flag==true)
  {
   digitalWrite(D0,0);
  delayMicroseconds(2);
  digitalWrite(D0,1);
  delayMicroseconds(10);
  digitalWrite(D0,0);
  int duration=pulseIn(D1,1);
  float d=(0.034*duration)/2;
  Serial.println("the distance is:");
  Serial.println(d);
  flag=false;
  delay(500);
  }
  String data="distance="+String(d);
data.toCharArray(msg,50);
client.publish("iotstars",msg);

}
