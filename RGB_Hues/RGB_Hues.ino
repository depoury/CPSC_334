// It is pertinent to note that the R and G pins on the chip are inexplicably reversed!

const uint8_t r_pin = 5;
const uint8_t g_pin = 17;
const uint8_t b_pin = 16;

void setup() {
  Serial.begin(115200);
  PWM_Setup(r_pin, 1);
  PWM_Setup(g_pin, 2);
  PWM_Setup(b_pin, 3);
}

void loop() {
  up_down(1, 0, 0);
  up_down(0, 1, 0);
  up_down(0, 0, 1);
  up_down(1, 1, 0);
  up_down(1, 0, 1);
  up_down(0, 1, 1);
  up_down(1, 1, 1);
}

void up_down(int rk, int gk, int bk) {
  for (int i = 0; i < 255; i++) {
    RGB_Set(i * rk, i * gk, i * bk);
  }
  for (int i = 255; i >= 0; i--) {
    RGB_Set(i * rk, i * gk, i * bk);
  }
}

void PWM_Setup(uint8_t pin, uint8_t channel) {
  ledcAttachPin(pin, channel);
  ledcSetup(channel, 12000, 8);
}

void RGB_Set(const int r, const int g, const int b) {
  ledcWrite(1, r);
  ledcWrite(2, g);
  ledcWrite(3, b);
  Serial.printf("R: %d | G: %d | B: %d\n", r, g, b);
  delay(1);
}
