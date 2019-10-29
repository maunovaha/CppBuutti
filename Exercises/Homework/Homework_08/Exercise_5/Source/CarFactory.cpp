#include "CarFactory.h"

Car CarFactory::volkswagen()
{
    return {"Volkswagen", 50.0f, 5.2f};
}

Car CarFactory::peugeot()
{
    return {"Peugeot", 53.0f, 4.6f};
}

Car CarFactory::toyota()
{
    return {"Toyota", 44.0f, 6.6f};
}
