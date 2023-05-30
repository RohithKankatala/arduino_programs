#include <DHT.h>
#include <DHT_U.h>
#define DHTpin 2
#define DHTType DHT11
DHT dht(DHTpin,DHTType);
#include <ThingSpeak.h>
#include<ESP8266WiFi.h>
char *SSID ="friend";
char *password="11111111";
const char *apikey="9S2P3UZ57G803337";
unsigned long channel id="846842";
WiFiClient node;
void setup() {
  dht.begin():
  ThingSpeak.begin(node);
  // put your setup code here, to run once:
Serial.begin(9600);
WiFi.begin(SSID,password);
while(WiFi.status()!=WL_CONNECTED){
  Serial.print(".");
  delay(20);
}
Serial.print("\n")
Serial.print("connected");
Serial.print("IP address:");
Serial.print(WiFi.localIP());

}

void loop() {
float T,H;
T=dht.readTemperature();
H=dht.readHumidity();
ThingSpeak.setField(1,T);
ThingSpeak.setField(2,H);
ThingSpeak.writeFields(channel id,apikey);
delay(15);
Serial.print("the temperature:");
Serial.println(T);
Serial.print("the Humidity");
Serial.println(H);
delay(500);
}

}
