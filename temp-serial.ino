#include <OneWire.h>
#include <DallasTemperature.h>
#include <SimpleTimer.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);
SimpleTimer timer;

void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
  timer.setInterval(5000, measureAndSend);
}

void loop()
{
  timer.run();
}

void measureAndSend(void) 
{
  sensors.requestTemperatures();
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print("\r\n");
}
