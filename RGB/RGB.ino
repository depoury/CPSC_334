const uint8_t r_pin = 5;
const uint8_t g_pin = 17;
const uint8_t b_pin = 16;
const uint8_t l_pin = 33;
const uint8_t p_pin = 25;

int count;

void setup() {
  Serial.begin(115200);
  
  ledcAttachPin(r_pin, 1);
  ledcAttachPin(g_pin, 2);
  ledcAttachPin(b_pin, 3);
  pinMode(l_pin, OUTPUT);
  count = 0;
  digitalWrite(l_pin, LOW);
  //pinMode(p_pin, OUTPUT);
  //digitalWrite(p_pin, HIGH);
  ledcAttachPin(p_pin, 4);
 
  ledcSetup(1, 12000, 8);
  ledcSetup(2, 12000, 8);
  ledcSetup(3, 12000, 8);
  ledcSetup(4, 12000, 8);
}

void loop() {
  if (count == 127) {
    digitalWrite(l_pin, HIGH);
  } else if (count == 255) {
    digitalWrite(l_pin, LOW);
    count = -1;
  }
  count++;
  ledcWrite(4, count);
  if (count % 3 == 0) {
    RGB_Set(255, 0, 0);
  } else if (count % 3 == 1) {
    RGB_Set(0, 255, 0);
  } else {
    RGB_Set(0, 0, 255);
  }
}

void RGB_Set(const int r, const int g, const int b) {
  ledcWrite(1, r);
  ledcWrite(2, g);
  ledcWrite(3, b);
  delay(100);
}
