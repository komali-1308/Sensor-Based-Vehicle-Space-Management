#include <ThingSpeak.h> 
#include <LiquidCrystal.h> 
const int rs =8, en =9, d4 =10, d5 =11, d6 =12, d7 =13; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
#include <Servo.h> 
Servo myservo; 
int ir=2; 
int ir1=4; 
int ir2=5; 
int ir3=7; 
int ir4=A0; 
int cnt=0; 
void setup()  
{ 
  Serial.begin(115200); 
  myservo.attach(A5); 
  lcd.begin(16,2); 
  lcd.setCursor(4,0); 
  lcd.print("WELCOME"); 
  lcd.setCursor(0,1); 
  lcd.print("ITM"); 
  delay(1500); 
  lcd.clear(); 
 pinMode(ir,INPUT); 
 pinMode(ir1,INPUT); 
 pinMode(ir2,INPUT); 
 pinMode(ir3,INPUT); 
 pinMode(ir4,INPUT); 
 wifi_init(); 
} 
void loop() { 
  int sen1=digitalRead(ir); 
  int sen2=digitalRead(ir1);  
  int sen3=digitalRead(ir2);  
  int sen4=digitalRead(ir3);  
  int sen5=digitalRead(ir4);  
 lcd.clear(); 
  lcd.setCursor(0,0); 
 lcd.print("S1:"); 
 lcd.setCursor(3,0); 
 lcd.print(sen1); 
 lcd.setCursor(7,0); 
 lcd.print("S2:"); 
 lcd.setCursor(10,0); 

 lcd.print(sen2); 
 lcd.setCursor(0,1); 
 lcd.print("S3:"); 
 lcd.setCursor(3,1); 
 lcd.print(sen3); 
 lcd.setCursor(7,1); 
 lcd.print("S4:"); 
 lcd.setCursor(10,1); 
 lcd.print(sen4); 
 delay(500); 
 cnt=cnt+1; 
 if (cnt>10) 
 { 
  cnt=0; 
 upload(sen1,sen2,sen3,sen4); 
}  
 if(sen5==0) 
  {  
    myservo.write(90); 
  } 
  else 
  { 
    myservo.write(0); 
 } 
} 
 void wifi_init() 
 { 
  Serial.println("AT+RST"); 
  delay(4000); 
  Serial.println("AT+CWMODE=3"); 
  delay(4000); 
  Serial.print("AT+CWJAP="); 
  Serial.write('"'); 
  Serial.print("Ecs(sbvsm)"); // ssid/user name 
  Serial.write('"'); 
  Serial.write(','); 
  Serial.write('"'); 
  Serial.print("ecs@1234"); //password 
  Serial.write('"'); 
  Serial.println(); 
  delay(1000); 
 } 
void upload(int x, int y, int z,int p) //ldr copied int to - x   and gas copied into -y 
{ 
   
  String cmd = "AT+CIPSTART=\"TCP\",\""; 
  cmd += "184.106.153.149"; // api.thingspeak.com 
  cmd += "\",80"; 
  Serial.println(cmd); 
  delay(1000); 
  String getStr ="GET /update?api_key=S2SF2JAVZS8MQ7D5&field1="; 
  getStr += String(x); 
  getStr +="&field2="; 
  getStr += String(y); 
  getStr +="&field3="; 
  getStr += String(z); 
  getStr +="&field4="; 
  getStr += String(p); 
  getStr += "\r\n\r\n"; 
 
  cmd = "AT+CIPSEND="; 
  cmd += String(getStr.length()); 
 Serial.println(cmd); 
  delay(1000); 
  Serial.println(getStr); 
} 
