#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

LEDController led_controller;
unsigned long last_read_ms=0;

void setup()
{
    Serial.begin(BMEConstants::SERIAL_BAUD);
    pinMode(BMEConstants::LED_PIN, OUTPUT);

    BMESPIInterfaceInstance::create();
    if(BMESPIInterfaceInstance::instance().init())
    {
        Serial.println("BME280 found over SPI.");
    }
    else
    {
        Serial.println("BME280 not found over SPI.");
    }
}

void loop()
{
    BMESPIInterface &bme=BMESPIInterfaceInstance::instance();
    unsigned long now_ms=millis();

    if (now_ms-last_read_ms >= BMEConstants::SENSOR_READ_INTERVAL_MS)
    {
        last_read_ms=now_ms;
        bme.read();

        Serial.print("Temperature: ");
        Serial.print(bme.get_temperature_c());
        Serial.print(" C blink interval:");
        Serial.print(led_controller.get_blink_interval_ms(bme.get_temperature_c()));
        Serial.println(" ms");
    }

    bool led_on=led_controller.update(now_ms, bme.get_temperature_c());
    digitalWrite(BMEConstants::LED_PIN, led_on ? HIGH : LOW);
}