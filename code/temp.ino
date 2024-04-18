#include <OneWire.h>
#include <DallasTemperature.h>
 
 
#define ONE_WIRE_BUS 2
 
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensors.begin();
 
}
 
void loop() {
  // put your main code here, to run repeatedly:
  sensors.requestTemperatures();
  float temperature  = sensors.getTempFByIndex(0);
 
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" F");
 
  delay(1000);
 
}
