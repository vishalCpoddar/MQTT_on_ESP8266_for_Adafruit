/************************** Configuration ***********************************/
#include "config.h"

#include "DHT.h"

#define DHTPIN 2
/************************ Code Starts Here *******************************/
#define DHTTYPE DHT11
// this int will hold the current count for our sketch
int count = 0;

AdafruitIO_Feed *TEMP = io.feed("TEMP");
AdafruitIO_Feed *HUMID = io.feed("HUMID");
DHT dht(DHTPIN, DHTTYPE);

void setup() {

  // start the serial connection
  Serial.begin(115200);
  dht.begin();
pinMode(16,OUTPUT);
  // wait for serial monitor to open
  while(! Serial);

  Serial.print("Connecting to Adafruit IO");

  // connect to io.adafruit.com
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

}

void loop() {
  io.run();
  //Read Data from DHT-11:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  else
  {
     Serial.print("sending -> ");
     Serial.println(h);
     Serial.println(t);
     HUMID->save(h);
     TEMP->save(t);
     digitalWrite(16,1);
   }
  delay(3000);
}
