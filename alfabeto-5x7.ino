#include <ShiftRegister74HC595.h>
#include <Wire.h>

#define SLAVE_ADDRESS 0x04

int letter_1 = 0;
int letter_2 = 1;

int clockPin = 11;
int latchPin = 12;

ShiftRegister74HC595 display_A (2, 9, clockPin, latchPin);
ShiftRegister74HC595 display_B (2, 10, clockPin, latchPin);

void setup() {
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(changeDisplay);
}

void loop() {
  int count = 0;
  int timer = 50;
  update_display(letter_1, display_A);
  update_display(letter_2, display_B);
}

void changeDisplay(int byteCount) {
  while (Wire.available()) {
    int number = Wire.read();
    if (number >= 200) {
      letter_2 = number - 200;
    } else {
      letter_1 = number - 100;
    }
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
  },
  { // E
    B00000000,
    B00011110,
    B00011110,
    B00010000,
    B00011110,
    B00011110,
    B00000000
  },
  { // F
    B00000000,
    B00011110,
    B00011110,
    B00010000,
    B00011110,
    B00011110,
    B00011110
  },
  { // G
    B00010001,
    B00001110,
    B00011110,
    B00011110,
    B00000110,
    B00001110,
    B00000001
  },
  { // H
    B00001110,
    B00001110,
    B00001110,
    B00000000,
    B00001110,
    B00001110,
    B00001110
  },
  { // I
    B00010001,
    B00011011,
    B00011011,
    B00011011,
    B00011011,
    B00011011,
    B00010001
  },
  { // J
    B00000011,
    B00010111,
    B00010111,
    B00010111,
    B00010111,
    B00010110,
    B00011001
  },
  { // K
    B00001110,
    B00010110,
    B00011010,
    B00011100,
    B00011010,
    B00010110,
    B00001110
  },
  { // L
    B00011110,
    B00011110,
    B00011110,
    B00011110,
    B00011110,
    B00011110,
    B00000000
  },
  { // M
    B00001110,
    B00000100,
    B00001010,
    B00001010,
    B00001110,
    B00001110,
    B00001110
  },
  { // N
    B00001110,
    B00001110,
    B00001100,
    B00001010,
    B00000110,
    B00001110,
    B00001110
  },
  { // O
    B00010001,
    B00001110,
    B00001110,
    B00001110,
    B00001110,
    B00001110,
    B00010001
  },
  { // P
    B00010000,
    B00001110,
    B00001110,
    B00010000,
    B00011110,
    B00011110,
    B00011110
  },
  { // Q
    B00010001,
    B00001110,
    B00001110,
    B00001110,
    B00001010,
    B00010110,
    B00001001
  },
  { // R
    B00010000,
    B00001110,
    B00000110,
    B00010000,
    B00011010,
    B00010110,
    B00001110
  },
  { // S
    B00010001,
    B00001110,
    B00011110,
    B00010001,
    B00001111,
    B00001110,
    B00010001
  },
  { // T
    B00000000,
    B00011011,
    B00011011,
    B00011011,
    B00011011,
    B00011011,
    B00011011
  },
  { // U
    B00001110,
    B00001110,
    B00001110,
    B00001110,
    B00001110,
    B00001110,
    B00010001
  },
  { // V
    B00001110,
    B00001110,
    B00001110,
    B00001110,
    B00001110,
    B00010101,
    B00011011
  },
  { // W
    B00001110,
    B00001110,
    B00001110,
    B00001010,
    B00001010,
    B00001010,
    B00010101
  },
  { // X
    B00001110,
    B00001110,
    B00010101,
    B00011011,
    B00010101,
    B00001110,
    B00001110
  },
  { // Y
    B00001110,
    B00001110,
    B00001110,
    B00010101,
    B00011011,
    B00011011,
    B00011011
  },
  { // Z
    B00000000,
    B00001111,
    B00010111,
    B00011011,
    B00011101,
    B00011110,
    B00000000
  }
};

void update_display(int letter, ShiftRegister74HC595 x) {
  uint8_t r = 1;
  uint8_t row[2];
  for (int count = 0; count < 7; count++) {
    row[0] = alphabet[letter][count];
    row[1] = r;
    x.setAll(row);
    delay(1);
    r = r << 1;
  }
}

void renderLetter(int letter, int letter2) {
  //  uint8_t r = 1;
  //  uint8_t row[2];
  //  for (int count = 0; count < 7; count++) {
  //    row[0] = alphabet[letter][count];
  //    row[1] = r;
  //    row[2] = alphabet[letter2][count];
  //    row[3] = r;
  //    sr.setAll(row);
  //    delay(1);
  //    r = r << 1;
  //  }
}
