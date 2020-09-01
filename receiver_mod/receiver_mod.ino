// receiver.pde
//
// Simple example of how to use VirtualWire to receive messages
// Implements a simplex (one-way) receiver with an Rx-B1 module
//
// See VirtualWire.h for detailed API docs
// Author: Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2008 Mike McCauley
// $Id: receiver.pde,v 1.3 2009/03/30 00:07:24 mikem Exp $

#include <VirtualWire.h>

int ledPassive = 5;
int ledActive = 7;
int buzzer = 8;


void setup()
{ 
  pinMode(ledPassive,OUTPUT);
  pinMode(ledActive,OUTPUT);
  pinMode(buzzer,OUTPUT);
  vw_set_ptt_inverted(true);
  vw_set_rx_pin(12);
  vw_setup(4000);
  vw_rx_start();
}
  void loop() {
    digitalWrite(ledPassive,HIGH);
    digitalWrite(buzzer,LOW);
    digitalWrite(ledActive,LOW);
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)){
      if(buf[0]=='X'){
        digitalWrite(ledPassive,LOW);
        for(int i=0;i<10;i++){
          digitalWrite(buzzer,LOW);
          digitalWrite(ledActive,HIGH);
          delay(200);
          digitalWrite(buzzer,HIGH);
          digitalWrite(ledActive,LOW);
          delay(200);
        }
      }
      else if(buf[0]!='X'){
        digitalWrite(ledPassive,HIGH);
      }
    }
  }

