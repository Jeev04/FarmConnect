// Smart Irrigation System

#include <DHT.h>
#include <ESP8266WiFi.h>
String apiKey = "X5AQ445IKMBYW31H"
const char* server = "api.thingspeak.com"; 
const char *ssid =  "EAACCESS";     
const char *pass =  "12345678"; 
#define DHTPIN D3

//Send SMS from GSM Module to Mobile

#include <SoftwareSerial.h>
#include "Adafruit_FONA.h"
 
#define FONA_RX            2
#define FONA_TX            3
#define FONA_RST           4
 
#define FONA_RI_INTERRUPT  0

char sendto[21] = "7012345678"; // Enter your Mobile Number here. Exclude country code.
char message[141] = "Pump has been turned on!"; 

String techtrends;
SoftwareSerial fonaSS = SoftwareSerial(FONA_TX, FONA_RX);
 
Adafruit_FONA fona = Adafruit_FONA(FONA_RST);
 
void setup() {  
  Serial.begin(115200);
  Serial.println(F("FONA incoming call example"));
  Serial.println(F("Initializing....(May take 3 seconds)"));
  delay(5000);
  fonaSS.begin(4800); // if you're using software serial
  if (! fona.begin(fonaSS)) {           // can also try fona.begin(Serial1) 
    Serial.println(F("Couldn't find FONA"));
    while (1);
  }
  Serial.println(F("FONA is OK"));
 
 fona.print ("AT+CSMP=17,167,0,0\r");
   fona.sendSMS(sendto, message);
   delay(1000);
}

DHT dht(DHTPIN, DHT11);
const int moisturePin = A0;
const int motorPin = D0;

unsigned long interval = 10000;
unsigned long previousMillis = 0;

pinMode(motorPin, OUTPUT);
digitalWrite(motorPin, LOW); // keep motor off initally
dht.begin();
WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  unsigned long currentMillis = millis();
float h = dht.readHumidity();
float t = dht.readTemperature();
if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
moisturePercentage = ( 100.00 - ( (analogRead(moisturePin) / 1023.00) * 100.00 ) );
  Serial.print("Soil Moisture is  = ");
  Serial.print(moisturePercentage);
  Serial.println("%");
if (moisturePercentage < 50) {
    

 
void loop()
{
  fona.sendSMS(sendto, message);
  delay(10000);
}

    digitalWrite(motorPin, HIGH);
  }
   if (moisturePercentage > 50 && moisturePercentage < 55) {
    /1**/
    
    gitalWrite(motorPin, HIGH);
    void loop()
    {
    fona.sendSMS(sendto, message);
    delay(10000);
    }   
  }
 if (moisturePercentage > 56) {
    digitalWrite(motorPin, LOW);
  }
  
