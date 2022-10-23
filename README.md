# Color sensing vehicle
* Period : 2021.04-2021.06 (3 months)
* Personnel : 5 person
* Development environment : Arduino IDE
* Development language : C++
* Development goals  
  * 운반차가 DC모터를 사용하여 목적지에 정확하게 도달할 수 있습니다.
  * 2 개의 서보모터로 감지한 사물을 들어올릴 수 있습니다. 
  * 색상 감지 센서에서 사물의 색상을 감지하고 색상에 따라 설정한 경로로 움직일 수 있습니다. 

<br/> <br/>

## Microcontroller
<a href="#"><img src="?" width="350px" height="350px"></a> 
* Board : Arduino Uno (M3)
* Core : AVR ATMega328 
* Clock Speed : 16MHz
* Digital I/O Pins : 14 (of which 6 provide PWM output)
* Analog Input Pins : 6

<br/> <br/>

## Pinout Configuration
* LED -> OUTPUT -> 2
* DCMotor -> OUTPUT -> 8, 9, 10, 11
* ServoMotor -> OUTPUT -> 12, 13 
* ColorSensor -> OUTPUT -> A0, A1, A2, A3
* ColorSensor -> INPUT -> 3

<br/> <br/>

## Code review
* 
```C
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,LOW);
  
  digitalWrite(s2,LOW);               
  digitalWrite(s3,LOW);
  
  red_color = pulseIn(out_pin, LOW);
  red_color = map(red_color,25,72,255,0);  
  red_color = constrain(red_color,0,255);
```
* 수직과 수평을 제어하기 위한 서보모터 2 개를 12번 핀과 13번 핀으로 구성하였습니다.
* 12번 서보모터는 75도, 50도를 설정하여 올리고 내릴 수 있도록 하고, 13번 모터는 75도, 110도를 설정하여 수평으로 잡고 풀 수 있도록 하여 물건을 지탱할 수 있도록 설계하였습니다.
```C
  tiltservo.attach(12);  
  gripservo.attach(13);

  gripservo.write(75); 
  delay(200);
  tiltservo.write(75);
  delay(100);
  
  tiltservo.write(50);  
  delay(100);
  gripservo.write(110); 
  delay(200);
```

<br/> <br/>

## Result
<a href="#"><img src="?" width="500px" height="400px"></a>
<a href="#"><img src="?" width="500px" height="400px"></a>

<br/> <br/>

## Realization
* 


