#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Replace with your own ThingSpeak Write API Key.
String apiKey = "YOUR_THINGSPEAK_WRITE_API_KEY";

const int potentiometerPin = 33;
const char* server = "http://api.thingspeak.com";

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    Serial.print("Connecting to Wi-Fi");

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }

    Serial.println("\\nConnected to Wi-Fi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}

void loop() {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;

        int potValue = analogRead(potentiometerPin);
        float voltage = (potValue / 4095.0) * 3.3;

        Serial.print("Potentiometer Value: ");
        Serial.println(potValue);
        Serial.print("Voltage: ");
        Serial.println(voltage);

        String url = String(server);
        url += "/update?api_key=" + apiKey;
        url += "&field1=" + String(potValue);
        url += "&field2=" + String(voltage, 2);

        http.begin(url);
        int httpResponseCode = http.GET();

        Serial.print("HTTP Response Code: ");
        Serial.println(httpResponseCode);

        if (httpResponseCode > 0) {
            Serial.println("Response: " + http.getString());
        }

        http.end();
    } else {
        Serial.println("Wi-Fi Disconnected");
    }

    delay(20000);
}
