#include <PubSubClient.h>
#include <ESP8266WiFi.h>
char * SSID="Realme 3 Pro";
char * password="password";
char * server="iot.eclipse.org";
WiFiClient(node1);
PubSubClient client(node1);

char msg[50];
boolean flag=false;

void setup() {
  // put your setup code here, to run once:
pinMode(16,OUTPUT);
pinMode(15,INPUT);
Serial.begin(9600);
WiFi.begin(SSID,password);
if(WiFi.status()!=WL_CONNECTED)
{
  Serial.print(".");
  delay(200);
}
Serial.print("\n");
Serial.print("wifi connected");
Serial.print("IP:");
Serial.print(WiFi.localIP());
client.setServer(server,1883);
client.subscribe("iotstars");
client.setCallback(callback);

}

void callback(char * topic,byte * payload,unsigned int length)
{
  Serial.print("message arrived[");
  Serial.print(topic);
  Serial.print("]");
  for(int i=0;i<length;i++)
  {
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
 float d;
 if(flag==true)
  {
   digitalWrite(16,0);
  delayMicroseconds(2);
  digitalWrite(16,1);
  delayMicroseconds(10);
  digitalWrite(16,0);
  int duration=pulseIn(15,1);
  d=(0.034*duration)/2;
  Serial.println("the distance is:");
  Serial.println(d);
  flag=false;
  delay(500);
  }
  String data="distance="+String(d);
data.toCharArray(msg,50);
client.publish("iotstars1",msg);

}
