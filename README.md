# Smart Street Light Fault Detection System

## Overview

The Smart Street Light Fault Detection System is a technological solution aimed at maintaining well-lit streets by proactively identifying and addressing faults in street light systems. The system utilizes light intensity sensors strategically placed on street lights to continuously monitor the intensity and stability of light output. By analyzing this data, potential malfunctions can be detected before they result in darkened streets, contributing to a safer nighttime environment for pedestrians, cyclists, and drivers.

## Features

- Automated fault detection: Sensors detect deviations in light intensity and flag potential faults.
- Communication network: Establishes a network between sensors and a central monitoring station for real-time data transmission.
- Threshold definition: Allows setting of acceptable light intensity thresholds based on street light type and regulations.
- Data analysis: Central monitoring station compares light intensity data against predefined thresholds.
- Fault detection: Flags potential faults such as out-of-range intensity or flickering lights.
- Alert generation: Generates alerts for maintenance crews if faults are detected, enabling timely repairs.

## System Architecture

The system consists of Arduino Uno microcontrollers, light intensity sensors (BH1750), breadboards, jumper wires, and Wi-Fi modules (ESP8266). Sensors are installed on street lights, collecting light intensity data at regular intervals. This data is transmitted to the central monitoring station for analysis. If deviations are detected, alerts are generated for maintenance crews.

## Safety Considerations

- Secure sensor placement to minimize tampering or vandalism.
- Weatherproofing of sensors and enclosures to protect against environmental factors.
- Adherence to electrical safety standards during installation and operation.
- Structural integrity checks to prevent equipment dislodgement.
- Implementation of traffic safety measures during maintenance activities.

## Getting Started

To set up the Smart Street Light Fault Detection System, follow these steps:

1. Install light intensity sensors on street lights.
2. Establish a communication network between sensors and the central monitoring station (Currenttly Google Sheet).
3. Define acceptable light intensity thresholds based on street light type and regulations.
3. Set-up a proper wifi connection between every NodeMCU and server.
4. Activate sensors for data collection at regular intervals.
5. Transmit collected data to the central monitoring station.
6. Analyze data for potential faults and generate alerts if necessary.

## Src files

All the required files are being uploaded in `/include` section of the repository.

- The `/results/arduino` conatins file to collect data of sensor-1.
- The `/results/Arduino_send_in_STD` contains file to send data of sensor-1 to NodeMCU.
- The `/results/nodemu_receive_in_STD` contains file to receive data from arduino and sensor-2 and upload result to Google Sheet.
- The `/results/nodemcu` contains file to receive data and convert it to readable form.
- The `/results/IOT_to_BHL` contains file to receive data from sensor-2.
- The `/results/to_sheet` contains file to send data to Google sheet.

## Results

The location data of faulted street light is being uploaded to Googe Sheet, the demo is uploaded in `/results` section

The cicuit diagram and required components is in `/assets` section.

## References

For more information on the components and standards used in this project, refer to the following resources:

- **Arduino**: Arduino Uno. [Arduino Website](https://www.arduino.cc/en/Main/ArduinoBoardUno)
- **BH1750**: Adafruit BH1750 Light Sensor. [Adafruit](https://learn.adafruit.com/adafruit-bh1750-light-sensor-breakout)
- **Breadboard**: SparkFun Breadboard - Mini Modular (White). [SparkFun](https://www.sparkfun.com/products/12043)
- **Jumper Wires**: SparkFun Jumper Wires - Connected 6in (M/M, 20 pack). [SparkFun](https://www.sparkfun.com/products/8430)
- **ESP8266**: Espressif ESP8266 Wi-Fi Module. [Espressif](https://www.espressif.com/en/products/socs/esp8266)
- **IEC 60529**: International Electrotechnical Commission (IEC) - Degrees of protection provided by enclosures (IP Code). [IEC](https://www.iec.ch/standards/Catalogue/browseByPublicationDate.htm?c=2022%2F01)
- **OSHA Electrical Safety Standards**: Occupational Safety and Health Administration (OSHA). [OSHA](https://www.osha.gov/standards/electrical)
- **FHWA Temporary Traffic Control Devices**: Federal Highway Administration (FHWA). [FHWA](https://safety.fhwa.dot.gov/ttp/devices/)
- **IEEE 1584**: Institute of Electrical and Electronics Engineers (IEEE) - IEEE Standard for Electrical Safety in the Workplace. [IEEE](https://standards.ieee.org/standard/1584-2018.html)
- **NEMA Standards**: National Electrical Manufacturers Association (NEMA). [NEMA](https://www.nema.org/standards)
- **ANSI Standards**: American National Standards Institute (ANSI). [ANSI](https://www.ansi.org/standards)
- **NFPA 70**: National Fire Protection Association (NFPA) - National Electrical Code. [NFPA](https://www.nfpa.org/codes-and-standards/all-codes-and-standards/list-of-codes-and-standards/detail?code=70)
- **ISO Standards**: International Organization for Standardization (ISO). [ISO](https://www.iso.org/standards.html)
- **USDOT Manual on Uniform Traffic Control Devices (MUTCD)**: United States Department of Transportation (USDOT). [USDOT](https://mutcd.fhwa.dot.gov/)
- **ASCE Standards**: American Society of Civil Engineers (ASCE). [ASCE](https://www.asce.org/standards/)
- **ASSP Standards**: American Society of Safety Professionals (ASSP). [ASSP](https://www.assp.org/standards)
- **IEEE 802.11**: Institute of Electrical and Electronics Engineers (IEEE) - IEEE 802.11 Wireless LAN Standards. [IEEE](https://standards.ieee.org/standard/802_11-2016.html)
- **ITU-T Recommendations**: International Telecommunication Union (ITU). [ITU](https://www.itu.int/rec/T-REC/en)
- **EERE Street Lighting Resources**: Energy Efficiency and Renewable Energy (EERE). [EERE](https://www.energy.gov/eere/ssl/street-lighting-resources)

These references provide detailed information on the components, standards, and regulations relevant to the Smart Street Light Fault Detection System.


## License

This project is licensed under the [MIT License](LICENSE).
