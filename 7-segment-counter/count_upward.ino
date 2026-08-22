const int SEG_A = 13;
const int SEG_F = 11;
const int SEG_B = 8;
const int SEG_E = 7;
const int SEG_D = 6;
const int SEG_C = 4;
const int SEG_G = 3;

const int D1 = 5;
const int D2 = 9;

const int UP_BUTTON = A0;
const int DOWN_BUTTON = A1;

int x = 0;

void setup() {
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(UP_BUTTON, INPUT_PULLUP);
  pinMode(DOWN_BUTTON, INPUT_PULLUP);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
}

void showNumber(int number) {
  if (number == 0) { digitalWrite(SEG_A, HIGH); digitalWrite(SEG_F, HIGH); digitalWrite(SEG_B, HIGH); digitalWrite(SEG_E, HIGH); digitalWrite(SEG_D, HIGH); digitalWrite(SEG_C, HIGH); digitalWrite(SEG_G, LOW); }
  if (number == 1) { digitalWrite(SEG_A, LOW); digitalWrite(SEG_F, LOW); digitalWrite(SEG_B, HIGH); digitalWrite(SEG_E, LOW); digitalWrite(SEG_D, LOW); digitalWrite(SEG_C, HIGH); digitalWrite(SEG_G, LOW); }
  if (number == 2) { digitalWrite(SEG_A, HIGH); digitalWrite(SEG_F, LOW); digitalWrite(SEG_B, HIGH); digitalWrite(SEG_E, HIGH); digitalWrite(SEG_D, HIGH); digitalWrite(SEG_C, LOW); digitalWrite(SEG_G, HIGH); }
  if (number == 3) { digitalWrite(SEG_A, HIGH); digitalWrite(SEG_F, LOW); digitalWrite(SEG_B, HIGH); digitalWrite(SEG_E, LOW); digitalWrite(SEG_D, HIGH); digitalWrite(SEG_C, HIGH); digitalWrite(SEG_G, HIGH); }
  if (number == 4) { digitalWrite(SEG_A, LOW); digitalWrite(SEG_F, HIGH); digitalWrite(SEG_B, HIGH); digitalWrite(SEG_E, LOW); digitalWrite(SEG_D, LOW); digitalWrite(SEG_C, HIGH); digitalWrite(SEG_G, HIGH); }
  if (number == 5) { digitalWrite(SEG_A, HIGH); digitalWrite(SEG_F, HIGH); digitalWrite(SEG_B, LOW); digitalWrite(SEG_E, LOW); digitalWrite(SEG_D, HIGH); digitalWrite(SEG_C, HIGH); digitalWrite(SEG_G, HIGH); }
  if (number == 6) { digitalWrite(SEG_A, HIGH); digitalWrite(SEG_F, HIGH); digitalWrite(SEG_B, LOW); digitalWrite(SEG_E, HIGH); digitalWrite(SEG_D, HIGH); digitalWrite(SEG_C, HIGH); digitalWrite(SEG_G, HIGH); }
  if (number == 7) { digitalWrite(SEG_A, HIGH); digitalWrite(SEG_F, LOW); digitalWrite(SEG_B, HIGH); digitalWrite(SEG_E, LOW); digitalWrite(SEG_D, LOW); digitalWrite(SEG_C, HIGH); digitalWrite(SEG_G, LOW); }
  if (number == 8) { digitalWrite(SEG_A, HIGH); digitalWrite(SEG_F, HIGH); digitalWrite(SEG_B, HIGH); digitalWrite(SEG_E, HIGH); digitalWrite(SEG_D, HIGH); digitalWrite(SEG_C, HIGH); digitalWrite(SEG_G, HIGH); }
  if (number == 9) { digitalWrite(SEG_A, HIGH); digitalWrite(SEG_F, HIGH); digitalWrite(SEG_B, HIGH); digitalWrite(SEG_E, LOW); digitalWrite(SEG_D, HIGH); digitalWrite(SEG_C, HIGH); digitalWrite(SEG_G, HIGH); }
}

void turnBothDigitsOff() {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
}

void showDigit(int digitPin, int number) {
  turnBothDigitsOff();
  delayMicroseconds(100);
  showNumber(number);
  digitalWrite(digitPin, LOW);
  delay(3);
  digitalWrite(digitPin, HIGH);
}

void showTwoDigitNumber(int number) {
  int ones = number % 10;
  int tens = number / 10;
  showDigit(D1, ones);
  showDigit(D2, tens);
}

void displayNumberFor(int number, int duration) {
  unsigned long startTime = millis();
  while (millis() - startTime < duration) {
    showTwoDigitNumber(number);
  }
}

void waitForRelease(int buttonPin) {
  while (digitalRead(buttonPin) == LOW) {
    showTwoDigitNumber(x);
  }
  delay(30);
}

void loop() {
  showTwoDigitNumber(x);

  if (digitalRead(UP_BUTTON) == LOW) {
    delay(30);
    if (digitalRead(UP_BUTTON) == LOW) {
      x += 1;
      if (x > 99) {
        x = 0;
      }
      waitForRelease(UP_BUTTON);
    }
  }

  else if (digitalRead(DOWN_BUTTON) == LOW) {
    delay(30);
    if (digitalRead(DOWN_BUTTON) == LOW) {
      waitForRelease(DOWN_BUTTON);
      while (x > 0) {
        displayNumberFor(x, 500);
        x -= 1;
      }
      displayNumberFor(0, 500);
    }
  }
}
