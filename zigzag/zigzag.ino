/*zig zag*/
auto pin = PB0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(pin, OUTPUT);
}

auto intensity = 100;

const auto o = 300;
const auto ooo = o+o+o;
const auto pause_bit = o;
const auto pause_letter = o+o;
const auto pause_word = 2*pause_letter;
const auto END = 0;

void play_bit(int what){
  analogWrite(pin, intensity);   // turn the LED on (HIGH is the voltage level)
  delay(what);                       // wait for a second
  analogWrite(pin, 0);    // turn the LED off by making the voltage LOW
  delay(pause_bit);                       // wait for a second
}

template<class T> void play_letter(const T *bits){
  do{
    play_bit(*bits);
  } while(*bits++);
  delay(pause_letter);
}


const int z[] = {ooo, ooo, o, o, END};
const int i[] = {o, o, END};
const int g[] = {ooo, ooo, o, END};
const int a[] = {o, ooo, END};
const int flikker[] = {50, 50, 50, 50, 50, 50, 50, END};


// the loop function runs over and over again forever
void loop() {
  play_letter(flikker);
  delay(pause_word);
  
  play_letter(z);
  play_letter(i);
  play_letter(g);
  delay(pause_word);
  
  play_letter(z);
  play_letter(a);
  play_letter(g);
  delay(pause_word);
}
