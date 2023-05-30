#include <DHT.h>
#include <DHT_U.h>

#include <ThingSpeak.h>

#include <BearSSLHelpers.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureAxTLS.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureAxTLS.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>
const char *ssid = "KVV";
const char *pass = "12345678";
unsigned long channelid= 785953;
const char *apikey="RTE1FFUDCNQZPU62";

WiFiClient
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("conecting wifi with the ssid");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("..");
    delay(500);
  }
  Serial.print('\n');
  Serial.println("WiFi connected");
  Serial.print("The IP:");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
