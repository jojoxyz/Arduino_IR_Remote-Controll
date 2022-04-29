#include <IRremote.h>
 int Pin10    =10; //VCC
 int Pin9     = 9; //GND
 int RECV_PIN = 8; 
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver

    pinMode(Pin10, OUTPUT);
    pinMode(Pin9, OUTPUT);
}

void loop() {
    digitalWrite(Pin10, HIGH);
      digitalWrite(Pin9, LOW);
  
  if (irrecv.decode(&results)) {
    if ((results.value & ~0x8000LL) == 0xc800f740cLL) {
      Serial.println("Got an OnOff code");
    }
  //  Serial.println(results.value >> 32, HEX);
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
}
