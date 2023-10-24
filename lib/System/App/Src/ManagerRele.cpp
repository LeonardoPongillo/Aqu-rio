#include <App/Inc/ManagerRele.h>

ManagerRele* ManagerRele::instance_ = nullptr;

ManagerRele::ManagerRele()
{
    Rele1 = new GPIOs(rele_1_gpio);
    Rele2 = new GPIOs(rele_2_gpio);
}

ManagerRele::~ManagerRele()
{

}

ManagerRele* ManagerRele::getInstance()
{
    if(instance_ == nullptr)
    {
        instance_ = new ManagerRele();
    }
    return instance_;
}

void ManagerRele::init()
{
    Rele1->set();
    Rele2->set();
}

void ManagerRele::check(RELE rele, TASK task)
{
    switch (rele)
    {
        case LIGHT :
        {
                 if(task == LIGAR)   { Rele1->reset(); }
            else if(task == DESLIGAR){ Rele1->set(); }
        }
        break;

        case PUMP :
        {
                 if(task == LIGAR)   { Rele2->reset(); }
            else if(task == DESLIGAR){ Rele2->set(); }
        }    
        break;
    
        default:
            break;
    }
}