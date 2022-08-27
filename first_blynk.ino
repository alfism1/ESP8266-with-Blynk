/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "XXXXXXX"
#define BLYNK_DEVICE_NAME "XXXXXXX"
#define BLYNK_AUTH_TOKEN "XXXXXXX"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "XXXXXXX";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "XXXXXXX";
char pass[] = "XXXXXXX";

BlynkTimer timer;

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  Serial.println("V0");
  Serial.println(value);

  if (value == 0)
  {
    digitalWrite(5, HIGH);
  }
  else
  {
    digitalWrite(5, LOW);
  }
  // Update state
  Blynk.virtualWrite(V1, value);
}

// This function is called every time the Virtual Pin 3 state changes
BLYNK_WRITE(V3)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();
  Serial.println("V3");
  Serial.println(value);

  if (value == 0)
  {
    digitalWrite(2, HIGH);
  }
  else
  {
    digitalWrite(2, LOW);
  }
  // Update state
  Blynk.virtualWrite(V4, value);
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  //  // Change Web Link Button message to "Congratulations!"
  //  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  //  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  //  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
}

void setup()
{
  pinMode(2, OUTPUT); // Initialise digital pin 2 as an output pin
  pinMode(5, OUTPUT); // Initialise digital pin 2 as an output pin
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  // Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  // Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
