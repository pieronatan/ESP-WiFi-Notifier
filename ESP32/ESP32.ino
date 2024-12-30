#include <WiFi.h>
#include <HTTPClient.h>
#include <UrlEncode.h>

const int VP_PIN = 34; // Utilize o GPIO correto para o ADC no ESP32

const char* ssid = "";
const char* password = "";
String phoneNumber = "";
String apiKey = "";

void sendMessage(String message){
  String url = "http://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(message);
  WiFiClient client;    
  HTTPClient http;
  http.begin(client, url);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");  
  int httpResponseCode = http.POST("");
  if (httpResponseCode == 200){
    Serial.println("Message sent successfully");
  }
  else{
    Serial.println("Error sending the message");
    Serial.println("HTTP response code: ");
    Serial.println(httpResponseCode);
  }
  http.end();
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  int voltage = analogRead(VP_PIN);

  float voltageValue = (voltage / 4095.0) * 3.3;
  Serial.println(voltageValue);

  if (voltageValue > 2){
    Serial.println(voltageValue);
    sendMessage("Hello from ESP32!");
  }

  delay(1000);
}
