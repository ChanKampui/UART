void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);                                                                       
  Serial1.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial1.available()>0){
    Serial.println(Serial1.read());
  }
}
