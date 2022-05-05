#include <Arduino.h>
#include "TemperatureHall.h"

/*------------------ Реализация функций внутреннего термометра -------------------*/
// функция получения температуры °C
float Temperature::getTemperature()
{
    _temperature = ((temprature_sens_read() - 32) / 1.8);
    return _temperature;
}
// функция вывода значения температуры °C в терминал
void Temperature::printTemperature()
{
    Serial.println((temprature_sens_read() - 32) / 1.8);
}

/*------------------ Реализация функций внутреннего датчика Холла -------------------*/
// функция получения значений датчика Холла
uint16_t Hall::getHall()
{
    _hall = hallRead();
    return _hall;
}
// функция вывода значений датчика Холла в терминал
void Hall::printHall()
{
    Serial.println(hallRead());
}
// функция изминения яркости светодиода от значений датчика Холла
void Hall::ledSensor(uint16_t ledPin)
{
    pinMode(ledPin, OUTPUT);
    ledcSetup(0, 5000, 8);
    ledcAttachPin(ledPin, 0);
    _hall = hallRead();
    _hall = map(_hall, 0, 600, 0, 253);
    ledcWrite(0, _hall);
}
