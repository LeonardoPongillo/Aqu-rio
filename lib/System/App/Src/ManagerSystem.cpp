#include <App/Inc/ManagerSystem.h>

ManagerSystem::ManagerSystem()
{
    ManagerWifi::getInstance();
    ManagerAlexa::getInstance();
    ManagerRele::getInstance();
}

ManagerSystem::~ManagerSystem()
{

}

void ManagerSystem::check()
{

    ManagerWifi::getInstance()->check_event();
    ManagerAlexa::getInstance()->check_event();
}

void ManagerSystem::init()
{
    ManagerRele::getInstance()->init();
    ManagerWifi::getInstance()->init();
    ManagerAlexa::getInstance()->init();
}