#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter;

float minLux = 0xFFFF; // Initialize minimum light level to a high value
float maxLux = 0;
bool isCalibrated = false;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lightMeter.begin();
  Serial.println(F("BH1750 Test begin")); // Print this only once during setup
}

void calibrateSensor() {
  Serial.println("Calibrating sensor...");

  unsigned long calibrationStartTime = millis(); // Record the start time for calibration
  unsigned long calibrationDuration = 60000; // 1 minute in milliseconds

  // Calibrate the sensor by taking readings over 1 minute
  while (millis() - calibrationStartTime < calibrationDuration) {
    delay(100); // Delay between readings
    float lux = lightMeter.readLightLevel();
    if (lux != 0xFFFF) { // Check if reading is valid
      if (lux < minLux) minLux = lux; // Update minLux if a lower value is found
      if (lux > maxLux) maxLux = lux; // Update maxLux if a higher value is found
    }

    Serial.print("."); // Print dot to indicate progress
  }

  Serial.println("Calibration complete.");
  isCalibrated = true;
}

void loop() {
  if (!isCalibrated) {
    calibrateSensor(); // Calibrate the sensor if not already calibrated
    delay(1000); // Delay for readability
  }

  float lux = lightMeter.readLightLevel();
  float percent = 0;
  String status;

  if (lux != 0xFFFF && maxLux != minLux) {
    percent = ((lux - minLux) / (maxLux - minLux)) * 100.0; // Calculate percentage relative to minimum and maximum levels
  }

  // Determine status based on percent
  if (percent <= 10) {
    status = "Faulty: Light intensity too low";
  } else if (percent > 10 && percent <= 20) {
    status = "Flickering: Unstable light intensity";
  } else {
    status = "Working Fine: Stable light intensity";
  }

  // Print percentage and status
  Serial.print("Percent:");
  Serial.print(percent);
  Serial.print(",Status:");
  Serial.println(status);

  delay(5000);
}
