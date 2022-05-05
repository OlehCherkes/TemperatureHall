#pragma once

#ifdef __cplusplus
extern "C"
{
#endif
  uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif

// класс датчика температуры
class Temperature
{
public:
  float getTemperature();  // функция получения температуры °C
  void printTemperature(); // функция вывода значения температуры °C в терминал
private:
  float _temperature;
};

// класс датчика Холла
class Hall
{
public:
  uint16_t getHall();              // функция получения значений датчика Холла
  void printHall();                // функция вывода значений датчика Холла в терминал
  void ledSensor(uint16_t ledPin); // функция изминения яркости светодиода от значений датчика Холла
private:
  uint16_t _hall;
};
