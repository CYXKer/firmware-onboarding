#include "LEDController.h"

unsigned long LEDController::get_blink_interval_ms(float temperature_c) const
{
    if (temperature_c != temperature_c)
    {
        return BMEConstants::SLOW_BLINK_MS;
    }
    if (temperature_c <= BMEConstants::MIN_TEMP_C)
    {
        return BMEConstants::SLOW_BLINK_MS;
    }
    if (temperature_c >= BMEConstants::MAX_TEMP_C)
    {
        return BMEConstants::FAST_BLINK_MS;
    }
    float fraction =(temperature_c - BMEConstants::MIN_TEMP_C)/(BMEConstants::MAX_TEMP_C-BMEConstants::MIN_TEMP_C);
    float span = BMEConstants::SLOW_BLINK_MS - BMEConstants::FAST_BLINK_MS;
    return BMEConstants::SLOW_BLINK_MS-(unsigned long)(fraction*span);
}

bool LEDController::update(unsigned long now_ms, float temperature_c)
{
    unsigned long interval_ms=get_blink_interval_ms(temperature_c);
    if(now_ms- _last_toggle_ms >= interval_ms)
    {
        _led_on=!_led_on;
        _last_toggle_ms=now_ms;
    }

    return _led_on;
}