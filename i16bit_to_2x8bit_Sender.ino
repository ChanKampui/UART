//16bit to 2_8bit
//24bit to 3_8bit
//32bit to 4_8bit

uint16_t less_16bit = 1023;   // Max of 16 bit unsigned interger : 65535
uint32_t over_16bit = 70000; 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);

  convertData16(1023);
  convertData32(70000);
}

void loop() {
  // put your main code here, to run repeatedly:
}

uint16_t convertData16(uint16_t data) {
  Serial1.write(0X3C);  //StartMarker
  Serial1.write((data >> 8) & 0XFF);
  Serial1.write(data & 0xFF);
  Serial1.write(0x3E);  //EndMarker
  return data;
}


uint32_t convertData32(uint32_t data) {
  Serial1.write(0X3C);
  Serial1.write((data >> 16) & 0xFF);
  Serial1.write((data >> 8) & 0XFF);
  Serial1.write(data & 0xFF);
  Serial1.write(0x3E);
  return data;
}
