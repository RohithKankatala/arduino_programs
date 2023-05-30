#include <DHT.h>
#include <DHT_U.h>
#define DHTpin 2
#define DHTType DHT11
DHT dht(DHTpin,DHTType);

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
float temp,hum;
temp=dht.readTemperature();
hum=dht.readHumidity();
Serial.print("the temperature:");
Serial.println(temp);
Serial.print("the humidity:");
Serial.println(hum);
delay(500);

}
