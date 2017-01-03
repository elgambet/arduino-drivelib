/*
  Drivelib.h - Library for controlling elegoo smart robot car v1.0
  Created by Pablo Gambetta December 2016
  Released into the public domain.
*/
#ifndef Drivelib_h
#define Drivelib_h

#include "Arduino.h"

class Drivelib
{
  public:
    Drivelib(int in1=9, int in2=8, int in3=7, int in4=6, int ena=11, int enb=5, int default_speed=127);
    void init();
    void faster();
    void slower();
    void speed(int speed);
    void forward_motor_1(int speed = 0);
    void forward_motor_2(int speed = 0);
    void forward();
    void backward_motor_1(int speed = 0);
    void backward_motor_2(int speed = 0);
    void backward();
    void left(bool fast_turn = true);
    void right(bool fast_turn = true);
    void bark();
    void breakcar();
    void stop(bool reset_speed = true);
  private:
    int in1; // Motor 1
    int in2; // Motor 1
    int in3; // Motor 2
    int in4; // Motor 2
    /*define channel enable output pins*/
    int ENA; // Speed of motor 1
    int ENB; // Speed of motor 2
    int actual_speed;
    int default_speed;
};

#endif