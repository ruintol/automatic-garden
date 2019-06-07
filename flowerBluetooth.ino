 int relay_pin=8;
int soil_sign = A0; 
int soil_val = 1050;
int tem_val=26;
#include <dht11.h>
#define DHT11PIN 9
//#define blueToothSerial Serial1 
dht11 DHT11;
#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);  
void setup()
{
   Serial.begin(9600); 
   pinMode(relay_pin,OUTPUT);
    pinMode(soil_sign, INPUT); 
  lcd.begin(16,2); 
  lcd.print("Watering System");
   attachInterrupt(digitalPinToInterrupt(1),togglerelay,RISING);  //  function for creating external interrupts at pin2 on Rising (LOW to HIGH)    
}
void loop()
{
int chk = DHT11.read(DHT11PIN);
int tem=(int)DHT11.temperature;
int hum=(int)DHT11.humidity;
  int sensorValue = analogRead(soil_sign);   
  lcd.clear();
  lcd.print("Watering System"); 
  lcd.setCursor(0,1);  
  lcd.print("S:"); 
  lcd.setCursor(2,1);
  lcd.print(sensorValue); 
  Serial.print("S:");
   Serial.println(sensorValue);
    lcd.setCursor(7,1);
   lcd.print("T:");
   lcd.setCursor(9,1);
  lcd.print(tem); 
    Serial.print("T:");
   Serial.println(tem);
      lcd.setCursor(12,1);
   lcd.print("H:");
   lcd.setCursor(14,1);
  lcd.print(hum);
      Serial.print("H:");
   Serial.println(hum);

if((analogRead(soil_sign) >soil_val))
  {
    digitalWrite(relay_pin,HIGH);
delay(300);
 digitalWrite(relay_pin,LOW); 
  }
  else{
    digitalWrite(relay_pin,LOW);
    
  }
 }
    void togglerelay(){
  if(Serial.available()>0){ 
     char ch = Serial.read(); 
if (ch=='A')
 {
digitalWrite(relay_pin,HIGH);
delay(3000);
  }
  if (ch=='B')
 {
digitalWrite(relay_pin,LOW);
  }
 }
   }
