# Color sensing vehicle
* Period : 2021.03-2021.06 (4 months)
* Personnel : 5 person
* Development environment : Arduino IDE
* Development language : C++
* Development goals  
  * 물건 색상을 구분할 수 있도록 센서의 주파수 값을 제어한다.
  * 
  * Control relay by comparing set temperature with current temperature and maintain and manage set temperature.

<br/> <br/>

## Microcontroller
<a href="#"><img src="?" width="350px" height="350px"></a> 
* Part : Arduino Uno (M3)
* Core : AVR ATMega328 
* Clock Speed : 16MHz
* Digital I/O Pins : 14 (of which 6 provide PWM output)
* Analog Input Pins : 6

<br/> <br/>

## Pinout Configuration
<a href="#"><img src="?" width="400px" height="400px"></a>

### System Core


### Connectivity
* SPI2 -> FND
  * Data Size : 8bit
  * First Bit : MSB
  * Prescaler : 16
  * Clock Polarity : High
  * Clock Phase : 1 Edge
* I2C2 -> OLED
  * Speed Mode : Fast Mode
  * Clock Speed : 400000 Hz
  * Fast Mode Duty Cycle : Duty cycle Tlow/Thigh = 2
* USART1 -> FTDI
  * Baud Rate : 115200 Bits/s
  * Word Length : 8 Bit
* ONEWIRE -> SENSOR

<br/> <br/>



## Code review
### Main
* The if statement is executed according to the button variable that is interrupted.
* LED is controlled according to the state of the start switch.
* Start temperature conversion and get temperature value.
* When the switch is on, the relay operates according to the temperature value, and when the switch is off, the relay does not operate regardless of the temperature value.
```C
while (1) {
	checkButton();
	checkStartSw();

	if (!isConverted()) 
		startConvert();
	
	checkConvert();
	if (!isConverted()) {
		temperature = getTemp();
		if (getStartSw() == ON_t) {
			relayControl(temperature);
		} else {
			if (getRelayState() == ON_t) 
				relayOnOff(OFF_t);
		}
	}
}
```

<br/> <br/>

## Result
### Photo
<a href="#"><img src="https://github.com/hmh2683/heatingroom.project/blob/main/images/result.png" width="500px" height="400px"></a>
<a href="#"><img src="https://github.com/hmh2683/heatingroom.project/blob/main/images/uart.png" width="500px" height="400px"></a>

<br/> <br/>

## Realization
* The automatic generation of STM32CubeIDE confirmed that the pin was set up, and I was able to master how to use the interrupt and timer.
* I learned C language grammar when I was an undergraduate, but I was able to learn how to use grammar and skills for the first time in the project and learn a little more about how to interact and include them in the library.
* I was able to learn about the communication between chips such as SPI, I2C, UART, and ONEWIRE, and I was able to learn and experience the communication method by directly modifying the software implementation using open source.

