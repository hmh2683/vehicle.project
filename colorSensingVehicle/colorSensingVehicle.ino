#include <Servo.h>
#define EN1 8     
#define EN2 9
#define EN3 10
#define EN4 11 

void Put(void);
void Hold(void);
void Front(void);
void Back(void);
void Right(void);
void Left(void);
void Stop(void);

Servo tiltservo;        
Servo gripservo;

const int tilt_servo = 12;
const int grip_servo = 13; 

//s0, s1 pins set the size of the frequency
const byte s0 = A0; 
const byte s1 = A1;

//s2, s3 pins specify color
const byte s2 = A2;
const byte s3 = A3;
const byte out_pin = 2; 

const int led_pin = 3;

int red_color = 0;
int green_color = 0;
int blue_color = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(EN1,OUTPUT); 
  pinMode(EN2,OUTPUT);
  pinMode(EN3,OUTPUT);
  pinMode(EN4,OUTPUT);
  
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);  
  pinMode(out_pin,INPUT);
  
  pinMode(led_pin, INPUT);
  
  //frequency output size 20%
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,LOW);

  tiltservo.attach(tilt_servo);  
  gripservo.attach(grip_servo);
  gripservo.write(110);
  tiltservo.write(50);

  digitalWrite(EN1,LOW);
  digitalWrite(EN2,LOW);
  digitalWrite(EN3,LOW);
  digitalWrite(EN4,LOW); 
}

void loop() {
  //red color read
  digitalWrite(s2,LOW);               
  digitalWrite(s3,LOW);
  
  //Read the frequency value and output it in the range of 0~255
  red_color = pulseIn(out_pin, LOW);
  red_color = map(red_color,25,72,255,0);  
  red_color = constrain(red_color,0,255);
  
  Serial.print("RED:");
  Serial.print(red_color);
  Serial.print(" ");
  delay(50);
  
  //green color read
  digitalWrite(s2,HIGH);            
  digitalWrite(s3,HIGH);
  
  //Read the frequency value and output it in the range of 0~255
  green_color = pulseIn(out_pin, LOW); 
  green_color = map(green_color, 30,90,255,0);   
  green_color = constrain(green_color, 0, 255);
  
  Serial.print("GREEN:");
  Serial.print(green_color);
  Serial.print(" ");
  delay(50);
  
  //blue color read
  digitalWrite(s2,LOW);               
  digitalWrite(s3,HIGH);             
  
  
  //Read the frequency value and output it in the range of 0~255
  blue_color = pulseIn(out_pin, LOW);
  blue_color = map(blue_color, 25,70,255,0); 
  blue_color = constrain(blue_color, 0, 255);
  
  Serial.print("BLUE:");
  Serial.print(blue_color);
  Serial.println(" ");
  delay(50);
  
  //Action when red is detected
  if(red_color > 50){               
    Hold();
    digitalWrite(led_pin, HIGH);
    Right();
    delay(600);
    Stop();
    delay(1000);
    
    Put();
    Left();
    delay(600);
    Stop();
    delay(1000);
    digitalWrite(led_pin, LOW);
  } 
  //Action when green is detected
  else if(green_color > 100){  
    Hold();
    Back();
    delay(1000);
    Left();
    delay(1200);
    Front();
    delay(2000);
    Stop();
    delay(1000);
   
    Put();
    Back();
    delay(2000);
    Left();
    delay(1200);
    Front();
    delay(1000);
    Stop(); 
    delay(1000);
  }
  //Action when blue is detected
  else if(blue_color > 100){   
    Hold();
    Back();
    delay(1000);
    Left();
    delay(600);
    Front();
    delay(1000);
    Left();
    delay(600);
    Front();
    delay(2000);
    Stop();
    delay(1000);
   
    Put();
    Back();
    delay(2000);
    Left();
    delay(600);
    Front();
    delay(1000);
    Left();
    delay(600);
    Front();
    delay(1000);
    Stop(); 
    delay(1000);
  }
  else{                              
   Put();
  }
}


void Put(){
  tiltservo.write(50);  
  delay(100);
  gripservo.write(110); 
  delay(200);
}

void Hold(){
  gripservo.write(75); 
  delay(200);
  tiltservo.write(75);
  delay(100);
}

void Front(){
  digitalWrite(EN1,HIGH);
  digitalWrite(EN2,LOW);
  digitalWrite(EN3,HIGH);
  digitalWrite(EN4,LOW);
}

void Back(){
  digitalWrite(EN1,LOW);
  digitalWrite(EN2,HIGH);
  digitalWrite(EN3,LOW);
  digitalWrite(EN4,HIGH);
}

void Right(){
  digitalWrite(EN1,HIGH);
  digitalWrite(EN2,LOW);
  digitalWrite(EN3,LOW);
  digitalWrite(EN4,HIGH);
}

void Left(){
  digitalWrite(EN1,LOW);
  digitalWrite(EN2,HIGH);
  digitalWrite(EN3,HIGH);
  digitalWrite(EN4,LOW);
}

void Stop(){
  digitalWrite(EN1,LOW);
  digitalWrite(EN2,LOW);
  digitalWrite(EN3,LOW);
  digitalWrite(EN4,LOW);
}
