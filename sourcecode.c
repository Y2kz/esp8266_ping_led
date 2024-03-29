#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>

//defining pins  
//edit here if you want to add more LEDs
#define LED1 5     //(D5) 
#define LED2 0     //(D3) 

//Wi-Fi name and password
const char* ssid     = "Y2kz";
const char* password = "Y2kz1234";

//whatever domain you like which responds to ICMP
const char* remote_host = "www.google.com";


String avg_time_ms;
int i;

//initial startup
void setup() {
  //serial rate
  Serial.begin(115200);
  
//pinMode edit here if you want to add more
  //you can set multiple LEDs for different ping rate
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  
  delay(1);
  
  Serial.println();
  Serial.println("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print("."); //just wait :(
  }
  Serial.println();
  Serial.print("WiFi connected with ip ");  // Just a pre message
  Serial.println(WiFi.localIP());
  Serial.print("Pinging host ");  // Just a pre message
  Serial.println(remote_host);
}

//loop

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
      Serial.print(" Internet condition Online "); //online serial output :)

    }
//add more conditions here - if you want multiple ping level 
    
  }
  else
  {
    Serial.println("Error :( ");  // :(
    digitalWrite(LED1, LOW);      //clearing the pre state condition
    digitalWrite(LED2, LOW);      //edit if you add more pins
    delay(1);
    digitalWrite(LED1, HIGH);
    Serial.print(" Internet condition Offline "); //offline serial output :(

  }


}
