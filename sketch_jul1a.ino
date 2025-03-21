#include <SoftwareSerial.h>

SoftwareSerial espSerial(3, 1); // RX = GPIO3, TX = GPIO1 (ESP-01 default UART)

void setup() {
    Serial.begin(9600);    // Debug Serial Monitor
    espSerial.begin(9600);   // Match Arduino Mega's baud rate

    Serial.println("ESP-01 Ready to Receive Data...");
}

void loop() {
    if (espSerial.available()) {
        String data = espSerial.readStringUntil('\n'); // Read distance data
        Serial.print("Received Distance: ");
        Serial.println(data); // Print to Serial Monitor
    }
}
