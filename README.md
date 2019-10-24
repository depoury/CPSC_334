# CPSC_334
## Project 3 - Wireless Smoke Detector
I started with the idea of building a smoke detector as my DIY sensor.
To this end, I put an LED next to an LDR in a dark space and took a measurement from the LDR to establish a baseline.

When smoke enters the chamber, it will reduce the amount of light that reaches the LDR, thus sensing smoke.

---
Along with the sensor, a smoke detector needs a warning system. To this end, on the opposite side of the board I attached a speaker, power LED and RGB LED as well as another LDR. The speaker emits an alarm sound when the sensor is triggered. The RGB changes colour to reflect how close to the threshold the sensor is. The power LED is to signal when the battery needs charging. Finally the LDR is for detecting bright lights outside of the case in the event that the threshold needs resetting.

---
With a working smoke alarm system, we now progress to wireless access. Here I used the esp32 as its own WiFi hotspot to allow a user to connect without having the move the device. I wrote a python script with several inbuilt commands that allow for, toggling the lights and alarm as well as testing the alarm.

---
The full python code can be found in UDP_Send.py, the full esp32 code can be found in Final.ino
Details on the circuitry can be found at:
https://201903cpsc33401.canvaspress.yale.edu/2019/10/24/smoke-detector/
