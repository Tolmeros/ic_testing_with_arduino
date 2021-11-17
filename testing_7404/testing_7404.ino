
// IC pins connection:

#define IC1A_PIN 3
#define IC1Y_PIN 4
#define IC2A_PIN 5
#define IC2Y_PIN 6
#define IC3A_PIN 7
#define IC3Y_PIN 8

#define IC4A_PIN 12
#define IC4Y_PIN 11
#define IC5A_PIN A1
#define IC5Y_PIN A0
#define IC6A_PIN 2
#define IC6Y_PIN A2

const byte input[6] = {IC1A_PIN, IC2A_PIN, IC3A_PIN, IC4A_PIN, IC5A_PIN, IC6A_PIN};
const byte output[6] = {IC1Y_PIN, IC2Y_PIN, IC3Y_PIN, IC4Y_PIN, IC5Y_PIN, IC6Y_PIN};

void setup() {
  Serial.begin(115200);
  Serial.println(F("7404 IC test."));

  for (byte i = 0; i<6; i++) {
    pinMode(output[i], INPUT_PULLUP);
    pinMode(input[i], OUTPUT);
  }

  #if 0
  // Setup MCU pins:
  #if 0
    pinMode(IC1Y_PIN, INPUT);
    pinMode(IC2Y_PIN, INPUT);
    pinMode(IC3Y_PIN, INPUT);
    pinMode(IC4Y_PIN, INPUT);
    pinMode(IC5Y_PIN, INPUT);
    pinMode(IC6Y_PIN, INPUT);
    
  #else
    pinMode(IC1Y_PIN, INPUT_PULLUP);
    pinMode(IC2Y_PIN, INPUT_PULLUP);
    pinMode(IC3Y_PIN, INPUT_PULLUP);
    pinMode(IC4Y_PIN, INPUT_PULLUP);
    pinMode(IC5Y_PIN, INPUT_PULLUP);
    pinMode(IC6Y_PIN, INPUT_PULLUP);
  #endif

  pinMode(IC1A_PIN, OUTPUT);
  pinMode(IC2A_PIN, OUTPUT);
  pinMode(IC3A_PIN, OUTPUT);
  pinMode(IC4A_PIN, OUTPUT);
  pinMode(IC5A_PIN, OUTPUT);
  pinMode(IC6A_PIN, OUTPUT);
  #endif

  // Run test:
  run_once();
}

void loop() {

}

void run_once() {
  //Serial.println(F(""));
  byte i;
  bool prev_result;
  for (i = 0; i<6; i++) {
    Serial.print(F("Testing inverter # "));
    Serial.print(i+1);
    digitalWrite(input[i], LOW);
    prev_result = (digitalRead(output[i]) == HIGH);
    digitalWrite(input[i], HIGH);

    if (prev_result && (digitalRead(output[i]) == LOW)) {
      Serial.println(F(" ok."));
    } else {
      Serial.println(F(" error!"));
    }
  }
}
