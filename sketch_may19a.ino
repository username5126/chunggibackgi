#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27,20,4); 

int Rpin = 7;
int Bpin = 8;
int buttonRpin = 2;
int buttonBpin = 3;
int right = 0;
int buttonpin[3] = {4,5,6};

Servo servo1;
Servo servo2;

void setup() {
  lcd.init();                      
  lcd.init();
  srand(time(NULL));

  pinMode(Rpin, OUTPUT);
  pinMode(Bpin, OUTPUT);
  pinMode(buttonRpin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
  for (int i = 0; i<=2; i++) {
    pinMode(buttonpin[i], INPUT_PULLUP);
  }
  Serial.begin(115200);

  servo1.attach(9);
  servo2.attach(10);
}

void loop() {
  int rand = random(100) % 2;
  int updown = random(100) % 2;
  int clicked = 0;
  if (rand == 0) {
    analogWrite(Rpin, 255);   
    analogWrite(Bpin, 0);
    lcd.backlight();
    lcd.setCursor(3,0);
    lcd.print("RED ");
  } else {
    analogWrite(Rpin, 0);   
    analogWrite(Bpin, 255); 
    lcd.backlight();
    lcd.setCursor(3,0);
    lcd.print("BLUE");
  }  
  while (clicked == 0) {
    if (digitalRead(buttonRpin) == HIGH) {
      clicked = 1;
      if (rand == 0) {
        right += 1;
      } else {
        right += 0;
      }
    }
    if (digitalRead(buttonBpin) == HIGH) {
      clicked = 1;
      if (rand == 1) {
        right += 1;
      } else {
        right += 0;
      }
    }
  }

  digitalWrite(9, LOW);
  digitalWrite(11, LOW);

  delay(1000);
  lcd.backlight();
  lcd.setCursor(3,1);
  lcd.print(right);
}
