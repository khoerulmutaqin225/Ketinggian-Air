#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
//BlynkTimer timer;
WidgetLED led1(V2);
WidgetLED led2(V3);
WidgetLED led3(V4);
// Authorization token from the Blynk App. //Masukan Token Blynk
// Your WiFi credentials.                  //Masukan Nama Wifi
// Set password to "" for open networks.   //Password Wifi
//#define BLYNK_TEMPLATE_ID "TMPL5GOC0ADl"
//#define BLYNK_DEVICE_NAME "Pendeteksi Ketinggian Air"
//#define BLYNK_AUTH_TOKEN "fr1iZLenOMmeXUQ27ysf_jmfCl0SkcDV"
char auth[] = "fr1iZLenOMmeXUQ27ysf_jmfCl0SkcDV";
char ssid[] = "Nabilahatha";
char pass[] = "Abil1106";

//data sensor di A0 (analog 0) 
const int sensorPin = A0;
float liquid_level;
int liquid_graph;
//led 1 untuk D1
const int led1 = D1;
//led 2 untuk D2
const int led2 = D2;
//led 3 untuk D3
const int led3 = D3;

const int BatasBawah = 250;
const int BatasAtas = 550;

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(sensorPin, INPUT);
  Blynk.virtualWrite(V0, liquid_level); // This Use Basic Value  pf water container
  Blynk.virtualWrite(V1, liquid_graph); // This wil show the percentage of water in the container in a virtual pin V1
  Blynk.run();
  // initialize the LED pin as an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  //  initialize serial communications:
}

void loop()
{
  // read the value of the potentiometer:
  liquid_level = analogRead(sensorPin);
  liquid_graph = analogRead(sensorPin); // Percentage of water in the container
  Serial.println("liquid_level :");
  Serial.print(liquid_level); // This will print the liquid level in the monitor
  Serial.println("liquid_graph :");
  Serial.print(liquid_graph); // This will print the percentage of liquid in the monitor
  Blynk.virtualWrite(V0, liquid_level);
  Blynk.virtuallWrite(V1, liquid_graph);
  Blynk.run();
  int analogValue = analogRead(sensorPin);
  // if the analog value is high enough, turn on the LED:
  if (analogValue < BatasBawah)
  {
    led1.on();
    digitalWrite(led1, HIGH);
  }
  else
  {
    led1.off();
    digitalWrite(led1, LOW);
  }

  if (analogValue > BatasBawah)
  {
    led2.on();
    digitalWrite(led2, HIGH);
  }
  else
  {
    led2.off();
    digitalWrite(led2, LOW);
  }

  if (analogValue > BatasAtas)
  {
    led3();
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }
  else
  {
    led3();
    digitalWrite(led3, LOW);
  }
  delay(1000); // delay in between reads for stability
}
