#ifndef MANAGERRELE_H
#define MANAGERRELE_H

#include <Drive/Inc/GPIOs.h>

enum RELE
{
    NONERELE = -1,
    LIGHT,
    PUMP,
    MAXRELE
};

enum TASK
{
    NONETASK = -1,
    LIGAR,
    DESLIGAR,
    MAXTASK
};


class ManagerRele
{
public:
    static ManagerRele* getInstance();
    void check(RELE rele, TASK task);
    void init();

private:
    ManagerRele();
    ~ManagerRele();

    static ManagerRele* instance_;

    GPIOs* Rele1;
    GPIOs* Rele2;

};

#endif