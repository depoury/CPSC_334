const uint8_t r_pin = 5;
const uint8_t g_pin = 17;
const uint8_t b_pin = 16;
int count;

void setup() {
  Serial.begin(115200);
  
  ledcAttachPin(r_pin, 1);
  ledcAttachPin(g_pin, 2);
  ledcAttachPin(b_pin, 3);
  ledcSetup(1, 12000, 8);
  ledcSetup(2, 12000, 8);
  ledcSetup(3, 12000, 8);
}

void loop() {
  RGB_Set(255, 0, 0);
  delay(1000);
  RGB_Set(0, 255, 0);
  delay(1000);
  RGB_Set(0, 0, 255);
  delay(1000);
}

void RGB_Set(const int r, const int g, const int b) {
  ledcWrite(1, r);
  ledcWrite(2, g);
  ledcWrite(3, b);
  delay(100);
}
