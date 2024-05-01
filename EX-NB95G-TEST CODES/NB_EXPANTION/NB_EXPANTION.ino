#define RX0 25
#define TX0 0

void setup() {
// initialize both serial ports:
Serial.begin(9600);
Serial2.begin(9600, SERIAL_8N1, RX0, TX0);
}

void loop() 
  if (Serial2.available()) {
    int inByte = Serial2.read();
    Serial.write(inByte);
  }
  // read from port 0, send to port 1:
  if (Serial.available()) {
    int inByte = Serial.read();
    Serial2.write(inByte);
  }
}
