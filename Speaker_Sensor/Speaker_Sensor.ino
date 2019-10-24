void setup() {
  Serial.begin(115200);
  pinMode(12, INPUT);
}

void loop() {
  Serial.println(analogRead(12));
}
