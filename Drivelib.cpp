/*
  Drivelib.h - Library for controlling elegoo smart robot car v1.0
  Created by Pablo Gambetta December 2016
  Released into the public domain.
*/
#include "Arduino.h"
#include "Drivelib.h"

/**
* constructor
* @param {int} [optional, default 9] in1 pin mode definition for motor 1
* @param {int} [optional, default 8] in2 pin mode definition for motor 1
* @param {int} [optional, default 7] in3 pin mode definition for motor 2
* @param {int} [optional, default 6] in4 pin mode definition for motor 2
* @param {int} [optional, default 11] ena speed for motor 1 // should be 10, but is not working
* @param {int} [optional, default 5] enb speed for motor 2
* @param {int} [optional, default 127] default speed
*/
Drivelib::Drivelib(int in1, int in2, int in3, int in4, int ena, int enb, int default_speed)
{
    // Set pin modes
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(ena, OUTPUT);
    pinMode(enb, OUTPUT);
    
    // define logic control output pin
    this->in1=in1; // Motor 1
    this->in2=in2; // Motor 1
    this->in3=in3; // Motor 2
    this->in4=in4; // Motor 2

    // define channel enable output pins
    this->ENA=ena; // Speed of motor 1
    this->ENB=enb; // Speed of motor 2

    // Define default speed
    this->actual_speed = default_speed;
    this->default_speed = default_speed;
};

/**
* init
*/
void Drivelib::init()
{
    // Set pin modes
    pinMode(this->in1, OUTPUT);
    pinMode(this->in2, OUTPUT);
    pinMode(this->in3, OUTPUT);
    pinMode(this->in4, OUTPUT);
    pinMode(this->ENA, OUTPUT);
    pinMode(this->ENB, OUTPUT);
};

/**
* Move forward motor 1
*/
void Drivelib::forward_motor_1(int speed)
{ 
  if(speed == 0) speed = this->actual_speed;
  digitalWrite(this->in1, HIGH);
  digitalWrite(this->in2, LOW);
  analogWrite(this->ENA, speed);
}

/**
* Move forward motor 2
*/
void Drivelib::forward_motor_2(int speed)
{ 
  if(speed == 0) speed = this->actual_speed;
  digitalWrite(this->in3, LOW); // Should be "HIGH", but cables are inverted
  digitalWrite(this->in4, HIGH); // Should be "LOW", but cables are inverted
  analogWrite(this->ENB, speed);
}

/**
* Move backward motor 1
*/
void Drivelib::backward_motor_1(int speed)
{ 
  if(speed == 0) speed = this->actual_speed;
  digitalWrite(this->in1, LOW);
  digitalWrite(this->in2, HIGH);
  analogWrite(this->ENA, speed);
}

/**
* Move backward motor 2
*/
void Drivelib::backward_motor_2(int speed)
{ 
  if(speed == 0) speed = this->actual_speed;
  digitalWrite(this->in3, HIGH); // Should be "LOW", but cables are inverted
  digitalWrite(this->in4, LOW); // Should be "HIGH", but cables are inverted-
  analogWrite(this->ENB, speed);
}

/**
* Move forward
*/
void Drivelib::forward()
{ 
  Serial.print("forward");
  this->forward_motor_1();
  this->forward_motor_2();
}

/**
* Move backward
*/
void Drivelib::backward()
{
  Serial.print("backward");
  this->backward_motor_1();
  this->backward_motor_2();
}

/**
* Turn left
*/
void Drivelib::left(bool fast_turn)
{
  Serial.print("left");
  if(fast_turn){
    this->forward_motor_1(255);
    this->backward_motor_2(255);
  } else {
    this->forward_motor_1();
    this->backward_motor_2();
  }
}

/**
* Turn right
*/
void Drivelib::right(bool fast_turn)
{
  Serial.print("right");
  if(fast_turn){
    this->backward_motor_1(255);
    this->forward_motor_2(255);
  } else {
    this->backward_motor_1();
    this->forward_motor_2();
  }
}

/**
* Move forward
*/
void Drivelib::bark()
{
  Serial.print("bark");
  digitalWrite(this->ENA, HIGH);
  digitalWrite(this->ENB, HIGH);
  digitalWrite(this->in1, HIGH);
  digitalWrite(this->in2, HIGH);
  digitalWrite(this->in3, HIGH);
  digitalWrite(this->in4, HIGH);
}

/**
* Break the car
*/
void Drivelib::breakcar()
{
  this->stop();
  delay(50);
  this->backward();
  delay(50);
  this->stop();
}

/**
* Stop the car
*/
void Drivelib::stop(bool reset_speed)
{
  Serial.print("stop");
  digitalWrite(this->ENA, LOW);
  digitalWrite(this->ENB, LOW);
  digitalWrite(this->in1, LOW);
  digitalWrite(this->in2, LOW);
  digitalWrite(this->in3, LOW);
  digitalWrite(this->in4, LOW);
  if(reset_speed) this->actual_speed = this->default_speed;
}

void Drivelib::speed(int speed)
{
  if(speed >= 0 && speed <= 255) this->actual_speed = speed;
  else {
    if(speed < 0) this->actual_speed = 0;
    if(speed > 255) this->actual_speed = 255;
  }
  Serial.print("Speed: ");
  Serial.print(this->actual_speed);
  Serial.print(".");
}

void Drivelib::faster()
{
  int new_speed = this->actual_speed + 10;
  this->actual_speed = new_speed <= 255 ? new_speed : 255;
}

void Drivelib::slower()
{
  int new_speed = this->actual_speed - 10;
  this->actual_speed = new_speed >= 0 ? new_speed : 0;
}