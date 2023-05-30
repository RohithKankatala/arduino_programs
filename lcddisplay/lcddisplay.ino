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
lcd.begin(16,2);
lcd.print("internet of things");

}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0,0);
lcd.print("internet");
lcd.setCursor(0,1);
lcd.print("of things");
lcd.clear();
}
