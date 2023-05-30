
#include <LiquidCrystal.h>
#define RS 3
#define E 4
#define D4 5
#define D5 6
#define D6 7
#define D7 8
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);

void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT);
  pinMode(10,INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(11,0);
  delayMicroseconds(2);
  digitalWrite(11,1);
  delayMicroseconds(10);
  digitalWrite(11,0);
  int duration=pulseIn(10,1);
  float distance=(0.034*duration)/2;
  Serial.println("the distance is:");
  Serial.println(distance);
  delay(500);
 lcd.setCursor(0,0);
lcd.print("the distance is");
lcd.setCursor(0,1);
lcd.print(distance);
lcd.clear();

 
}
