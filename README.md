# Color sensing vehicle
* Period : 2021.04-2021.06 (3 months)
* Personnel : 5 person
* Development environment : Arduino IDE
* Development language : C++
* Development goals  
  * 바퀴가 이동할 수 있도록 제어
  * 서보모터 2개 를 활용하여 그립과 경사를 조정한다 
  * 물건 색상을 구분할 수 있도록 센서의 주파수 값을 제어한다.

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
### Main
* The if statement is executed according to the button variable that is interrupted.
```C


```

<br/> <br/>

## Result
### Photo
<a href="#"><img src="?" width="500px" height="400px"></a>
<a href="#"><img src="?" width="500px" height="400px"></a>

<br/> <br/>

## Realization
* The automatic generation of STM32CubeIDE confirmed that the pin was set up, and I was able to master how to use the interrupt and timer.


