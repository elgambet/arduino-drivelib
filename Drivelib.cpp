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
* @param {int} [optional, default 10] ena speed for motor 1
* @param {int} [optional, default 5] enb speed for motor 2
*/
Drivelib::Drivelib(int in1, int in2, int in3, int in4, int ena, int enb)
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
};

/**
* Move forward
*/
void Drivelib::forward()
{ 
  digitalWrite(this->ENA, HIGH);
  digitalWrite(this->ENB, HIGH);
  digitalWrite(this->in1, HIGH);
  digitalWrite(this->in2, LOW);
  digitalWrite(this->in3, HIGH);
  digitalWrite(this->in4, LOW);
  Serial.println("Forward");
}

/**
* Move backward
*/
void Drivelib::backward()
{
  digitalWrite(this->ENA, HIGH);
  digitalWrite(this->ENB, HIGH);
  digitalWrite(this->in1, LOW);//digital output
  digitalWrite(this->in2, HIGH);
  digitalWrite(this->in3, LOW);
  digitalWrite(this->in4, HIGH);
  Serial.println("Back");
}

/**
* Turn left
*/
void Drivelib::left()
{
  digitalWrite(this->ENA, HIGH);
  digitalWrite(this->ENB, HIGH);
  digitalWrite(this->in1, LOW);
  digitalWrite(this->in2, HIGH);
  digitalWrite(this->in3, HIGH);
  digitalWrite(this->in4, LOW);
  Serial.println("Left");
}

/**
* Turn right
*/
void Drivelib::right()
{
  digitalWrite(this->ENA, HIGH);
  digitalWrite(this->ENB, HIGH);
  digitalWrite(this->in1, HIGH);
  digitalWrite(this->in2, LOW);
  digitalWrite(this->in3, LOW);
  digitalWrite(this->in4, HIGH);
  Serial.println("Right");
}

/**
* Move forward
*/
void Drivelib::bark()
{
  digitalWrite(this->ENA, HIGH);
  digitalWrite(this->ENB, HIGH);
  digitalWrite(this->in1, HIGH);
  digitalWrite(this->in2, HIGH);
  digitalWrite(this->in3, HIGH);
  digitalWrite(this->in4, HIGH);
  Serial.println("Bark");
}

/**
* Break the car
*/
void Drivelib::breakcar()
{
  digitalWrite(this->ENA, HIGH);
  digitalWrite(this->ENB, HIGH);
  digitalWrite(this->in1, LOW);
  digitalWrite(this->in2, LOW);
  digitalWrite(this->in3, LOW);
  digitalWrite(this->in4, LOW);
  Serial.println("Break");
}

/**
* Stop the car
*/
void Drivelib::stop()
{
  digitalWrite(this->ENA, LOW);
  digitalWrite(this->ENB, LOW);
  digitalWrite(this->in1, LOW);
  digitalWrite(this->in2, LOW);
  digitalWrite(this->in3, LOW);
  digitalWrite(this->in4, LOW);
  Serial.println("Stop");
}