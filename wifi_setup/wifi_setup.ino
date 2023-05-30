#include<ESP8266WiFi.h>
const char WiFiPassword[]="passcode";
const char AP_NameChar[]="yourname";

WiFiServer server(80);

String a = "HTTP/1.1 200 OK\r\nContent-Type:/html\r\n\r\n";

String b = "<!DOCTYPEhtml><html><head><title>LED Control</title></head><body><divid='main'><h2>LED Control</h2>";

String c = "<form id='F1'action='LED_ON'><input class='button'type=submit value='LED_ON'></form><br>";

String d = "<form id='F2'action='LED_OFF'><input class='button'type=submit value='LED_OFF'></form><br>";

String e = "</div></body></html>";

String request="";
int LED_Pin=D0;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_Pin,OUTPUT);
  boolean conn=WiFi.softAP(AP_NameChar,WiFiPassword);
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
WiFiClient client=server.available();

if(!client)
{
  return;
}

request=client.readStringUntil('\r');

if(request.indexOf("LED_OFF")>0){
  digitalWrite(LED_Pin,HIGH);}
  else if(request.indexOf("LED_ON")>0){
    digitalWrite(LED_Pin,LOW);}

    client.flush();

    client.print(a);
    client.print(b);
    client.print(c);
    client.print(d);
    client.print(e);

    
}
