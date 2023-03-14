// This #include statement was automatically added by the Particle IDE.
#include <Grove_Temperature_And_Humidity_Sensor.h>


// Based On:
// https://wiki.seeedstudio.com/Grove-TemperatureAndHumidity_Sensor/
// https://docs.particle.io/reference/device-os/libraries/g/Grove_Temperature_And_Humidity_Sensor/
// https://docs.particle.io/getting-started/integrations/webhooks/
// https://wiki.seeedstudio.com/Grove-TemperatureAndHumidity_Sensor/
// https://docs.particle.io/reference/device-os/firmware/

#define DHTPIN D2
DHT dht(DHTPIN);

void setup() {
    dht.begin();
}

void loop() {
    delay(5000);
    
    float temp = dht.getTempCelcius();
    
    if (isnan(temp)) {
        return;
    } else {
        Particle.publish("temp", String(temp));
    }
}