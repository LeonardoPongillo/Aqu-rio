#ifndef MANAGERALEXA_H
#define MANAGERALEXA_H

#include <Arduino.h>
#include <Espalexa.h>
#include <App/Inc/ManagerWifi.h>
#include <App/Inc/ManagerRele.h>

class ManagerAlexa
{
    String device_1 = "Luz aquario";
    String device_2 = "Bomba aquario";

public:
    static ManagerAlexa* getInstance();
    void check_event();
    void init();
    void check_luz();
    void check_bomba();

private:
    ManagerAlexa();
    ~ManagerAlexa();

    static ManagerAlexa* instance_;

    Espalexa espalexa;

    bool isInit = false;

};

#endif