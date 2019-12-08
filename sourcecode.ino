
/*MIT License

Copyright (c) 2019 Vaishnav PP

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>
//defining pins  edit here if you want to add more
#define LED1 5     //(D5) 
#define LED2 0     //(D3) 
#define LED3 2     //(D4)

const char* ssid     = "Y2kz";
const char* password = "Y2kz1234";

const char* remote_host = "www.google.com";


String avg_time_ms;
int i;

void setup() {
  Serial.begin(115200);
//pinMode edit here if you want to add more
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  
  delay(1);
  
  Serial.println();
  Serial.println("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("WiFi connected with ip ");  // Just a pre message
  Serial.println(WiFi.localIP());
  Serial.print("Pinging host ");  // Just a pre message
  Serial.println(remote_host);
}

void loop() {

  if (Ping.ping(remote_host))
  {
    Ping.ping(remote_host, 10);  //10 time ping to google, You can change value to higher or lower
    i = Ping.averageTime();
    avg_time_ms = Ping.averageTime();
    Serial.println(i);

    if (i > 1 && i < 900)  // change here for offline timeout ping period 
    {
      
      digitalWrite(LED1, LOW);    //clearing the pre state condition
      digitalWrite(LED2, LOW);    //edit if you add more pins
      delay(1);
      digitalWrite(LED2, HIGH);
      Serial.print(" Internet condition Online ");

    }

  }
  else
  {
    Serial.println("Error :( ");
    digitalWrite(LED1, LOW);      //clearing the pre state condition
    digitalWrite(LED2, LOW);      //edit if you add more pins
    delay(1);
    digitalWrite(LED1, HIGH);
    Serial.print(" Internet condition Offline ");

  }


}
