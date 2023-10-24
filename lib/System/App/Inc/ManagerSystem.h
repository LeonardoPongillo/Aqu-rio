#ifndef MANAGERSYSTEM_H
#define MANAGERSYSTEM_H

#include <Arduino.h>
#include <App/Inc/ManagerWifi.h>
#include <App/Inc/ManagerAlexa.h>
#include <App/Inc/ManagerRele.h>

class ManagerSystem
{
public:
    ManagerSystem();
    ~ManagerSystem();
    void check();
    void init();

private:
    

};

#endif