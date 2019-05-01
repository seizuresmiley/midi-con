#include <MIDI_Controller.h>

const uint8_t velocity = 0b1111111; // Maximum velocity (0b1111111 = 0x7F = 127)
const uint8_t addresses[4][4] = {   // the note numbers corresponding to the buttons in the matrix
  {  1,  2,  3 , 4},
  {  5,  6,  7, 8 },
  {  9,  10,  11, 12 },
  { 13, 14, 15, 16 }
};

// Create a new instance of the class 'ButtonMatrix', called 'buttonmatrix', with dimensions 4 rows and 3 columns, with the rows connected to pins 2, 3, 4 and 5
// and the columns connected to pins 6, 7 and 8, that sends MIDI messages with the notes specified in 'addresses' on MIDI channel 1, with velocity 127
ButtonMatrix<4, 4> buttonmatrix({2, 3, 4, 5}, {6, 7, 8,9}, addresses, 1, velocity);

void setup() {}

void loop() {
  // Refresh the buttons (check whether the states have changed since last time, if so, send it over MIDI)
  MIDI_Controller.refresh();
};
