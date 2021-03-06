#ifndef DHT_H
#define DHT_H
#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

// WioLTE STM32F405 compatibility
#define STM32F405


// 8 MHz(ish) AVR ---------------------------------------------------------
#if (F_CPU >= 7400000UL) && (F_CPU <= 9500000UL)
#define COUNT 3
// 16 MHz(ish) AVR --------------------------------------------------------
#elif (F_CPU >= 15400000UL) && (F_CPU <= 19000000L)
#define COUNT 6
#elif defined(STM32F405)
#define COUNT 40
#else
#error "CPU SPEED NOT SUPPORTED"
#endif

/* DHT library

MIT license
written by Adafruit Industries
*/

// how many timing transitions we need to keep track of. 2 * number bits + extra
#define MAXTIMINGS 85

#define DHT11 11
#define DHT22 22
#define DHT21 21
#define AM2301 21

class Dht11 {
 private:
  uint8_t data[6];
  uint8_t _pin, _type, _count;
  boolean read(void);
  unsigned long _lastreadtime;
  boolean firstreading;

 public:
  Dht11(uint8_t pin, uint8_t type=DHT11, uint8_t count=COUNT);
  void init(void);
  float getTemperature(bool S=false);
  float convertCtoF(float);
  float getHumidity(void);

};
#endif
