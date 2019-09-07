#include "WiFi.h"
#include "FirebaseESP32.h"
#include "time.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ArduinoJson.h>
//khai báo hằng số
#define FIREBASE_HOST "smartgarden-4b96b.firebaseio.com"
#define FIREBASE_AUTH "VOkJ3CgDPCkWIxYfj2q9HmKLCDHYj7JaMib3ZZFx"
#define bomHCpin 27
#define bomApin 26
#define bomBpin 25
#define denpin 14
#define lightsensor 12
#define PHSensorPin 32
#define TdsSensorPin 33
#define touch1 13
#define touch2 18
#define touch3 19
#define touch4 21
#define wifiled 22
#define statusled 23

int ttbomHC = 0, ttbomA = 0, ttbomB = 0, ttden = 0;
int gtt;
float temperatureC;
String sendbom, sendbomA, sendbomB, sendden;
int sendtt = 0;
//#define bomOxipin 35
//-----------------tnuoc_time
const int oneWireBus = 5; //pin cảm biến nhiệt độ nước
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 21600;
const int   daylightOffset_sec = 3600;
//-----------------------
//---------------PH
#define Offset 2.00
#define samplingInterval 20
#define printInterval 2000
#define ArrayLenth  40
int pHArray[ArrayLenth];
int pHArrayIndex = 0;
//----------------------
//------------------------TDS
#define VREF 5
#define SCOUNT  30
int analogBuffer[SCOUNT];
int analogBufferTemp[SCOUNT];
int analogBufferIndex = 0, copyIndex = 0;
float averageVoltage = 0, tdsValue = 0, temperature = 27;
//--------------anh sang-------------
int  gtin = 0;
int gt[30], i;
//--------------
static float pHValue, voltage;
unsigned long timedelay,timedelay2= millis();;
//------------------
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);
FirebaseData firebaseData;
void setup() {
  Serial.begin(115200);
  WiFi.begin("B304-Gamer", "LacHong@2019");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  timedelay = millis();
  //-------------
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  pinMode(TdsSensorPin, INPUT);
  pinMode(PHSensorPin, INPUT);
  pinMode(lightsensor, INPUT);
  pinMode(touch4, INPUT);
  pinMode(touch3, INPUT);
  pinMode(touch2, INPUT);
  pinMode(touch1, INPUT);
  pinMode(wifiled, OUTPUT);
  pinMode(statusled, OUTPUT);
  pinMode(bomHCpin, OUTPUT);
  pinMode(bomApin, OUTPUT);
  pinMode(bomBpin, OUTPUT);
  pinMode(denpin, OUTPUT);
  digitalWrite(statusled, HIGH);
  digitalWrite(bomHCpin, HIGH);
  digitalWrite(bomApin, HIGH);
  digitalWrite(bomBpin, HIGH);
  digitalWrite(denpin, HIGH);
  attachInterrupt(touch1, touch1f, HIGH);
  attachInterrupt(touch2, touch2f, HIGH);
  attachInterrupt(touch3, touch3f, HIGH);
  attachInterrupt(touch4, touch4f, HIGH);
}

void loop() {
 if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(wifiled, HIGH);
  } else {
    digitalWrite(wifiled, LOW);
  }
  //-------------------
  //PH
  pHArray[pHArrayIndex++] = analogRead(PHSensorPin);
  if (pHArrayIndex == ArrayLenth)pHArrayIndex = 0;
  //TDS
  analogBuffer[analogBufferIndex] = analogRead(TdsSensorPin);
  analogBufferIndex++;
  if (analogBufferIndex == SCOUNT)
    analogBufferIndex = 0;
  //-------------------
  gt[i] = analogRead(lightsensor);
  if (i > 30) {
    i = 0;
  }
  //
  if ( (unsigned long) (millis() - timedelay) > 3000)
  {
    PH();
    TDSSS();
    Tw();
    anhsang();
    senddata();
    timedelay = millis();
    getdata();
    }
//    senddongco();

  //---------------------------------------------------
  dongco();
}
