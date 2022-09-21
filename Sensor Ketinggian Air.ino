#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Authorization token from the Blynk App.
char auth[] = "tt1tcqOkNBXMsMtMlzvRDNGpuZutSImA";

// Your WiFi credentials.
// Set password to "" for open networks.

char ssid[] = "Nabilahatha";
char pass[] = "Abil1106";


const int sensorPin= A0;
float liquid_level;
int liquid_graph;
const int Led1 = D1;
const int Led2 = D2;
const int Led3 = D3;

const int BatasBawah = 800;
const int BatasTengah = 900;
const int BatasAtas = 960;

void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
pinMode(Led1, OUTPUT);
pinMode(Led2, OUTPUT) ;
pinMode(Led3, OUTPUT) ;
pinMode(sensorPin, INPUT);
Blynk.virtualWrite(V0, liquid_level);
Blynk.virtualWrite(V1, liquid_graph);//This wil show the percentage of water in the container in a virtual pin V1
Blynk.run();
// initialize the LED pin as an output:
pinMode(Led1, OUTPUT);
pinMode(Led2, OUTPUT) ;
pinMode(Led3, OUTPUT) ;
// initialize serial communications:       
}

void loop()
{
// read the value of the potentiometer:
liquid_level = analogRead(sensorPin);
liquid_graph =analogRead(sensorPin);//Percentage of water in the container 
Serial.println(liquid_level);//This will print the liquid level in the monitor 
Serial.println(liquid_graph);//This will print the percentage of liquid in the monitor
Blynk.virtualWrite(V0, liquid_level);
Blynk.virtualWrite(V1, liquid_graph);
Blynk.run();
int analogValue = analogRead(sensorPin);
// if the analog value is high enough, turn on the LED:
if (analogValue > BatasBawah)
{
digitalWrite(Led1, HIGH);
digitalWrite(Led2, LOW);
digitalWrite(Led3, LOW);
}
else if (analogValue > BatasTengah)
{
digitalWrite(Led1, LOW);
digitalWrite(Led2, HIGH);
digitalWrite(Led3, LOW);
}
else if (analogValue > BatasAtas)
{
digitalWrite(Led1, LOW);
digitalWrite(Led2, LOW);
digitalWrite(Led3, HIGH);
}
// print the analog value:
Serial.println(analogValue);
delay(100);       
// rentang waktu pengiriman data
}
