const byte numBytes = 7;
uint32_t receivedBytes[numBytes];
byte numReceived = 0;

bool newData = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  recvBytesWithStartMarkers();
  showNewData();
}

void recvBytesWithStartMarkers() {
  static bool recvInProgress = false;
  static byte ndx = 0;
  byte startMarker = 0x3C;
  byte endMarker = 0x3E;
  byte rb;

  while (Serial1.available() > 0 && newData == false) {
    rb = Serial1.read();

    //Serial.println(rb);  //For Checking the number read form Serial1

    if (recvInProgress == true) {
      if (rb != endMarker) {
        receivedBytes[ndx] = rb;
        ndx++;
        if (ndx >= numBytes) {
          ndx = numBytes - 1;
        }
      } else {
        receivedBytes[ndx] = '\0';
        recvInProgress = false;
        numReceived = ndx;
        ndx = 0;
        newData = true;
      }
    } else if (rb == startMarker) {
      recvInProgress = true;
    }
  }
}

void showNewData() {
  if (newData == true) {
    // uint32_t result = receivedBytes[0] << 16 | receivedBytes[1] << 8 | receivedBytes[2];
     uint16_t result = receivedBytes[0] << 8 | receivedBytes[1];
    Serial.println(receivedBytes[0] << 16 );
    Serial.println(receivedBytes[1] << 16 & 0xFF);
    Serial.println(result);
  }
  newData = false;
}
