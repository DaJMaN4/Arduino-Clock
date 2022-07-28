
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <dht.h>
#include <virtuabotixRTC.h>
#define dht_apin A3 // Analog Pin sensor is connected to
dht DHT; //it needs to be here
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display
virtuabotixRTC myRTC(A5, A4, 13); //pins conntected to rtc
int pinA = 2;  //   \
int pinB = 3;  //   |
int pinC = 4;  //   |
int pinD = 5;  //   | Variables to LCD display
int pinE = 6;  //   |
int pinF = 7;  //   |
int pinG = 8;  //   /
int D1 = 9;  //   \
int D2 = 10; //   | variables to lcd to know which LCD part must be turn on
int D3 = 11; //   |
int D4 = 12; //   /
int timer1 = 0; 
int timer2 = 0; 
int timer3 = 0; 
int timer4 = 0;
int kk = 0; // Actually a bool that says in witch stadium loop is in a specific moment.
int dis = 0; // same as privious
int dele = 0; // same as privious
bool first_time = 0; // same as privious
int n;
void setup() {     
  //myRTC.setDS1302Time(0, 53, 21, 1, 25, 10, 2021); //seting current time 
  Serial.begin(9600);
  lcd.cursor(); lcd.begin(); lcd.backlight(); lcd.print("Select Mode"); // initialize the LCD
  pinMode(pinA, OUTPUT); 
  pinMode(pinB, OUTPUT); 
  pinMode(pinC, OUTPUT); 
  pinMode(pinD, OUTPUT); 
  pinMode(pinE, OUTPUT); 
  pinMode(pinF, OUTPUT); 
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT); 
  pinMode(D2, OUTPUT); 
  pinMode(D3, OUTPUT); 
  pinMode(D4, OUTPUT);  
}
void zero() {digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, HIGH); digitalWrite(pinG, LOW);}
void one() {digitalWrite(pinA, LOW); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, LOW); digitalWrite(pinE, LOW); digitalWrite(pinF, LOW); digitalWrite(pinG, LOW);}
void two() {digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, LOW); digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, LOW); digitalWrite(pinG, HIGH);}
void three() {digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, HIGH); digitalWrite(pinE, LOW); digitalWrite(pinF, LOW); digitalWrite(pinG, HIGH);}
void four() {digitalWrite(pinA, LOW); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, LOW); digitalWrite(pinE, LOW); digitalWrite(pinF, HIGH); digitalWrite(pinG, HIGH);}
void five() {digitalWrite(pinA, HIGH); digitalWrite(pinB, LOW); digitalWrite(pinC, HIGH); digitalWrite(pinD, HIGH); digitalWrite(pinE, LOW); digitalWrite(pinF, HIGH); digitalWrite(pinG, HIGH);}
void six() {digitalWrite(pinA, HIGH); digitalWrite(pinB, LOW); digitalWrite(pinC, HIGH); digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, HIGH); digitalWrite(pinG, HIGH);}
void seven() {digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, LOW); digitalWrite(pinE, LOW); digitalWrite(pinF, LOW); digitalWrite(pinG, LOW);  }
void eight() {digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, HIGH); digitalWrite(pinE, HIGH); digitalWrite(pinF, HIGH); digitalWrite(pinG, HIGH);}
void nine() {digitalWrite(pinA, HIGH); digitalWrite(pinB, HIGH); digitalWrite(pinC, HIGH); digitalWrite(pinD, HIGH); digitalWrite(pinE, LOW); digitalWrite(pinF, HIGH); digitalWrite(pinG, HIGH);} 
void none() {digitalWrite(pinA, LOW); digitalWrite(pinB, LOW); digitalWrite(pinC, LOW); digitalWrite(pinD, LOW); digitalWrite(pinE, LOW); digitalWrite(pinF, LOW); digitalWrite(pinG, LOW);} 
void numbers() {
  none();
  if (timer1 == 0) {digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, LOW); zero();}
  if (timer1 == 1) {digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, LOW); one();}
  if (timer1 == 2) {digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, LOW); two();}
  if (timer1 == 3) {digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, LOW); three();}
  if (timer1 == 4) {digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, LOW); four();}
  if (timer1 == 5) {digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, LOW); five();}
  if (timer1 == 6) {digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, LOW); six();}
  if (timer1 == 7) {digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, LOW); seven();}
  if (timer1 == 8) {digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, LOW); eight();}
  if (timer1 == 9) {digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, LOW); nine();}
  delay(2.5);
  none();
  if (timer2 == 0) {digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, LOW);digitalWrite(D4, HIGH); zero();}
  if (timer2 == 1) {digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, LOW);digitalWrite(D4, HIGH); one();}
  if (timer2 == 2) {digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, LOW);digitalWrite(D4, HIGH); two();}
  if (timer2 == 3) {digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, LOW);digitalWrite(D4, HIGH); three();}
  if (timer2 == 4) {digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, LOW);digitalWrite(D4, HIGH); four();}
  if (timer2 == 5) {digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, LOW);digitalWrite(D4, HIGH); five();}
  if (timer2 == 6) {digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, LOW);digitalWrite(D4, HIGH); six();}
  if (timer2 == 7) {digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, LOW);digitalWrite(D4, HIGH); seven();}
  if (timer2 == 8) {digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, LOW);digitalWrite(D4, HIGH); eight();}
  if (timer2 == 9) {digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, LOW);digitalWrite(D4, HIGH); nine();}
  delay(2.5);
  none();
  if (timer3 == 0) {digitalWrite(D1, HIGH);digitalWrite(D2, LOW);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH); zero();}
  if (timer3 == 1) {digitalWrite(D1, HIGH);digitalWrite(D2, LOW);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH); one();}
  if (timer3 == 2) {digitalWrite(D1, HIGH);digitalWrite(D2, LOW);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH); two();}
  if (timer3 == 3) {digitalWrite(D1, HIGH);digitalWrite(D2, LOW);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH); three();}
  if (timer3 == 4) {digitalWrite(D1, HIGH);digitalWrite(D2, LOW);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH); four();}
  if (timer3 == 5) {digitalWrite(D1, HIGH);digitalWrite(D2, LOW);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH); five();}
  if (timer3 == 6) {digitalWrite(D1, HIGH);digitalWrite(D2, LOW);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH); six();}
  if (timer3 == 7) {digitalWrite(D1, HIGH);digitalWrite(D2, LOW);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH); seven();}
  if (timer3 == 8) {digitalWrite(D1, HIGH);digitalWrite(D2, LOW);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH); eight();}
  if (timer3 == 9) {digitalWrite(D1, HIGH);digitalWrite(D2, LOW);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH); nine();}
  delay(2.5);
  none();
  if (timer4 == 0) {digitalWrite(D1, LOW);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH); zero();}
  if (timer4 == 1) {digitalWrite(D1, LOW);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH); one();}
  if (timer4 == 2) {digitalWrite(D1, LOW);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH); two();}
  if (timer4 == 3) {digitalWrite(D1, LOW);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH); three();}
  if (timer4 == 4) {digitalWrite(D1, LOW);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH); four();}
  if (timer4 == 5) {digitalWrite(D1, LOW);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH); five();}
  if (timer4 == 6) {digitalWrite(D1, LOW);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH); six();}
  if (timer4 == 7) {digitalWrite(D1, LOW);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH); seven();}
  if (timer4 == 8) {digitalWrite(D1, LOW);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH); eight();}
  if (timer4 == 9) {digitalWrite(D1, LOW);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH); nine();}
  delay(2.5);
}

void tim(){ //timer
  timer1 = 0;
  timer2 = 0;
  timer3 = 0;
  timer4 = 0;
  while (true) {
    delay(2.5);
    dele = dele + 10;
    if (dele == 1000){ dele = 0; timer1 = timer1 + 1; 
      if (timer1 == 10) { timer1 = 0; timer2 = timer2 + 1; }
      if (timer2 == 6)  { timer2 = 0; timer3 = timer3 + 1; }
      if (timer3 == 10) { timer3 = 0; timer4 = timer4 + 1; }}
    if (digitalRead(A1) == HIGH) {
      if (first_time == 0) {first_time = 1;}
      else{
        while(digitalRead(A1) == HIGH){
          numbers();
        }
        digitalWrite(D1, HIGH);
        digitalWrite(D2, HIGH);
        digitalWrite(D3, HIGH);
        digitalWrite(D4, HIGH);
        break;
      }
    }
    numbers();
  }
}
void tem() {    // temperature       Fastest refresh should be once every two seconds (delay ;) )
  delay(1000);
  DHT.read11(dht_apin);
  lcd.clear();
  lcd.print("Humidity ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  lcd.setCursor(2,3);
  lcd.print("Temp. ");
  lcd.print(DHT.temperature); 
  lcd.println("C  ");
  delay(1000);
}
void clo(){
  Wire.end();
  while (true) {
    numbers();
    dele = dele + 10;
    if (dele == 1000){ 
      dele = 0;
      myRTC.updateTime();
      n = myRTC.minutes;
      timer1 = (n / 1U) % 10;
      timer2 = (n / 10U) % 10;
      n = myRTC.hours;
      timer3 = (n / 1U) % 10;
      timer4 = (n / 10U) % 10;
      }
    if (digitalRead(A1) == HIGH) {
        digitalWrite(D1, HIGH);digitalWrite(D2, HIGH);digitalWrite(D3, HIGH);digitalWrite(D4, HIGH);       
        while(digitalRead(A1) == HIGH){}
        break; 
    }
  }
}
void loop() {
  if (digitalRead(A0) == HIGH) {
    while(digitalRead(A0) == HIGH){}
    if (kk != 1) {kk = kk + 1; dis = 1;}
  }
  if (digitalRead(A2) == HIGH) {
    while(digitalRead(A2) == HIGH){}
    if (kk != -1) {kk = kk - 1; dis = 1;}
  }
  if (digitalRead(A1) == HIGH) {
    if (kk == -1){
      while(digitalRead(A1) == HIGH){}
      lcd.noBacklight();
      tim();
      lcd.backlight();
      }
    if (kk == 0){
      while(digitalRead(A1) == HIGH){}
      lcd.noBacklight();
      clo();
      lcd.backlight();
      }
    if (kk == 1){
      while(digitalRead(A1) == HIGH){}
      tem();
    }
  }
  if (kk == -1 and dis == 1) {lcd.clear(); lcd.print("Timer"); dis = 0;
  }
  if (kk == 1 and dis == 1) {lcd.clear(); lcd.print("Thermometer"); dis = 0;
  }
  if (kk == 0 and dis == 1) {lcd.clear(); lcd.print("Clock"); dis = 0;
  }
}
