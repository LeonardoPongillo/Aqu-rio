#include "Drive/Inc/GPIOs.h"

GPIOs::GPIOs(struct_gpio_t gpio) :
    gpio_(gpio)
{
    pinMode(gpio_.pin, gpio_.mode);
}

GPIOs::~GPIOs()
{

}

void GPIOs::set()
{
    digitalWrite(gpio_.pin, HIGH);
}

void GPIOs::reset()
{
    digitalWrite(gpio_.pin, LOW);
}