uint8_t s_pin = 12;
uint8_t ldr_pin = 13;
int MIN = 4095;
int MAX = 0;

void setup() {
  Serial.begin(115200);
  ledcSetup(0, 12000, 8);
  ledcAttachPin(s_pin, 0);
  pinMode(ldr_pin, INPUT);
}

void loop() {
  int freq = analogRead(ldr_pin);
  MAX = max(freq, MAX);
  MIN = min(freq, MIN);
  freq = scale(freq);
  ledcWriteTone(0, freq);
  Serial.println(freq);
  delay(10);
}

int scale(int f) {
  f = f - MIN;
  double scalar = 4095 / MAX;
  f = (int) scalar * f;
  return f;
}
