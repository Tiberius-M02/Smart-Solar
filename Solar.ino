#include "arduino_secrets.h" // inclus din ArduinoCloud

#include "thingProperties.h" // inclus din ArduinoCloud, contine headere si variabilele declarate in Cloud
#include <DHT.h> // librarie pt senzorul DHT22

#define AER 33
#define UMD 32

const int aerUscat = 4095; // Valoare pt pamantul complet uscat
const int apaPahar = 499; //Valoare pt pamantul complet umed

DHT Senzor_aer(AER, DHT22);

void setup() {
  Serial.begin(115200);
  Senzor_aer.begin();
  pinMode(UMD, INPUT);

  delay(2000); 


  initProperties(); // initializeaza placa, cod scris in "thingProperties.h"

  ArduinoCloud.begin(ArduinoIoTPreferredConnection); // Cenectare la arduinoCloud
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();

  umiditate = Senzor_aer.readHumidity(); // Citeste umiditatea (0% - 100%) si temperatura (-40 - 80 grade C) a senzorului DHT22
  temp = Senzor_aer.readTemperature();


  long sum = 0;
  float Umiditate_procent;
  
  for(int i = 0; i <= 100; i++){
    sum += analogRead(UMD);
    delay(5);
  }
  sum = sum / 101;

  Umiditate_procent = map(sum, aerUscat, apaPahar, 0, 100); // Transforma rangeul de valori analogice primite de la senzorul HW-080, in valori intre 0 - 100

  humSol = Umiditate_procent;
  
}



