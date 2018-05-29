/************************ Adafruit IO Config *******************************/
#define IO_USERNAME    "Adafruit UserName"
#define IO_KEY         "KEY"

/******************************* WIFI **************************************/

#define WIFI_SSID       "SSID NAME"
#define WIFI_PASS       "PRE SHARED KEY"


#include "AdafruitIO_WiFi.h"
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);