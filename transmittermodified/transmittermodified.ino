// transmitter.pde
//
// Simple example of how to use VirtualWire to transmit messages
// Implements a simplex (one-way) transmitter with an TX-C1 module
//
// See VirtualWire.h for detailed API docs
// Author: Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2008 Mike McCauley
// $Id: transmitter.pde,v 1.3 2009/03/30 00:07:24 mikem Exp $

#include <VirtualWire.h>
const char *message = "Merry Christmas";
int button = 2;
const int transmit_pin = 12;


void setup()
{
    // Initialise the IO and ISR
    pinMode(button, INPUT);
    vw_set_tx_pin(transmit_pin);
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(4000);       // Bits per sec
    
    
}



  void loop (){
    if (digitalRead(button)==HIGH) {
    message="X";
    vw_send((uint8_t *)message, strlen(message));
    vw_wait_tx();
    
  
    delay(2000);
  }
  }
