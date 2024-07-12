#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Stream.h>

//藍牙模組的tx接10,rx接11
//伺服馬達接9



SoftwareSerial BT(10,11); // 定義Arduino PIN10及PIN11分別為RX及TX腳

char forward_backward;
int speed=0,direction=90;


void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  BT.begin(9600);
}
void turn(int d){
  if(d>0){
    digitalWrite(4, LOW);
    digitalWrite(4, HIGH);
  }else if(d<0){
    digitalWrite(4, HIGH);
    digitalWrite(4, LOW);
  }
  analogWrite(3, abs(d));
}

void loop() {
  //if(BT.available()){
  //  Serial.println(BT.readString());
  //}
  //  put your main code here, to run repeatedly:
  
  if(BT.available()){
    String movement = BT.readString();
    forward_backward = movement[1];
    speed = movement.substring(movement.indexOf('s'), movement.indexOf('d')).toInt();
    direction = movement.substring(movement.indexOf('d'), movement.length()).toInt();
  }
   turn(direction);
   analogWrite(6, 100);
   digitalWrite(7, HIGH);
   digitalWrite(8, LOW);
}
