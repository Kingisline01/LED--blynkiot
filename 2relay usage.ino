#define BLYNK_TEMPLATE_ID "TMPL3cajkLTFI"
#define BLYNK_TEMPLATE_NAME "SWITCH"
#define BLYNK_AUTH_TOKEN "1ClHsq8Mw-4r6bZsUJ1neRgAp5wb_9CS"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Kavijio_fastedition";
char pass[] = "length@78";

#define RELAY1_PIN D4 // GPIO4
#define RELAY2_PIN D1 // GPIO5

void setup() {
  Serial.begin(9600);
  
  // Initialize Blynk
  Blynk.begin(auth, ssid, pass);

  // Set relay pins as outputs
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);

  // Set relays to OFF initially
  digitalWrite(RELAY1_PIN, HIGH); // HIGH is OFF for most relay modules
  digitalWrite(RELAY2_PIN, HIGH);
}

void loop() {
  Blynk.run();
}

// Blynk virtual pin V1 for Relay 1
BLYNK_WRITE(V1) {
  int pinValue = param.asInt(); // Get the value from Blynk app
  digitalWrite(RELAY1_PIN, !pinValue); // Toggle relay based on Blynk input
}

// Blynk virtual pin V2 for Relay 2
BLYNK_WRITE(V2) {
  int pinValue = param.asInt();
  digitalWrite(RELAY2_PIN, !pinValue);
}
