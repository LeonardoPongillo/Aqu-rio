#include <App/Inc/ManagerWifi.h>

ManagerWifi* ManagerWifi::instance_ = nullptr;

ManagerWifi::ManagerWifi()
{
 
}

ManagerWifi::~ManagerWifi()
{

}

void ManagerWifi::init()
{
   WiFi.mode(WIFI_STA);
   WiFi.begin(wifi_ssid, wifi_password);
}

ManagerWifi* ManagerWifi::getInstance()
{
    if(instance_ == nullptr)
    {
        instance_ = new ManagerWifi();
    }
    return instance_;
}

uint8_t ManagerWifi::getStatusWifi()
{
    return status_;
}

void ManagerWifi::check_event()
{
    status_ = DESCONECTADO;

    switch((uint8_t)WiFi.status())
    {
        case WL_CONNECTED :
            Serial.println("Conectado");
            status_ = CONECTADO;
            break;
        
        case WL_CONNECT_FAILED :
            Serial.println("Falha na conexão");
            reconectar_wifi();
            break;
            
        case WL_CONNECTION_LOST :
            Serial.println("conexão perdida");
            reconectar_wifi();
            break;
        
        case WL_DISCONNECTED :
            Serial.println("Desconectado");
            reconectar_wifi();
            break;

        default:
            break;
    }
}

void ManagerWifi::reconectar_wifi()
{
    WiFi.reconnect();
    delay(2000);    
}