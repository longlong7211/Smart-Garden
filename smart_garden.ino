#include <FirebaseESP32.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>
#include "GravityTDS.h"
#include <EEPROM.h>
#include <WebServer.h>

#define nhietdopin 2
#define TDSpin 13
#define FIREBASE_HOST "smartgarden-2019.firebaseio.com/"
#define FIREBASE_AUTH "rtkJkwchq1OzEaU73E8AwTmYkIl2"

float nhietdo;
unsigned long timesend = 0, timedoc = 0, timepress = 0;
float temperature, chattan = 0;
const char* ssid = "Smart Garden";
const char* password = "";
String id, pw;
IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
WebServer server(80);
FirebaseData firebaseData;
OneWire oneWire(nhietdopin);
DallasTemperature sensors(&oneWire);
GravityTDS gravityTds;

void setup(void)
{
  EEPROM.begin(512);
  Serial.begin(115200);
  pinMode(TDSpin, INPUT);
  pinMode(13, INPUT);
  sensors.begin();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  gravityTds.setAref(5.0);  //reference voltage on ADC,
  gravityTds.setAdcRange(1024);  //1024 for 10bit ADC;4096 for 12bit ADC
  gravityTds.begin();  //initialization
  setup_wifi();
}

void loop(void)
{
  server.handleClient();
  if (digitalRead(13) == HIGH) {
    if (millis() - timepress > 3000) {
      serverstart(); timepress = millis();
    }
  } else timepress = millis();
  // Đọc cảm biến---------------------------
  //đọc cảm biến nhiệt độ

  if (millis() - 1000 > timedoc) {
    sensors.requestTemperatures();
    Serial.print("Nhiet do :");
    Serial.println(sensors.getTempCByIndex(0));
    nhietdo = sensors.getTempCByIndex(0);
    temperature = nhietdo;
    timedoc = millis();
    //đọc cảm biến nồng độ chất tan
    gravityTds.setTemperature(temperature);  // set the temperature and execute temperature compensation
    gravityTds.update();  //sample and calculate
    chattan = gravityTds.getTdsValue();  // then get the value
    Serial.print(chattan, 0);
    Serial.println("ppm");
  }
  //---------------------------------------------------
  //Gửi dữ liệu mỗi 1 giây

  if (millis() - 1000 > timesend) {
    //Gửi nhiệt độ
    if (WiFi.status() == WL_CONNECTED) {
      Firebase.setFloat(firebaseData, "Sensor/nhietdo" , nhietdo);
      Firebase.setFloat(firebaseData, "Sensor/chattan" , chattan);
      timesend = millis();
    }
  }
}
