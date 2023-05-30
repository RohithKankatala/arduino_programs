#include <ESP8266WiFi.h>
#include<PubSubClient.h>
char * SSID="friend";
char * password="11111111";
char * server = "iot.eclipse.org";
WiFiClient node1;
PubSubClient client(node1);


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
    digitalWrite(16,0);
  }
  if((char)payload[0]=='0')
  {
    digitalWrite(16,1);
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
 

}
