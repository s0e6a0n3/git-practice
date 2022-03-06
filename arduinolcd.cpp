#include <LiquidCrystal_I2C.h>

#define trigPin 2
#define echoPin 3

  LiquidCrystal_I2C lcd(0x27,16,2);

int ultrasonic(){
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration*0.034/2;
  return distance;
}



void setup() {
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
lcd.init();
lcd.backlight();
delay(1000);// put your setup code here, to run once:
}

void loop() {
 lcd.clear();
 lcd.setCursor(0,0);
 
 int dist=ultrasonic();
 lcd.print(dist);
 lcd.print("cm");
 delay(500);
 // put your main code here, to run repeatedly:
}
