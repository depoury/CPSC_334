// It is pertinent to note that R and G on the chip are reversed for some unknown reason!

const uint8_t r_pin = 17;
const uint8_t g_pin = 5;
const uint8_t b_pin = 16;

void setup() {
  Serial.begin(115200);
  PWM_Setup(r_pin, 1);
  PWM_Setup(g_pin, 2);
  PWM_Setup(b_pin, 3);
}

void loop() {
  //hues(0);
  //hues(1);
  //hues(2);
}

void PWM_Setup(uint8_t pin, uint8_t channel) {
  ledcAttachPin(pin, channel);
  ledcSetup(channel, 12000, 8);
}

void RGB_Set(const int R, const int G, const int B) {
  ledcWrite(1, R);
  ledcWrite(2, G);
  ledcWrite(3, B);
  Serial.printf("R: %d | G: %d | B: %d\n", R, G, B);
  delay(1);
}

void hues(int set) {
  for (int c1 = 0; c1 < 255; c1 += 5) {
    for (int c2 = 0; c2 < 255; c2 += 5) {
      for (int c3 = 0; c3 < 255; c3 += 5) {
        if (set == 0) {
          RGB_Set(c1, c2, c3); 
        } else if (set == 1) {
          RGB_Set(c2, c3, c1);
        } else if (set == 2) {
          RGB_Set(c3, c1, c2);
        }
      }
      for (int c3 = 255; c3 >= 0; c3 -= 5) {
        if (set == 0) {
          RGB_Set(c1, c2, c3); 
        } else if (set == 1) {
          RGB_Set(c2, c3, c1);
        } else if (set == 2) {
          RGB_Set(c3, c1, c2);
        }
      }
    }
    for (int c2 = 255; c2 >= 0; c2 -= 5) {
      for (int c3 = 0; c3 < 255; c3 += 5) {
        if (set == 0) {
          RGB_Set(c1, c2, c3); 
        } else if (set == 1) {
          RGB_Set(c2, c3, c1);
        } else if (set == 2) {
          RGB_Set(c3, c1, c2);
        }
      }
      for (int c3 = 255; c3 >= 0; c3 -= 5) {
        if (set == 0) {
          RGB_Set(c1, c2, c3); 
        } else if (set == 1) {
          RGB_Set(c2, c3, c1);
        } else if (set == 2) {
          RGB_Set(c3, c1, c2);
        }
      }
    }
  }
  for (int c1 = 255; c1 >= 0; c1 -= 5) {
    for (int c2 = 0; c2 < 255; c2 += 5) {
      for (int c3 = 0; c3 < 255; c3 += 5) {
        if (set == 0) {
          RGB_Set(c1, c2, c3); 
        } else if (set == 1) {
          RGB_Set(c2, c3, c1);
        } else if (set == 2) {
          RGB_Set(c3, c1, c2);
        }
      }
      for (int c3 = 255; c3 >= 0; c3 -= 5) {
        if (set == 0) {
          RGB_Set(c1, c2, c3); 
        } else if (set == 1) {
          RGB_Set(c2, c3, c1);
        } else if (set == 2) {
          RGB_Set(c3, c1, c2);
        }
      }
    }
    for (int c2 = 255; c2 >= 0; c2 -= 5) {
      for (int c3 = 0; c3 < 255; c3 += 5) {
        if (set == 0) {
          RGB_Set(c1, c2, c3); 
        } else if (set == 1) {
          RGB_Set(c2, c3, c1);
        } else if (set == 2) {
          RGB_Set(c3, c1, c2);
        }
      }
      for (int c3 = 255; c3 >= 0; c3 -= 5) {
        if (set == 0) {
          RGB_Set(c1, c2, c3); 
        } else if (set == 1) {
          RGB_Set(c2, c3, c1);
        } else if (set == 2) {
          RGB_Set(c3, c1, c2);
        }
      }
    }
  }
}
