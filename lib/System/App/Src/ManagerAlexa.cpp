#include <App/Inc/ManagerAlexa.h>

ManagerAlexa* ManagerAlexa::instance_ = nullptr;

void callback_bomba(uint8_t value)
{
    Serial.println(value);

    if(value == 255)
    {
        ManagerRele::getInstance()->check(RELE::PUMP, TASK::LIGAR);
    }
    else
    {
         ManagerRele::getInstance()->check(RELE::PUMP, TASK::DESLIGAR);
    }
}

void callback_luz(uint8_t value)
{
    Serial.println(value);
    
    if(value == 255)
    {
        ManagerRele::getInstance()->check(RELE::LIGHT, TASK::LIGAR);
    }
    else
    {
        ManagerRele::getInstance()->check(RELE::LIGHT, TASK::DESLIGAR);
    }
}

ManagerAlexa::ManagerAlexa(){ }
ManagerAlexa::~ManagerAlexa(){ }

ManagerAlexa* ManagerAlexa::getInstance()
{
    if(instance_ == nullptr)
    {
        instance_ = new ManagerAlexa();
    }
    return instance_;
}

void ManagerAlexa::init()
{

}

void ManagerAlexa::check_event()
{
    uint8_t status_wifi = ManagerWifi::getInstance()->getStatusWifi();
    
    if( status_wifi == STATUSWIFI::CONECTADO )
    {
        if(isInit)
        {
           Serial.println("ALEXA INICIALIZADA");
            espalexa.loop();
        }
        else
        {
            Serial.println("ALEXA NÃO INICIALIZADA");
            espalexa.addDevice(device_2, callback_bomba);
            espalexa.addDevice(device_1, callback_luz);
            espalexa.begin();

            isInit = true;
        }
    }
    else
    {
        isInit = false;
    }
}
