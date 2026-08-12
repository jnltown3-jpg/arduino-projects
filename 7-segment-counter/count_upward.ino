const int SEG_A = 13;
const int DIGIT_4 = 12;
const int SEG_F = 11;
const int DIGIT_3 = 10;
const int DIGIT_2 = 9;
const int SEG_B = 8;
const int SEG_E = 7;
const int SEG_D = 6;
const int SEG_DP = 5;
const int SEG_C = 4;
const int SEG_G = 3;
const int DIGIT_1 = 2;
const int BUTTON_PIN = A0;

int x = 3;

void setSegments(bool a, bool b, bool c, bool d, bool e, bool f, bool g) {
  digitalWrite(SEG_A, a);
  digitalWrite(SEG_B, b);
  digitalWrite(SEG_C, c);
  digitalWrite(SEG_D, d);
  digitalWrite(SEG_E, e);
  digitalWrite(SEG_F, f);
  digitalWrite(SEG_G, g);
  digitalWrite(SEG_DP, LOW);
}

void showNumber(int number) {
  switch (number) {
    case 0: setSegments(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW); break;
    case 1: setSegments(LOW, HIGH, HIGH, LOW, LOW, LOW, LOW); break;
    case 2: setSegments(HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH); break;
    case 3: setSegments(HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH); break;
    case 4: setSegments(LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH); break;
    case 5: setSegments(HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH); break;
    case 6: setSegments(HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH); break;
    case 7: setSegments(HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW); break;
    case 8: setSegments(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH); break;
    case 9: setSegments(HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH); break;
  }
}

void setup() {
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);
  pinMode(SEG_DP, OUTPUT);
  pinMode(DIGIT_1, OUTPUT);
  pinMode(DIGIT_2, OUTPUT);
  pinMode(DIGIT_3, OUTPUT);
  pinMode(DIGIT_4, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  digitalWrite(DIGIT_2, HIGH);
  digitalWrite(DIGIT_3, HIGH);
  digitalWrite(DIGIT_4, HIGH);
  digitalWrite(DIGIT_1, LOW);
  showNumber(x);
  if (digitalRead(BUTTON_PIN) == LOW) {
    delay(30);
    if (digitalRead(BUTTON_PIN) == LOW) {
      x = (x + 1) % 10;
      while (digitalRead(BUTTON_PIN) == LOW) {
        delay(10);
      }
    }
  }
}
