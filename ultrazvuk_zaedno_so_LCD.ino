#include <LiquidCrystal.h>
#include <Servo.h>

const int rs = 12, en = 11, d4 = 6, d5 = 4, d6 = 13, d7 = 2;
LiquidCrystal  lcd(rs, en, d4, d5, d6, d7);
const int trigPin = 9;
const int echoPin = 3;
long duration;
int distanceCm;

int servoPin1 = 10;
int servoPin2 = 5;

Servo servo1;
Servo servo2;
int pos = 0; 

int printDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  lcd.setCursor(0, 1); 
  lcd.print("Distance: "); 
  lcd.print(distanceCm);
  lcd.print("cm    ");
  delay(10);
  return distanceCm;
}

void setup() {
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo1.attach(servoPin1, 0, 90);
  servo1.write(0);
  servo2.attach(servoPin2, 0, 270);
  servo2.write(0);  
}

void loop() {

  int pauza=500;
  int chekor1=10;
  int chekor2=10;
  int granica1=90;
  int granica2=270;
  int granica1d=0;
  float koeficient1=2;
  float koeficient2=2.0/3;

  for(int agol1=granica1d; agol1<=granica1; agol1+=chekor1)
  {
    servo1.write(agol1*koeficient1); 
    lcd.setCursor(10, 0);
    lcd.print("M2:");
    lcd.print(agol1);
    lcd.print("   ");
    delay(pauza); 
    for(int agol2=0; agol2<=granica2; agol2+=chekor2)
    {
      servo2.write(agol2*koeficient2); 
      lcd.setCursor(0, 0);
      lcd.print("M1:");
      lcd.print(agol2);
      lcd.print("   ");
      delay(pauza);
      distanceCm=printDistance();

      while(distanceCm<10)
      {
        distanceCm=printDistance();
      }
    }
    for(int agol2=granica2; agol2>=0; agol2-=chekor2)
    {
      servo2.write(agol2*koeficient2); 
      lcd.setCursor(0, 0);
      lcd.print("M1:");
      lcd.print(agol2);
      lcd.print("   ");
      delay(pauza);
      distanceCm=printDistance();

      while(distanceCm<10)
      {
        distanceCm=printDistance();
      }
    }
    
  }
  

    for(int agol1=granica1; agol1>=granica1d; agol1-=chekor1)
  {
    servo1.write(agol1*koeficient1); 
    lcd.setCursor(10, 0);
    lcd.print("M2:");
    lcd.print(agol1);
    lcd.print("   ");
    delay(pauza); 
    for(int agol2=0; agol2<=granica2; agol2+=chekor2)
    {
      servo2.write(agol2*koeficient2); 
      lcd.setCursor(0, 0);
      lcd.print("M1:");
      lcd.print(agol2);
      lcd.print("   ");
      delay(pauza);
      distanceCm=printDistance();

      while(distanceCm<10)
      {
        distanceCm=printDistance();
      }
    }
    for(int agol2=granica2; agol2>=0; agol2-=chekor2)
    {
      servo2.write(agol2*koeficient2); 
      lcd.setCursor(0, 0);
      lcd.print("M1:");
      lcd.print(agol2);
      lcd.print("   ");
      delay(pauza);
      distanceCm=printDistance();

      while(distanceCm<10)
      {
        distanceCm=printDistance();
      }
    }
  }

}