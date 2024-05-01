#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

char password[] = "laksh@05";
char ssid[] = "Redmi Note 11";

const char* host = "script.google.com";
const int httpsPort = 443;

const char* GScriptId = "AKfycbzpbDawNwC7BpepRVTo0wpaGS6pkiVDiP3t1mOsSbjDPte-lhuMb7e0Q3D_pMImMd2fhw";


#define wss "DESKTOP-R4QI4L4 0008"
#define wpp "laksh@05"


void setup() {
  delay(10);

  Serial.println();
  delay(5000);


  Serial.print(" conneting to ");
  Serial.println(wss);

  WiFi.mode(WIFI_STA);
  WiFi.begin(wss, wpp);
  Serial.begin(115200);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    // WiFi.begin(wss, wpp);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

// void loop() {
//   if (Serial.available() > 0) {
//     String receivedData = Serial.readStringUntil('\n');
//     // Process the received data here
//     Serial.println(receivedData);
//     /////////////////////////////////////
    
//   Serial.print("connecting to ");
//   Serial.println(host);
  
//   WiFiClientSecure client;
//   if (!client.connect(host, httpsPort)) {
//     Serial.println("connection failed");
//     return;
//   }

//   String url = "/macros/s/" + String(GScriptId) + "/exec?";
//   url += "value1=111&value2=222";

//   Serial.print("requesting URL: ");
//   Serial.println(url);

//   client.print(String("GET ") + url + " HTTP/1.1\r\n" +
//                "Host: " + host + "\r\n" +
//                "Connection: close\r\n\r\n");
//   delay(500);

//   while (client.connected()) {
//     String line = client.readStringUntil('\r');
//     Serial.print(line);
//   }
  
//   Serial.println();
//   Serial.println("closing connection");
//   }
// }


void loop(){
  Serial.print("connecting to ");
  Serial.println(host);
  
  WiFiClientSecure client;
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }

  String url = "/macros/s/" + String(GScriptId) + "/exec?";
  url += "value1=111&value2=222";

  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  delay(500);

  while (client.connected()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("closing connection");
  delay(5000);
}

