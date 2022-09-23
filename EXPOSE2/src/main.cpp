#include <Arduino.h>
#include <LiquidCrystal.h>
#define PIR 8

LiquidCrystal lcd = LiquidCrystal ( 2, 3, 4, 5, 6, 7 ) ;
int valPIR = 0;

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(PIR, INPUT);
}

void loop() {

  valPIR = digitalRead(PIR);
  if (valPIR == 1)
  { 
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print ("Presence");
    lcd.setCursor(1,1);
    lcd.print("detecter");
    Serial.println("Mouvement détecté :");
    Serial.println(valPIR);
    Serial.println("--------------------");
    delay(2000);
  } else {
    lcd.clear();
    lcd.setCursor(1,0) ;
    lcd.print ("Aucune");
    lcd.setCursor(1,1);
    lcd.print("presence");
    Serial.println("Aucune présence  :");
    Serial.println(valPIR);
    Serial.println("--------------------");
}

  
}  
 