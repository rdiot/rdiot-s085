/* BH1750 Digital Light intensity Sensor Module (GY-302) [S085] : http://rdiot.tistory.com/69 [RDIoT Demo] */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <BH1750.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
 
BH1750 lightMeter;
 
void setup(){
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
 
  delay(1000);
 
  lcd.clear();
  lightMeter.begin();  
}
 
void loop() {
  lcd.setCursor(0,0);
  lcd.print("S085:BH1750");
 
  uint16_t lux = lightMeter.readLightLevel();
  lcd.setCursor(0,1);
  lcd.print("Light=" + (String)lux + " lx   ");
 
  delay(1000);
}
