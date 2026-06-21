#include<Servo.h>
#include <LiquidCrystal.h>
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo myservo;
int pir=2;
int buz=3;
int mot=4;


void setup()
{
  Serial.begin(9600);
  myservo.attach(5);
  pinMode(mot,OUTPUT);
  pinMode(pir,INPUT);
  pinMode(buz,OUTPUT);
  lcd.begin(16,2);
  lcd.print(" WELCOME");
  delay(1000);
  myservo.write(0);

}

void loop()
{
  
 int pval=digitalRead(pir);
 lcd.clear();
 lcd.print("P:"+String(pval));

 if(pval==1)
 {
 
  Serial.print("7127751188,8256967330:AAEt8Xolq8s2cCImiBea36piYNF9CiFfmfY,Indu,indu7777,Security Alert,1,0,\n");
  delay(10000);
 }
if(Serial.available())
{
  int x=Serial.read();
  if(x=='1')
  {
    digitalWrite(mot,1);
    myservo.write(90);
  }
  if(x=='2')
  {
    digitalWrite(mot,0);
    myservo.write(0);
     digitalWrite(buz,1);
  delay(1000);
  digitalWrite(buz,0);
  }
}
}