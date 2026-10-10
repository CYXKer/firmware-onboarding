#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    constexpr uint8_t I2C_ADDRESS = 0x76;
    constexpr uint8_t LED_PIN = 13;
    constexpr uint8_t SPI_CS_PIN = 10;
    constexpr unsigned long SERIAL_BAUD = 115200;
    constexpr unsigned long SENSOR_READ_INTERVAL_MS=500;
    constexpr float MIN_TEMP_C=24.0f;
    constexpr float MAX_TEMP_C=28.0f;
    constexpr unsigned long SLOW_BLINK_MS=1000;
    constexpr unsigned long FAST_BLINK_MS=100;
}