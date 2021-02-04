/*
 * Solução para utilizar millis()
 * tratando o problema de overflow
 */
int ledState = LOW;
unsigned long prevMillis = 0;
const long interval = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  unsigned long currMillis = millis();
  if (prevMillis > currMillis) { // Verifica se ocorreu overflow
    Serial.println("overflow");
    prevMillis = 0;
    blink(currMillis);
  } else {
    blink(currMillis);
  }
}

void blink(unsigned long currMillis) {
  if (currMillis - prevMillis >= interval) {
    prevMillis = currMillis;
    ledState = !ledState;
    digitalWrite(13, ledState);
  }
}
