
#include <Arduino.h>
#include <stdint.h>
#include <App/Inc/ManagerSystem.h>

ManagerSystem* system_ = nullptr;


void setup( )
{ 
  Serial.begin(9600);
  Serial.println("");
  Serial.println("Iniciando");

  system_ = new ManagerSystem();
  system_->init();
}

void loop( )
{
  system_->check();
}