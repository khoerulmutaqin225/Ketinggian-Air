#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


char auth[] = "Isikan kode auth yang dikirim blynk ke E-mail anda"; 
char ssid[] = "Nama Wifi Anda";
char pass[] = "Password Anda"; // Jika tidak menggunakan password kosongkan ""

void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
