#ifndef MANAGERWIFI_H
#define MANAGERWIFI_H

#include <WiFi.h>
#include <stdint.h>

#define wifi_ssid        "Leonardo2.4"
#define wifi_password    "132548132548"

enum STATUSWIFI
{
    NONE = -1,
    CONECTADO,
    DESCONECTADO
};

class ManagerWifi
{

public:
    static ManagerWifi* getInstance();
    uint8_t getStatusWifi();
    void check_event();
    void init();

private:
    ManagerWifi();
    ~ManagerWifi();

    void reconectar_wifi();

    static ManagerWifi* instance_;
    uint8_t status_;

};

#endif