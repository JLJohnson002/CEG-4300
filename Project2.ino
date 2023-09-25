// the setup function runs once when you press reset or power the board
const long fastInterval = 500;
const long slowInterval = 1000;

unsigned long lastToggle = 0;

int highCount = 0;
int tslh = 0;
int lowCount = 0;
int tsll = 0;
int pressCount = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMilis = millis();
  int buttonPress = digitalRead(12);

  if (buttonPress == LOW) {

    tslh = millis();
    if (tslh - millis() == 0 && tsll- millis() == 0) {
      pressCount++;
      Serial.println(pressCount);
    }
    if (currentMilis - lastToggle >= slowInterval) {
      lastToggle = currentMilis;
      if (digitalRead(LED_BUILTIN) == LOW) {
        digitalWrite(LED_BUILTIN, HIGH);
      } else {
        digitalWrite(LED_BUILTIN, LOW);
      }
    }
  } else {
    if (currentMilis - lastToggle >= fastInterval) {

      lastToggle = currentMilis;
      if (digitalRead(LED_BUILTIN) == HIGH) {
        digitalWrite(LED_BUILTIN, LOW);
      } else {
        digitalWrite(LED_BUILTIN, HIGH);
      }
    }
  tsll = millis();
  }
}
