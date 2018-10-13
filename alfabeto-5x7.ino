#include <ShiftRegister74HC595.h>
int numberOfShiftRegisters = 2; // number of shift registers attached in series
int serialDataPin = 11; // DS
int clockPin = 12; // SHCP
int latchPin = 8; // STCP
ShiftRegister74HC595 sr (numberOfShiftRegisters, serialDataPin, clockPin, latchPin);

void setup() {
}
void loop() {

  int letter = 0;
  int count = 0;
  int timer = 200;
  while (letter < 4) {
    while (count < timer) {
      renderLetter(letter);
      count++;
    }
    count = 0;
    letter++;
  }
}

uint8_t alphabet[26][7] = {
  { // A
    B00011011,
    B00010101,
    B00001110,
    B00001110,
    B00000000,
    B00001110,
    B00001110
  },
  { // B
    B00010000,
    B00001101,
    B00001101,
    B00000001,
    B00001101,
    B00001101,
    B00010000
  },
  { // C
    B00010001,
    B00001110,
    B00011110,
    B00011110,
    B00011110,
    B00001110,
    B00010001
  },
  { // D
    B00010000,
    B00001101,
    B00001101,
    B00001101,
    B00001101,
    B00001101,
    B00010000
  }
};


void renderLetter(int letter) {
  uint8_t r = 1;
  uint8_t row[2];
  for (int count = 0; count < 7; count++) {
    row[0] = alphabet[letter][count];
    row[1] = r;
    sr.setAll(row);
    delay(1);
    r = r << 1;
  }
}
