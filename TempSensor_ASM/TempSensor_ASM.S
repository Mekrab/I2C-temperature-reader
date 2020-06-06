#include "avr/io.h"

//Gobal Temp 
  .global read_temp

read_temp:

;initiate //Initiate function
  ldi r18,0x00 //load TWSR to 0
  sts 0xB9,r17 //Put rate

  ldi r17,0x48 //load address of device
  sts 0xB8,r17

;start//start function
  ldi r17,0b10100100
  sts 0xBC,r17
  
  waitstart://waitstart function
  lds r16,0xBC
  sbrs r16,7
  rjmp waitstart

;setread //read function
  ldi r17,0b10010001
  sts 0xBB,r17

  ldi r17,0b11000100
  sts 0xBC,r17
  
  waitset: //waitset function
  lds r16,0xBC
  sbrs r16,7
  rjmp waitset

;readhere // readhere function
  ldi r17,0b10000100
  sts 0xBC,r17

  waitread:// waitread function
  lds r16,0xBC
  sbrs r16,7
  jmp waitread


;stop//stop condition 
  ldi r17,0b10010100
  sts 0xBC,r17
