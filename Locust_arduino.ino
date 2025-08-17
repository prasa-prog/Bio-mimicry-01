
#include <IRremote.h>

#define RECV_PIN 11   // <-- change this to the pin where your IR receiver is connected
#define OUT_PIN  5    // device/LED connected to pin 5

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  irrecv.enableIRIn();       // Start the IR receiver
  pinMode(OUT_PIN, OUTPUT);  // Output pin
}

// Function: Blink pin 5 with a specific pattern
void Button3() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(OUT_PIN, HIGH);
    delay(360);
    digitalWrite(OUT_PIN, LOW);
    delay(900); // 180*5
  }
  delay(360);
}

// Function: Turn pin 5 OFF
void off_3() {
  digitalWrite(OUT_PIN, LOW);
}

void loop() {
  if (irrecv.decode(&results)) {
    switch (results.value) {
      case 0x181840BF:  // Remote button A
        Button3();
        break;

      case 0x1818D02F:  // Remote button B
        off_3();
        break;
    }
    irrecv.resume(); // Get ready for the next signal
  }
}

 

        


 
