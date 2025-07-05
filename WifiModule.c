#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <PZEM004Tv30.h>
#include <SoftwareSerial.h>

// Blynk Auth Token and WiFi credentials
char auth[] = "YourAuthToken";
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

// Define Software Serial pins for PZEM
SoftwareSerial pzemSerial(D7, D6); // (TX, RX)
PZEM004Tv30 pzem(pzemSerial);

void setup() {
  Serial.begin(9600);
  pzemSerial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();

  float voltage = pzem.voltage();
  float current = pzem.current();
  float power = pzem.power();
  float frequency = pzem.frequency();

  Blynk.virtualWrite(V0, voltage);
  Blynk.virtualWrite(V1, current);
  Blynk.virtualWrite(V2, power);
  Blynk.virtualWrite(V3, frequency);

  delay(1000); // Update every second
}
