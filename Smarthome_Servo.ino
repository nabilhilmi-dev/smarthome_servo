
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h> // file untuk model wifi
#include <BlynkSimpleEsp8266.h> // file untuk blynk
#include <Servo.h>


char auth[] = "ION_Ni0_NhfCJo1mr5n5FC9by9YwJQPa";
char ssid[] = "TytydMeongs";
char pass[] = "siniguabisikin";

Servo gerak_servo;

BLYNK_WRITE(V1)
{
  gerak_servo.write (param.asInt());
  // Fungsi Blynk untuk mengatur nilai servo dengan pin virtual V1 yang ada di pada aplikasi blynk
}

void setup()
{
  
  // Debug Console
  Serial.begin(9600);// memulai serial monitor dengan baudrate 9600

  Blynk.begin(auth, ssid, pass); // untuk menjalakan blynk sesuai token, wifi, dan passwordnya

  gerak_servo.attach(9); //setting pin gpio 2 ke servo, d4 = 2
}

void loop()
{
  Blynk.run();// memulai bylnk   
}
