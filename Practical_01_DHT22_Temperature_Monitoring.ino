#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22
#define LEDPIN 13

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600);
    dht.begin();
    pinMode(LEDPIN, OUTPUT);
    Serial.println("IIoT Temperature Monitoring System");
}

void loop() {
    float temperature = dht.readTemperature();

    if (isnan(temperature)) {
        Serial.println("Sensor reading failed!");
        delay(2000);
        return;
    }

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    if (temperature > 30.0) {
        digitalWrite(LEDPIN, HIGH);
        Serial.println("ALERT! High Temperature Detected");
    } else {
        digitalWrite(LEDPIN, LOW);
        Serial.println("Normal Temperature");
    }

    Serial.println("                  ");
    delay(2000);
}
