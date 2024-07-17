#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <NewPing.h>
#include <time.h>

#define TRIGGER_PIN D2
#define ECHO_PIN D2
#define PIR_PIN D1
#define MAX_DISTANCE 200

const char* ssid = "Digital Skills Festival"; // Replace with your WiFi SSID
const char* thingSpeakServer = "https://api.thingspeak.com/update"; // ThingSpeak API URL
const char* apiKey = "U27RZFW8Z3YK9X5S"; // Replace with your ThingSpeak Write API Key

const int binId = 1; 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

WiFiClientSecure wifiClientSecure;
HTTPClient http;

unsigned long motionDetectedTime = 0;
bool motionDetected = false;

void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
  connectToWiFi();
  configTime(0, 0, "pool.ntp.org", "time.nist.gov"); 
  wifiClientSecure.setInsecure(); 
}

void loop() {
  if (digitalRead(PIR_PIN) == HIGH && !motionDetected) {
    Serial.println("Motion detected!");
    motionDetected = true;
    motionDetectedTime = millis(); 
  }

  if (motionDetected && millis() - motionDetectedTime >= 30000) { /
    unsigned int uS = sonar.ping();
    float distance = uS / US_ROUNDTRIP_CM;

    if (distance > 0) { 
      if (WiFi.status() == WL_CONNECTED) {
        sendDistanceData(distance);
      } else {
        Serial.println("Error in WiFi connection, attempting to reconnect...");
        connectToWiFi();
      }
    }

    motionDetected = false; 
  }

  delay(1000); 
}

void connectToWiFi() {
  WiFi.begin(ssid);
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
    attempts++;
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to WiFi");
  } else {
    Serial.println("Failed to connect to WiFi");
  }
}

String getFormattedTime() {
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);
  char buffer[20];
  sprintf(buffer, "%04d-%02d-%02d %02d:%02d:%02d", 
          p_tm->tm_year + 1900, 
          p_tm->tm_mon + 1, 
          p_tm->tm_mday, 
          p_tm->tm_hour, 
          p_tm->tm_min, 
          p_tm->tm_sec);
  return String(buffer);
}

void sendDistanceData(float distance) {
  String dateTime = getFormattedTime();
  dateTime.replace(" ", "%20");

  String url = String(thingSpeakServer) + 
               "?api_key=" + apiKey + 
               "&field1=" + String(binId) + 
               "&field2=" + dateTime + 
               "&field3=" + String(distance);

  Serial.println("URL: " + url); 

  http.begin(wifiClientSecure, url);

  int httpResponseCode = http.GET();

  if (httpResponseCode > 0) {
    String response = http.getString();
    Serial.println(httpResponseCode);
    Serial.println(response);
  } else {
    Serial.print("Error on sending GET: ");
    Serial.println(httpResponseCode);
    Serial.println(http.errorToString(httpResponseCode)); 

    // Print response headers
    WiFiClient* stream = http.getStreamPtr();
    while (stream->available()) {
      String line = stream->readStringUntil('\n');
      Serial.println(line);
    }
  }

  http.end();
}
