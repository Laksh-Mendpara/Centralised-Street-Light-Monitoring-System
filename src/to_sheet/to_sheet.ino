#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
String readString;
const char* ssid = "DESKTOP-R4QI4L4 0008";
const char* password = "laksh@05";
const char* host = "script.google.com";
const int httpsPort = 443;
WiFiClientSecure client;
const char* fingerprint = "46 B2 C3 44 9C 59 09 8B 01 B6 F8 BD 4C FB 00 74 91 2F EF F6";
String GAS_ID = "AKfycbzpbDawNwC7BpepRVTo0wpaGS6pkiVDiP3t1mOsSbjDPte-lhuMb7e0Q3D_pMImMd2fhw";  // Replace by your GAS service id

void setup()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }       
    sendData(113,125);  // Send test data
}
void loop()
{
   int a,b;
   a=1;
   b=1;
   sendData(a,b);
}
void sendData(int x, int y)
{
 client.setInsecure();
 Serial.print("connecting to ");
 Serial.println(host);
 if (!client.connect(host, httpsPort)) {
   Serial.println("connection failed");
   return;
 }          ///// https://script.google.com/macros/s/AKfycbzpbDawNwC7BpepRVTo0wpaGS6pkiVDiP3t1mOsSbjDPte-lhuMb7e0Q3D_pMImMd2fhw/exec
 String string_x     =  String(x, DEC);
 String string_y     =  String(y, DEC);
 Serial.print(string_x);
 Serial.println(string_y);
 String url = "/macros/s/" + GAS_ID + "/exec?value1=" + string_x + "&value2=" + string_y;
 Serial.print("requesting URL: ");
 Serial.println(url);
 client.print(String("GET ") + url + " HTTP/1.1\r\n" +
        "Host: " + host + "\r\n" +
        "User-Agent: BuildFailureDetectorESP8266\r\n" +
        "Connection: close\r\n\r\n");
 Serial.println("request sent");
 while (client.connected()) {
 String line = client.readStringUntil('\n');
 if (line == "\r") {
   Serial.println("headers received");
   break;
 }
 }
 String line = client.readStringUntil('\n');
 if (line.startsWith("{\"state\":\"success\"")) {
 Serial.println("esp8266/Arduino CI successfull!");
 } else {
 Serial.println("esp8266/Arduino CI has failed");
 }
 Serial.println("reply was:");
 Serial.println("==========");
 Serial.println(line);
 Serial.println("==========");
 Serial.println("closing connection");
}