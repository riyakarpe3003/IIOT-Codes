const int buttonPin = 4;
const int ledPin = 12;

int buttonState = 0;

void setup() {
    Serial.begin(115200);
    pinMode(buttonPin, INPUT);
    pinMode(ledPin, OUTPUT);
    Serial.println("Hello, ESP32!");
}

void loop() {
    buttonState = digitalRead(buttonPin);

    if (buttonState == HIGH) {
        digitalWrite(ledPin, HIGH);
        Serial.println("LED ON");
    } else {
        digitalWrite(ledPin, LOW);
        Serial.println("LED OFF");
    }

    delay(60);
}
