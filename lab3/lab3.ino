/*
*     Лабораторная работа 3
*     "Бегущая строка"
*     Автор: XxNagibatorxX
*     Дата создания: 15.04.2015
*/
#include <SPI.h>
#define SS_PIN 10
byte digit[10] = {
  0b00111111,
  0b00000110,
  0b01011011,
  0b01001111,
  0b01100110,
  0b01101101,
  0b01111101,
  0b00000111,
  0b01111111,
  0b01101111
};
void setup(){
pinMode(SS_PIN, OUTPUT);
SPI.begin();

}

void loop(){
drawLine();
}
void drawLine() {
	for(int i=0; i<8; i++){
	digitalWrite(SS_PIN, LOW);
	SPI.transfer(0xFF -(1<<i));
	SPI.transfer(0xFF);
	digitalWrite(SS_PIN, HIGH);
	delay(125);
}

}
