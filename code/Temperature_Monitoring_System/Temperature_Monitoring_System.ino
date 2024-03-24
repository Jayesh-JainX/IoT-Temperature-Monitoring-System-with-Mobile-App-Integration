#define BLYNK_TEMPLATE_ID "TMPL3mrrXgr98"
#define BLYNK_TEMPLATE_NAME "Temperature Monitor"
#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#define temp A0
#define led1Pin D10
#define led2Pin D2
#define led3Pin D3
#define led4Pin D6
#include "BlynkEdgent.h"


void setup() {
  pinMode(temp, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  int Temperature = analogRead(temp);
  float voltage = (float)Temperature * 5.0;
  voltage /= 1024.0;
  Serial.print(voltage); Serial.println(" volts");

  float temperatureC = (voltage - 0.5) * 100;  
  Serial.print(temperatureC); Serial.println(" degrees C");
  
  Blynk.virtualWrite(V0, temperatureC);

  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(temperatureF); Serial.println(" degrees F");
  
  Blynk.virtualWrite(V1, temperatureF); 
  
  // LED control logic...
  if (temperatureC < 25) {
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, LOW);
  } else if (temperatureC >= 25 && temperatureC < 50) {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, LOW);
  } else if (temperatureC >= 50 && temperatureC < 75) {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, LOW);
  } else if (temperatureC >= 75 && temperatureC < 100) {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);
    digitalWrite(led4Pin, LOW);
  } else if (temperatureC >= 100) {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);
    digitalWrite(led4Pin, HIGH);
  } else {
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, LOW);
  }

  delay(2000); 
}
