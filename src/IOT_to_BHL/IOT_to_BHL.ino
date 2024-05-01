// #include <Wire.h>
// #include <BH1750.h>
// #include <ESP8266WiFi.h>
// #include <WiFiClientSecure.h>

// BH1750 lightMeter;


// const char* ssid = "DESKTOP-R4QI4L4 0008";
// const char* password = "laksh@05";

// const char* fingerprint = "46 B2 C3 44 9C 59 09 8B 01 B6 F8 BD 4C FB 00 74 91 2F EF F6";
// String GAS_ID = "AKfycbzpbDawNwC7BpepRVTo0wpaGS6pkiVDiP3t1mOsSbjDPte-lhuMb7e0Q3D_pMImMd2fhw";  // Replace by your GAS service id

// const char* host = "script.google.com";
// const int httpsPort = 443;


// WiFiClientSecure client;

// float minLux = 0xFFFF;
// float maxLux = 0;
// bool isCalibrated = false;

// void setup() {
//   Serial.begin(9600);
//   Wire.begin();
//   lightMeter.begin();
//   Serial.println(F("BH1750 Test begin"));

//   // Connect to Wi-Fi
//   Serial.begin(9600);
//   delay(100);

//   Serial.println();
//   Serial.println("Connecting to WiFi");

//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, password);

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   Serial.println("");
//   Serial.println("WiFi connected");

//   sendDataSen1(23, 23);
//   sendDataSen2(25, 25);
// }

// void calibrateSensor() {
//   Serial.println("Calibrating sensor...");

//   unsigned long calibrationStartTime = millis();
//   unsigned long calibrationDuration = 60000;

//   while (millis() - calibrationStartTime < calibrationDuration) {
//     delay(100);
//     float lux = lightMeter.readLightLevel();
//     if (lux != 0xFFFF) {
//       if (lux < minLux) minLux = lux;
//       if (lux > maxLux) maxLux = lux;
//     }
//   }

//   Serial.println("Calibration complete.");
//   isCalibrated = true;
// }

// void sendDataSen1(float x, float y)
// {
//  client.setInsecure();
//  Serial.print("connecting to ");
//  Serial.println(host);
//  if (!client.connect(host, httpsPort)) {
//    Serial.println("connection failed");
//    return;
//  }

//  String string_x     =  String(x, 2);
//  String string_y     =  String(y, 2);
// //  String string_z;
// //  if (z==1){
// //   string_z = "Working Fine: Stable light intensity";
// //  } else if (z==0){
// //   string_z = "Flickering: Unstable light intensity";
// //  } else{
// //   string_z = "Faulty: Light intensity too low";
// //  }

//  String url = "/macros/s/" + GAS_ID + "/exec?value1=Sensor-1&value2=" + string_x + "&value3=" + string_y;

// //  Serial.print("requesting URL: ");
//   //  String url = "https://" + String(host) + "/macros/s/" + GAS_ID + "/exec?value1=" + string_x + "&value2=" + string_y + "&value3=" + string_z;

//  Serial.print("requesting URL: ");
//  Serial.println(url);
//  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
//         "Host: " + host + "\r\n" +
//         "User-Agent: BuildFailureDetectorESP8266\r\n" +
//         "Connection: close\r\n\r\n");
//  Serial.println("request sent");
//  while (client.connected()) {
//    String line = client.readStringUntil('\n');
//    if (line == "\r") {
//      Serial.println("headers received");
//      break;
//    }
//  }
//  String line = client.readStringUntil('\n');
//  if (line.startsWith("{\"state\":\"success\"")) {
//    Serial.println("esp8266/Arduino CI successful!");
//  } else {
//    Serial.println("esp8266/Arduino CI has failed");
//  }
//  Serial.println("reply was:");
//  Serial.println("==========");
//  Serial.println(line);
//  Serial.println("==========");
//  Serial.println("closing connection");
// }



// void sendDataSen2(float x, float y)
// {
//  client.setInsecure();
//  Serial.print("connecting to ");
//  Serial.println(host);
//  if (!client.connect(host, httpsPort)) {
//    Serial.println("connection failed");
//    return;
//  }

//  String string_x     =  String(x, 2);
//  String string_y     =  String(y, 2);
// //  String string_z;
// //  if (z==1){
// //   string_z = "Working Fine: Stable light intensity";
// //  } else if (z==0){
// //   string_z = "Flickering: Unstable light intensity";
// //  } else{
// //   string_z = "Faulty: Light intensity too low";
// //  }

//  String url = "/macros/s/" + GAS_ID + "/exec?value1=Sensor-2&value2=" + string_x + "&value3=" + string_y;

// //  Serial.print("requesting URL: ");
//   //  String url = "https://" + String(host) + "/macros/s/" + GAS_ID + "/exec?value1=" + string_x + "&value2=" + string_y + "&value3=" + string_z;

//  Serial.print("requesting URL: ");
//  Serial.println(url);
//  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
//         "Host: " + host + "\r\n" +
//         "User-Agent: BuildFailureDetectorESP8266\r\n" +
//         "Connection: close\r\n\r\n");
//  Serial.println("request sent");
//  while (client.connected()) {
//    String line = client.readStringUntil('\n');
//    if (line == "\r") {
//      Serial.println("headers received");
//      break;
//    }
//  }
//  String line = client.readStringUntil('\n');
//  if (line.startsWith("{\"state\":\"success\"")) {
//    Serial.println("esp8266/Arduino CI successful!");
//  } else {
//    Serial.println("esp8266/Arduino CI has failed");
//  }
//  Serial.println("reply was:");
//  Serial.println("==========");
//  Serial.println(line);
//  Serial.println("==========");
//  Serial.println("closing connection");
// }



// void loop() {
//   if (!isCalibrated) {
//     calibrateSensor();
//     delay(1000);
//   }

//   float lux = lightMeter.readLightLevel();
//   float percent = 0;

//   if (lux != 0xFFFF && maxLux != minLux) {
//     percent = ((lux - minLux) / (maxLux - minLux)) * 100.0;
//   }

//   Serial.print("Light Level: ");
//   Serial.print(lux);
//   Serial.println(" lx");

//   Serial.print("Intensity (%): ");
//   Serial.print(percent);
//   Serial.println();

//   if (Serial.available() > 0) {
//     String receivedData = Serial.readStringUntil('\n');
    
//     // Extract lux, percentage, and status from received data
//     int firstSemicolonIndex = receivedData.indexOf(';');
//     int secondSemicolonIndex = receivedData.indexOf(';', firstSemicolonIndex + 1);
//     if (firstSemicolonIndex != -1 && secondSemicolonIndex != -1) {
//       float receivedLux = receivedData.substring(0, firstSemicolonIndex).toFloat();
//       float receivedPercent = receivedData.substring(firstSemicolonIndex + 1, secondSemicolonIndex).toFloat();
//       String receivedStatus = receivedData.substring(secondSemicolonIndex + 1);
//       // int stat = (int) receivedData[secondSemicolonIndex+1];
      
//       // Print received data
//       Serial.print("Received lux: ");
//       Serial.println(receivedLux, 2); // Print lux with two decimal points
//       Serial.print("Received percentage: ");
//       Serial.println(receivedPercent, 2); // Print percentage with two decimal points
//       Serial.print("Received status: ");
//       Serial.println(receivedStatus);

//       // receivedLux = (float) receivedLux/1000;
//       // receivedPercent = (float) receivedPercent/100;

  
//       sendDataSen1(receivedLux, receivedPercent);
//       sendDataSen2(lux, percent);
//     }
//   }

//   delay(5000);
// }


#include <Wire.h>
#include <BH1750.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

BH1750 lightMeter;


const char* ssid = "DESKTOP-R4QI4L4 0008";
const char* password = "laksh@05";

const char* fingerprint = "46 B2 C3 44 9C 59 09 8B 01 B6 F8 BD 4C FB 00 74 91 2F EF F6";
String GAS_ID = "AKfycbzpbDawNwC7BpepRVTo0wpaGS6pkiVDiP3t1mOsSbjDPte-lhuMb7e0Q3D_pMImMd2fhw";  // Replace by your GAS service id

const char* host = "script.google.com";
const int httpsPort = 443;

WiFiClientSecure client;

float minLux = 0xFFFF;
float maxLux = 0;
bool isCalibrated = false;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lightMeter.begin();
  Serial.println(F("BH1750 Test begin"));

  // Connect to Wi-Fi
  Serial.println();
  Serial.println("Connecting to WiFi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");

  // Perform calibration
  calibrateSensor();
  sendDataToGoogleSheets1(11,11);
  sendDataToGoogleSheets2(12,12);

}

void calibrateSensor() {
  Serial.println("Calibrating sensor...");

  unsigned long calibrationStartTime = millis();
  unsigned long calibrationDuration = 60000;

  while (millis() - calibrationStartTime < calibrationDuration) {
    delay(100);
    float lux = lightMeter.readLightLevel();
    if (lux != 0xFFFF) {
      Serial.print(".");
      if (lux < minLux) minLux = lux;
      if (lux > maxLux) maxLux = lux;
    }
  }

  Serial.println("Calibration complete.");
  isCalibrated = true;
}

void sendDataToGoogleSheets1(float lux, float percent) {
  client.setInsecure();
 Serial.print("connecting to ");
 Serial.println(host);
 if (!client.connect(host, httpsPort)) {
   Serial.println("connection failed");
   return;
 }
//  if (client.verify(fingerprint, host)) {
//  Serial.println("certificate matches");
//  } else {
//  Serial.println("certificate doesn't match");
//  }
 String string_x     =  String(lux);
 String string_y     =  String(percent);
 String url = "/macros/s/" + GAS_ID + "/exec?value1=S1&value2=" + string_x + "&value3=" + string_y;
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

void sendDataToGoogleSheets2(float lux, float percent) {
  client.setInsecure();
 Serial.print("connecting to ");
 Serial.println(host);
 if (!client.connect(host, httpsPort)) {
   Serial.println("connection failed");
   return;
 }
//  if (client.verify(fingerprint, host)) {
//  Serial.println("certificate matches");
//  } else {
//  Serial.println("certificate doesn't match");
//  }
 String string_x     =  String(lux);
 String string_y     =  String(percent);
 String url = "/macros/s/" + GAS_ID + "/exec?value1=S2&value2=" + string_x + "&value3=" + string_y;
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


void loop() {
  if (!isCalibrated) {
    calibrateSensor();
    delay(1000);
  }

  float lux = lightMeter.readLightLevel();
  float percent = 0;

  if (lux != 0xFFFF && maxLux != minLux) {
    percent = ((lux - minLux) / (maxLux - minLux)) * 100.0;
  }

  Serial.print("Light Level: ");
  Serial.print(lux);
  Serial.println(" lx");

  Serial.print("Intensity (%): ");
  Serial.print(percent);
  Serial.println();

  if (Serial.available() > 0) {
    String receivedData = Serial.readStringUntil('\n');
    
    // Extract lux, percentage, and status from received data
    int firstSemicolonIndex = receivedData.indexOf(';');
    int secondSemicolonIndex = receivedData.indexOf(';', firstSemicolonIndex + 1);
    if (firstSemicolonIndex != -1 && secondSemicolonIndex != -1) {
      float receivedLux = receivedData.substring(0, firstSemicolonIndex).toFloat();
      float receivedPercent = receivedData.substring(firstSemicolonIndex + 1, secondSemicolonIndex).toFloat();
      String receivedStatus = receivedData.substring(secondSemicolonIndex + 1);
      
      // Print received data
      Serial.print("Received lux: ");
      Serial.println(receivedLux, 2); // Print lux with two decimal points
      Serial.print("Received percentage: ");
      Serial.println(receivedPercent, 2); // Print percentage with two decimal points
      Serial.print("Received status: ");
      Serial.println(receivedStatus);

      // Send received data to Google Sheets
      
      sendDataToGoogleSheets1(lux, percent);
      sendDataToGoogleSheets2(receivedLux, receivedPercent);
    }
  }

  delay(5000);
}
