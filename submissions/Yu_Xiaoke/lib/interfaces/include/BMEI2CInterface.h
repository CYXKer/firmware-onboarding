#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface
{
public:
    BMEI2CInterface()=default;
    bool init();
    void read();
    float get_temperature_c() const;

private:
    Adafruit_BME280 _bme;
    float _temperature_c = 0.0f;
};

using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;