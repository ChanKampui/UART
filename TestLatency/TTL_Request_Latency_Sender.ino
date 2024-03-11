void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(9, OUTPUT);

}

void loop() {
  if (Serial1.available() > 0) {
    if (Serial1.read() == 65) {
      digitalWrite(9, HIGH);
      delay(10);
      digitalWrite(9, LOW);
    }
  }
}
