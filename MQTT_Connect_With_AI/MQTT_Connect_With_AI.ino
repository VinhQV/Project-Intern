#include <WiFi.h>
#include "DHTesp.h"
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>


#define DHTpin 15
DHTesp dht;

// --- Cấu hình WiFi & MQTT 
const char* ssid = "Jizy";
const char* password = "22222222"; 
const char* mqtt_server = "c48f9ba1859f4961a84fa4d0e83b5f20.s1.eu.hivemq.cloud";
const int mqtt_port = 8883;
const char* mqtt_username = "Vinh22";
const char* mqtt_password = "VinhGiaVi222";

WiFiClientSecure espClient;
PubSubClient client(espClient);

// --- Hàm kết nối WiFi 
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  randomSeed(micros());
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

// --- Hàm kết nối lại MQTT 
void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientID =  "ESPClient-";
    clientID += String(random(0xffff), HEX);
    if (client.connect(clientID.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("connected");
      client.subscribe("esp32/command"); 
      Serial.println("Subscribed to topic: esp32/command");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}


void callback(char* topic, byte* payload, unsigned int length) {
  String incommingMessage = "";
  for (int i = 0; i < length; i++) incommingMessage += (char)payload[i];
  
  Serial.println("-------------------------");
  Serial.println("Received command from server!");
  Serial.print("Topic: ");
  Serial.println(topic);
  Serial.print("Message: ");
  Serial.println(incommingMessage);
  Serial.println("-------------------------");
}

// --- Hàm gửi tin nhắn đi
void publishMessage(const char* topic, String payload, boolean retained) {
  if (client.publish(topic, payload.c_str(), retained)) {
    Serial.println("Message published [" + String(topic) + "]: " + payload);
  }
}

// --- Hàm cài đặt ban đầu 
void setup() {
  Serial.begin(115200);
  while (!Serial) delay(1);

  dht.setup(DHTpin, DHTesp::DHT11);
  
  setup_wifi();
  
  espClient.setInsecure();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

// --- Vòng lặp chính 
unsigned long timeUpdata = millis();

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  if (millis() - timeUpdata > 5000) {
    TempAndHumidity data = dht.getTempAndHumidity();
    float h = data.humidity;
    float t = data.temperature;
    
    if (isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    DynamicJsonDocument doc(1024);
    doc["humidity"] = h;
    doc["temperature"] = t;
    char mqtt_message[128];
    serializeJson(doc, mqtt_message);

    publishMessage("esp32/dht11", mqtt_message, false);
    timeUpdata = millis();
  }
}