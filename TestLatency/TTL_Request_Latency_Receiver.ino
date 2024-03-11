uint32_t StartTime = 0;
uint32_t Latency = 0;
int StopFlag = 0;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(9, INPUT);

  Serial1.write('A');
  StartTime = micros();
}
void loop() {
  if (digitalRead(9) == HIGH && StopFlag == 0) {
    Latency = micros() - StartTime;
    Serial.println(Latency);
    StopFlag = 1;
  }
}
