#include "BMESPIInterface.h"

BMESPIInterface::BMESPIInterface()
    : _bme(BMEConstants::SPI_CS_PIN, &SPI)
{
}

bool BMESPIInterface::init()
{
    return _bme.begin();
}

void BMESPIInterface::read()
{
    _temperature_c =_bme.readTemperature();
}

float BMESPIInterface::get_temperature_c() const
{
    return _temperature_c;
}