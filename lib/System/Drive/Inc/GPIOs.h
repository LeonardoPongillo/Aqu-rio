#ifndef GPIOS_H
#define GPIOS_H
#include <Arduino.h>    

struct struct_gpio_t
{
    uint8_t pin;
    uint8_t mode;
};

const struct_gpio_t rele_1_gpio = 
{
    .pin = 33,
    .mode = OUTPUT
};

const struct_gpio_t rele_2_gpio = 
{
    .pin = 32,
    .mode = OUTPUT
};

class GPIOs
{
public:
    GPIOs(struct_gpio_t gpio);
    ~GPIOs();
    void set();
    void reset();

private:
    struct_gpio_t gpio_;
};

#endif