#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); 

int wrong = 0;
int Rpin = 9;
int Gpin = 10;
int Bpin = 11;
int buttonRpin = 7;
int buttonBpin = 6;
int right = 0;
long long int t_prev = 0;
int t_interval = 1000;
void setup() {
  lcd.init();                      
  lcd.init();

  pinMode(Rpin, OUTPUT);
  pinMode(Gpin, OUTPUT);
  pinMode(Bpin, OUTPUT);
  pinMode(buttonRpin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
  randomSeed(analogRead(A0));
  Serial.begin(115200);
}

void loop() {
  int rand = random(100) % 2;
  int clicked = 0;
  if (rand == 0) {
    analogWrite(Rpin, 255);   
    analogWrite(Gpin, 0);
    analogWrite(Bpin, 0);
    lcd.backlight();
    lcd.setCursor(3,0);
    lcd.print("RED ");
  } else {
    analogWrite(Rpin, 0);   
    analogWrite(Gpin, 0);
    analogWrite(Bpin, 255); 
    lcd.backlight();
    lcd.setCursor(3,0);
    lcd.print("BLUE");
  }  
  unsigned long t_now = millis();
  while (t_now - t_prev <= t_interval) {
    if (digitalRead(buttonRpin) == HIGH) {
      clicked = 1;
      if (rand == 0) {
        right += 1;
      } else {
        wrong += 1;
      }
    }
    if (digitalRead(buttonBpin) == HIGH) {
      clicked = 1;
      if (rand == 1) {
        right += 1;
      } else {
        wrong += 1;
      }
    }
  }
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);

  delay(1000);
  lcd.backlight();
  lcd.setCursor(3,1);
  lcd.print(right);
  lcd.setCursor(6,1);
  lcd.print(wrong);
  t_prev = t_now;
}
