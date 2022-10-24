# Color Sensing Vehicle
* Period : 2021.04-2021.06 (3 months)
* Personnel : 5 person
* Development environment : Arduino IDE
* Development language : C++
* Development goals  
  * 운반차가 2개의 DC모터를 이용하여 목적지에 정확하게 도달합니다.
  * 2개의 서보모터로 안전하게 감지한 사물을 들어올리고 내려놓습니다.
  * 색상 감지 센서에서 사물의 색상을 감지하고 색상에 따라 설정한 경로로 움직입니다. 

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

## Code Review
* s0핀을 HIGH s1핀을 LOW로 설정하면서 주파수를 20% 크기로 출력할 수 있도록 설정합니다.
* s1,s2 핀을 조합하여 빨강, 초록, 파랑의 주파수 값을 받아옵니다.
* pulseIn 함수를 통해 주파수의 값을 가져오고 그 값이 0~255 범위로 가져옵니다.

```C
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,LOW);
  
  digitalWrite(s2,LOW);               
  digitalWrite(s3,LOW);
  
  red_color = pulseIn(out_pin, LOW);
  red_color = map(red_color,25,72,255,0);  
  red_color = constrain(red_color,0,255);
```

* 수직과 수평을 제어하기 위한 서보모터 2 개를 12번 핀과 13번 핀으로 구성합니다.
* 12번 서보모터는 75도, 50도로 설정하여 수직으로 들어올리고 내려 놓을 수 있도록 설계합니다.
* 13번 서보모터는 75도, 110도로 설정하여 수평으로 잡고 풀 수 있도록 설계합니다.

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
* 평소처럼 아두이노 실습을 강의에 맞춰서 진행하는 것이 아닌 직접 프로젝트를 설계하고 진행하며 많은 도움이 되었습니다.
* 프로젝트에서 사용되는 각 하드웨어의 데이터시트 및 오픈소스를 활용하며 스스로 하드웨어를 작동시키는 것에 즐거움을 느낄 수 있었습니다.
* 4명의 팀원들과 컬러 감지 운반차를 진행하면서 각자의 역할을 수행하고 소통하면서 목표했던 결과물을 완성시킬 수 있어 의미가 있었습니다.

