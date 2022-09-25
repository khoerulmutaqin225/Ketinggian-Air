#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
WidgetLED led1(V2);
WidgetLED led2(V3);
WidgetLED led3(V4);
char auth[] = "vLX_XKrdLFbWviFFT5d5cpKOr4BG1iKo";
char ssid[] = "Nabilahatha";
char pass[] = "Abil1106";
const int sensorPin = A0;
int liquid_level;
int liquid_levelk;
const int LedHijau = D1;
const int LedKuning = D2;
const int LedMerah = D3;
const int BatasBawah = 250;
const int BatasAtas = 550;

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(LedMerah, OUTPUT);
  pinMode(LedHijau, OUTPUT);
  pinMode(LedKuning, OUTPUT);
  pinMode(sensorPin, INPUT);
  Blynk.virtualWrite(V0, liquid_level);
  Blynk.run();
  pinMode(LedMerah, OUTPUT);
  pinMode(LedKuning, OUTPUT);
  pinMode(LedMerah, OUTPUT);
}

void loop()
{
  liquid_levelk = analogRead(sensorPin);
  liquid_level = (liquid_levelk*4)/1024;
  Serial.println("liquid_level :"); 
  Serial.print(liquid_level); 
  Blynk.virtualWrite(V0, liquid_level);
  Blynk.run();
  int analogValue = analogRead(sensorPin);
  if (analogValue < BatasBawah)
  {
    led1.on();
    digitalWrite(LedHijau, HIGH);
  }
  else
  {
    led1.off();
    digitalWrite(LedHijau, LOW);
  }

  if (analogValue > BatasBawah)
  {
    led1.off();
    led2.on();
    digitalWrite(LedKuning, HIGH);
  }
  else
  {
    led2.off();
    digitalWrite(LedKuning, LOW);
  }

  if (analogValue > BatasAtas)
  {
    led2.off();
    led3.on();
    digitalWrite(LedKuning, LOW);
    digitalWrite(LedMerah, HIGH);
  }
  else
  {
    led3.off();
    digitalWrite(LedMerah, LOW);
  }
  delay(1000);
}
