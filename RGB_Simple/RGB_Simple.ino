const uint8_t r_pin = 5;
const uint8_t g_pin = 17;
const uint8_t b_pin = 16;

int R;
int G;
int B;

void setup() {
  Serial.begin(115200);
  PWM_Setup(r_pin, 1);
  PWM_Setup(g_pin, 2);
  PWM_Setup(b_pin, 3);
  R = G = B = 127;
}

void loop() {
  RGB_Constrain();
  RGB_Set();
  delay(10);
  Serial.printf("R: %d | G: %d | B: %d\n", R, G, B);
}

void PWM_Setup(uint8_t pin, uint8_t channel) {
  ledcAttachPin(pin, channel);
  ledcSetup(channel, 12000, 8);
}

void RGB_Set() {
  ledcWrite(1, R);
  ledcWrite(2, G);
  ledcWrite(3, B);
}

void RGB_Constrain() {
  R += random(-1, 2) * random(0, 2);
  G += random(-1, 2) * random(0, 2);
  B += random(-1, 2) * random(0, 2);
  
  if (R < 0) {
    R = 0;
  } else if (R > 255) {
    R = 255;
  }
  
  if (G < 0) {
    G = 0;
  } else if (G > 255) {
    G = 255;
  }
  
  if (B < 0) {
    B = 0;
  } else if (B > 255) {
    B = 255;
  }
}
