
// IC pins connection:
#define Q0_PIN 2
#define Q1_PIN 3
#define Q2_PIN 4
#define Q3_PIN 5
#define Q4_PIN 6
#define Q5_PIN 7
#define Q6_PIN 8
#define Q7_PIN 9

#define Q7NEXT_PIN 10

#define MR_PIN 11
#define SH_CP_PIN 12
#define ST_CP_PIN A0
#define OE_PIN A1
#define DS_PIN A2

/* Reading the output of the register being tested. */

byte read_Qout() {
  byte tmp = (digitalRead(Q0_PIN))|(digitalRead(Q1_PIN)<<1)|(digitalRead(Q2_PIN)<<2)|(digitalRead(Q3_PIN)<<3);
  tmp = tmp|(digitalRead(Q4_PIN)<<4)|(digitalRead(Q5_PIN)<<5)|(digitalRead(Q6_PIN)<<6)|(digitalRead(Q7_PIN)<<7);
  return tmp;
}

/* Sending signal to copy content of the shift register to the output register. */

void SH_CP_out() {
  digitalWrite(SH_CP_PIN, HIGH);
  delay(10);
  digitalWrite(SH_CP_PIN, LOW);
}

/* Sending shift signal. */

void ST_CP_out() {
  digitalWrite(ST_CP_PIN, HIGH);
  delay(10);
  digitalWrite(ST_CP_PIN, LOW);
}

void setup() {
  Serial.begin(115200);
  Serial.println(F("74HC595 test."));

  // Setup MCU pins:
  #if 0
    pinMode(Q0_PIN, INPUT);
    pinMode(Q1_PIN, INPUT);
    pinMode(Q2_PIN, INPUT);
    pinMode(Q3_PIN, INPUT);
    pinMode(Q4_PIN, INPUT);
    pinMode(Q5_PIN, INPUT);
    pinMode(Q6_PIN, INPUT);
    pinMode(Q7_PIN, INPUT);
  #else
    pinMode(Q0_PIN, INPUT_PULLUP);
    pinMode(Q1_PIN, INPUT_PULLUP);
    pinMode(Q2_PIN, INPUT_PULLUP);
    pinMode(Q3_PIN, INPUT_PULLUP);
    pinMode(Q4_PIN, INPUT_PULLUP);
    pinMode(Q5_PIN, INPUT_PULLUP);
    pinMode(Q6_PIN, INPUT_PULLUP);
    pinMode(Q7_PIN, INPUT_PULLUP);
  #endif

  pinMode(Q7NEXT_PIN, INPUT);

  pinMode(MR_PIN, OUTPUT);
  pinMode(SH_CP_PIN, OUTPUT);
  pinMode(ST_CP_PIN, OUTPUT);
  pinMode(OE_PIN, OUTPUT);
  pinMode(DS_PIN, OUTPUT);

  // Run test:
  run_once();
}

void loop() {

}

void run_once() {
  Serial.println(F("Shift register reset."));
  digitalWrite(MR_PIN, LOW);
  delay(10);
  digitalWrite(MR_PIN, HIGH);

  Serial.print(F("Test Q7_NEXT: "));
  if (digitalRead(Q7NEXT_PIN) == 0) {
    Serial.println(F("ok."));
  } else {
    Serial.println(F("error."));
  }

  

  Serial.print(F("Test OE: "));
  ST_CP_out();
  digitalWrite(OE_PIN, LOW);

  if (read_Qout() == 0x00) {
    Serial.println(F("ok."));
  } else {
    Serial.println(F("error."));
  }
  
  Serial.println(F("Test shift register: "));
  
  digitalWrite(DS_PIN, HIGH);
  
  SH_CP_out();
  ST_CP_out();
  Serial.print(F(" 0x01: "));
  if (read_Qout() == 0x01) {
    Serial.println(F("ok."));
  } else {
    Serial.println(F("error."));
    Serial.println(read_Qout());
  }

  SH_CP_out();
  ST_CP_out();
  Serial.print(F(" 0x03: "));
  if (read_Qout() == 0x03) {
    Serial.println(F("ok."));
  } else {
    Serial.println(F("error."));
    Serial.println(read_Qout());
    
  }

  SH_CP_out();
  ST_CP_out();
  Serial.print(F(" 0x07: "));
  if (read_Qout() == 0x07) {
    Serial.println(F("ok."));
  } else {
    Serial.println(F("error."));
    Serial.println(read_Qout());
  }

  SH_CP_out();
  ST_CP_out();
  Serial.print(F(" 0x0F: "));
  if (read_Qout() == 0x0F) {
    Serial.println(F("ok."));
  } else {
    Serial.println(F("error."));
    Serial.println(read_Qout());
  }

  SH_CP_out();
  ST_CP_out();
  Serial.print(F(" 0x1F: "));
  if (read_Qout() == 0x1F) {
    Serial.println(F("ok."));
  } else {
    Serial.println(F("error."));
    Serial.println(read_Qout());
  }

  SH_CP_out();
  ST_CP_out();
  Serial.print(F(" 0x3F: "));
  if (read_Qout() == 0x3F) {
    Serial.println(F("ok."));
  } else {
    Serial.println(F("error."));
    Serial.println(read_Qout());
  }

  SH_CP_out();
  ST_CP_out();
  Serial.print(F(" 0x7F: "));
  if (read_Qout() == 0x7F) {
    Serial.println(F("ok."));
  } else {
    Serial.println(F("error."));
    Serial.println(read_Qout());
  }

  SH_CP_out();
  ST_CP_out();
  Serial.print(F(" 0xFF: "));
  if (read_Qout() == 0xFF) {
    Serial.println(F("ok."));
  } else {
    Serial.println(F("error."));
    Serial.println(read_Qout());
  }

  digitalWrite(DS_PIN, LOW);

  SH_CP_out();
  ST_CP_out();
  Serial.print(F(" 0xFE: "));
  if (read_Qout() == 0xFE) {
    Serial.println(F("ok."));
  } else {
    Serial.println(F("error."));
    Serial.println(read_Qout());
  }

  if (digitalRead(Q7NEXT_PIN)==1) {
    Serial.println(F("Q7NEXT_PIN ok."));
  } else {
    Serial.println(F("Q7NEXT_PIN error."));
  }
  
  SH_CP_out();
  ST_CP_out();
  Serial.print(F(" 0xFC: "));
  if (read_Qout() == 0xFC) {
    Serial.println(F("ok."));
  } else {
    Serial.println(F("error."));
    Serial.println(read_Qout());
  }

  SH_CP_out();
  ST_CP_out();
  Serial.print(F(" 0xF8: "));
  if (read_Qout() == 0xF8) {
    Serial.println(F("ok."));
  } else {
    Serial.println(F("error."));
    Serial.println(read_Qout());
  }

  SH_CP_out();
  ST_CP_out();
  Serial.print(F(" 0xF0: "));
  if (read_Qout() == 0xF0) {
    Serial.println(F("ok."));
  } else {
    Serial.println(F("error."));
    Serial.println(read_Qout());
  }

  SH_CP_out();
  ST_CP_out();
  Serial.print(F(" 0xE0: "));
  if (read_Qout() == 0xE0) {
    Serial.println(F("ok."));
  } else {
    Serial.println(F("error."));
    Serial.println(read_Qout());
  }

  SH_CP_out();
  ST_CP_out();
  Serial.print(F(" 0xC0: "));
  if (read_Qout() == 0xC0) {
    Serial.println(F("ok."));
  } else {
    Serial.println(F("error."));
    Serial.println(read_Qout());
  }

  SH_CP_out();
  ST_CP_out();
  Serial.print(F(" 0x80: "));
  if (read_Qout() == 0x80) {
    Serial.println(F("ok."));
  } else {
    Serial.println(F("error."));
    Serial.println(read_Qout());
  }

  SH_CP_out();
  ST_CP_out();
  Serial.print(F(" 0x00: "));
  if (read_Qout() == 0x00) {
    Serial.println(F("ok."));
  } else {
    Serial.println(F("error."));
    Serial.println(read_Qout());
  }

}
