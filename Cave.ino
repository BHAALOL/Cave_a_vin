#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  //Temp & Humidité calculé
  String dhtTemp = String(dht.readTemperature());
  String dhtHum = String(dht.readHumidity());
  //Temperature requise 13 et 16 deg et temp 60 & 70
  int maxTemp = 14;
  int reqHum = 75;

    while (dhtTemp.toInt() > maxTemp){
      //Allume la led/compresseur
      Serial.println(dhtTemp.toInt());
      Serial.println("Allumage Compresseur");
      digitalWrite(13,HIGH);
      delay (1000);
      digitalWrite(13,LOW);
      }
    while ( dhtHum.toInt() > reqHum){
      //Allume la led/ventilo
      Serial.println(dhtHum.toInt());
      Serial.println("Allumage Ventilo");
      delay(1000);
      digitalWrite(12,HIGH);
      delay (1000);
      digitalWrite(12,LOW);
    }


}  
