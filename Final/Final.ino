#include <WiFi.h>
#include <WebServer.h>
#include <WiFiUdp.h>

const uint8_t r_pin = 16;
const uint8_t g_pin = 17;
const uint8_t b_pin = 5;
const uint8_t l_top_pin = 13;
const uint8_t l_bot_pin = 14;
const uint8_t s_pin = 12;
uint16_t THRESHOLD = 100;

char* ssid = "Yuki_Smoker";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

uint8_t SPEAKER = 1; //Default
uint8_t RGB_LED = 1; //Default

IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

WebServer server(80);

WiFiUDP udp;

void setup() {
  Serial.begin(115200);
  pwm_Setup(r_pin, 1);
  pwm_Setup(g_pin, 2);
  pwm_Setup(b_pin, 3);
  pinMode(l_top_pin, INPUT);
  pinMode(l_bot_pin, INPUT);
  pwm_Setup(s_pin, 4);
  for (int i = 0; i < 300; i++) {
    int current = analogRead(l_bot_pin);
    delay(10);
    if (current < THRESHOLD) {
      THRESHOLD = current;
    }
  }
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  server.begin();
  udp.begin(57222);
}

void loop() {
  int current = analogRead(l_bot_pin);
  //Serial.println(current);
  if (current > 255) {
    current = 255;
  }
  RGB_Set(255, current, current);
  if (current < THRESHOLD) {
    Alarm();
    Serial.println("ALARM");
  } 
  //Serial.println(current);
  checkDead();
  delay(100);
}

void pwm_Setup(uint8_t pin, uint8_t channel) {
  ledcAttachPin(pin, channel);
  ledcSetup(channel, 12000, 8);
}

void RGB_Set(const int r, const int g, const int b) {
  if (RGB_LED == 1) {
    ledcWrite(1, r);
    ledcWrite(2, g);
    ledcWrite(3, b);
  } else {
    ledcWrite(1, 0);
    ledcWrite(2, 0);
    ledcWrite(3, 0);
  }
  delay(100);
}

void Alarm() {
  if (SPEAKER == 1) {
    RGB_Set(255, 0, 0);
    for (int freq = 0; freq < 4096; freq++) {
      ledcWriteTone(4, freq);
      delay(2);
    }
    for (int freq = 4095; freq >= 0; freq--) {
      ledcWriteTone(4, freq);
      delay(2);
    }
  }
}

void checkDead() {
  uint8_t buffer[50] = "";
  memset(buffer, 0, 50);
  udp.parsePacket();
  String tmp;
  if(udp.read(buffer, 50) > 0){
    //Serial.println((char *)buffer);
    tmp = String((char *) buffer);
    Serial.println(tmp);
    if (tmp.startsWith("Stop!")) {
      SPEAKER = 0;
      RGB_LED = 0;
      Serial.println("CMD: STOP");
    } else if (tmp.startsWith("Speaker Off")) {
      SPEAKER = 0;
      Serial.println("CMD: SPEAKER OFF");
    } else if (tmp.startsWith("Lights Off")) {
      RGB_LED = 0;
      Serial.println("CMD: LIGHTS OFF");
    } else if (tmp.startsWith("Start!")) {
      SPEAKER = 1;
      RGB_LED = 1;
      Serial.println("CMD: START");
    } else if (tmp.startsWith("Speaker On")) {
      SPEAKER = 1;
      Serial.println("CMD: SPEAKER ON");
    } else if (tmp.startsWith("Lights On")) {
      RGB_LED = 1;
      Serial.println("CMD: LIGHTS ON");
    } else if (tmp.startsWith("Test")) {
      Serial.println("CMD: ALARM TEST");
      int tmp_hold = SPEAKER;
      SPEAKER = 1;
      Alarm();
      SPEAKER = tmp_hold;
    } else {
      Serial.println("UNKNOWN COMMAND!");
    }
  }
}
