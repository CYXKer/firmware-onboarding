#pragma once
#include "BMEConstants.h"

class LEDController
{
public:
    LEDController()=default;
    unsigned long get_blink_interval_ms(float temperature_c) const;
    bool update(unsigned long now_ms, float temperature_c);

private:
    bool _led_on=false;
    unsigned long _last_toggle_ms=0;
};
