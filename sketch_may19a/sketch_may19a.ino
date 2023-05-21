#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27,20,4); 
LiquidCrystal_I2C lcd2(0x26, 16, 2);

int r = 0;
int Rpin = 7;
int Bpin = 8;
int buttonRpin = 2;
int buttonBpin = 3;
int right = 0;
int buttonpin[6] = {4,5,6,11,12,13}; //4번 앉기 5번 일어서기 6번 점프 11번 게임시작 12번 리셋 13번 조이스틱 
int x_axispin = A1;
int y_axispin = A0;
int life = 0; 
int level = 1;
int millis_interval = 2000; // 2sec
int premillis = 0;
int start = 0;
unsigned long long nowmillis;

Servo servo1;
Servo servo2;

void setup() {
  lcd.init(); //lcd 초기화                       
  lcd.init();
  lcd2.init();
  lcd2.init();
  srand(time(NULL));

  pinMode(Rpin, OUTPUT);
  pinMode(Bpin, OUTPUT);
  pinMode(buttonRpin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
  for (int i = 0; i<=5; i++) {
    pinMode(buttonpin[i], INPUT_PULLUP);
  }

  servo1.attach(9);
  servo2.attach(10);
  life = 3;
}

void loop() {
  r += 1;
  int rand = random() % 2;
  int updown = random() % 2;
  int clicked = 0;
  if (digitalRead(buttonpin[11]) == LOW) {
    start += 1;
  }
  if (start >= 1) {
    lcd.init();
    if (rand == 0) {
    analogWrite(Rpin, 255);   
    analogWrite(Bpin, 0);
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("RED ");
  } else {
    analogWrite(Rpin, 0);   
    analogWrite(Bpin, 255); 
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("BLUE");
  }  

  
  while (clicked == 0) {
    if (digitalRead(buttonRpin) == HIGH) {
      clicked = 1;
      if (rand == 0) {
        right += 1;
      } else {
        life -= 3;
      }
    }
    if (digitalRead(buttonBpin) == HIGH) {
      clicked = 1;
      if (rand == 1) {
        right += 1;
      } else {
        life -= 1;
      }
    }
  }

    premillis = millis();

    digitalWrite(9, LOW);
    digitalWrite(11, LOW);

    delay(1000);

    lcd.backlight();
    lcd.setCursor(0,1);
    lcd.print("right : ");
    lcd.setCursor(9,1);
    lcd.print(right);
    lcd.setCursor(0,2);
    lcd.print("life : ");
    lcd.setCursor(8,2);
    lcd.print(life);
    if (r % 5 == 0) {
    level += 1;
    }

  if (life == 0) {
    lcd.init();
    lcd.setCursor(0,0);
    lcd.print("Game Over");
    lcd.setCursor(0,1);
    lcd.print("PUSH BUTTON TO RESTART");
  }
  }
  if (clicked == 0) {
    lcd.setCursor(0,0);
    lcd.print("Press to Start");
  }
}
