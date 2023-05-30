#include <DHT.h>
#include <DHT_U.h>
#define DHTpin D5
#define DHTType DHT11
DHT dht(DHTpin,DHTType);

char msg[50];

#include <ESP8266WiFi.h>
#include<PubSubClient.h>
char * SSID="friend";
char * password="11111111";
char * server = "iot.eclipse.org";
WiFiClient node1;
PubSubClient client(node1);


void setup() {
// pinMode(16,OUTPUT);                //or pinMode(D0,output); 
  dht.begin();
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
client.publish("iotstars",msg);

}
void reconnect()
{
  while(!client.connected())
  {
    Serial.print("connecting");
    if(client.connect("node1"))
    {
      client.publish("iotstars",msg);
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

 
float T,H;
T=dht.readTemperature();
H=dht.readHumidity();
Serial.print("the temperature:");
Serial.println(T);
Serial.print("the humidity:");
Serial.println(H);
delay(500);
String data="temp="+String(T)+",hum="+String(H);
data.toCharArray(msg,50);
client.publish("iotstars",msg);
}
