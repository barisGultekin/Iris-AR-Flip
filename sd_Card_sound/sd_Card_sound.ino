#include "SD.h"       
#include "TMRpcm.h"   
#include "SPI.h"      

// tmrpcm.setVolume(4);   
// tmrpcm.play("name.wav"); 

#define SD_ChipSelectPin 4
TMRpcm tmrpcm;
int mode = 1;
void setup(){
  pinMode(2,INPUT);
  pinMode(7,INPUT);
  tmrpcm.speakerPin = 9; //PWM
  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) 
    {
      Serial.println("SD BASARISIZ");
      return;
    }
  
  start:

  
  if(mode == 1)
  {
    tmrpcm.setVolume(5);
    tmrpcm.play("four.wav");
    while(true)
    {
      if(digitalRead(2) == 0)
      {
        mode = 2;
        while(digitalRead(2) == 0){}
        delay(600);
        goto start;
      }
      if(digitalRead(7) == 0)
      {
        mode = 5;
        while(digitalRead(7) == 0){}
        delay(600);
        goto start;
      }
    }
  }

  
  if(mode == 2)
  {
    tmrpcm.setVolume(5);
    tmrpcm.play("five.wav");
    while(true)
    {
      if(digitalRead(2) == 0)
      {
        mode = 3;
        while(digitalRead(2) == 0) {}
        delay(600);
        goto start;
      }
      if(digitalRead(7) == 0)
      {
        mode = 1;
        while(digitalRead(7) == 0){}
        delay(600);
        goto start;
      }
    }
  }
  
  
  if(mode == 3)
  {
    tmrpcm.setVolume(5);
    tmrpcm.play("three.wav");
    while(true)
    {
      if(digitalRead(2) == 0)
      {
        mode = 4;
        while(digitalRead(2) == 0){}
        delay(600);
        goto start;
      }
      if(digitalRead(7) == 0)
      {
        mode = 2;
        while(digitalRead(7) == 0){}
        delay(600);
        goto start;
      }
    }  
  }
  if(mode == 4)
  {
    tmrpcm.setVolume(5);
    tmrpcm.play("four.wav");
    while(true)
    {
      if(digitalRead(2) == 0)
      {
        mode = 5;
        while(digitalRead(2) == 0){}
        delay(600);
        goto start;
      }
      if(digitalRead(7) == 0)
      {
        mode = 3;
        while(digitalRead(7) == 0){}
        delay(600);
        goto start;
      }
    }  
  }
  if(mode == 5)
  {
    tmrpcm.setVolume(5);
    tmrpcm.play("five.wav");
    while(true)
    {
      if(digitalRead(2) == 0)
      {
        mode = 1;
        while(digitalRead(2) == 0){}
        delay(600);
        goto start;
      }
      if(digitalRead(7) == 0)
      {
        mode = 4;
        while(digitalRead(7) == 0){}
        delay(600);
        goto start;
      }
    }  
  }
}

void loop(){ }
