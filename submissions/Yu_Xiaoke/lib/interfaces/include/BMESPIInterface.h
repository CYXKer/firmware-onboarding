#pragma once
#include <Adafruit_BME280.h>
#include <SPI.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface();
    bool init ();
    void read();
    float get_temperature_c() const;

private:
    Adafruit_BME280 _bme;
    float _temperature_c=0.0f;
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;