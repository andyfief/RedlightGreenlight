#include <Adafruit_CircuitPlayground.h>

int time;
volatile bool green;
volatile bool reset;
int lose;
int correct;
int score;
int speed;

void setup() {
CircuitPlayground.begin();
Serial.begin(9600);
attachInterrupt(digitalPinToInterrupt(4), check, RISING);
attachInterrupt(digitalPinToInterrupt(5), resetbutton, RISING);
lose = 0;
correct = 0;
score = 0;
reset = 0;
}

void loop() {
speed = 100*score;
green = 0;

if (lose == 1) {
  CircuitPlayground.playTone(400, 200);
  CircuitPlayground.playTone(300, 200);
  CircuitPlayground.playTone(200, 200);
  CircuitPlayground.playTone(100, 200);
  speed = 0;
}
if (correct == 1) {
   CircuitPlayground.playTone(440, 100);
   ++score;
   
}
if (score == 10) {
  CircuitPlayground.playTone(100, 100);
  CircuitPlayground.playTone(100, 100);
  CircuitPlayground.playTone(200, 100);
  CircuitPlayground.playTone(300, 200);
  CircuitPlayground.playTone(200, 200);
  CircuitPlayground.playTone(400, 400);
  for(int i = 0; i < 10; i++) {
  CircuitPlayground.setPixelColor(i, 150, 0, 150);
  delay(300);
  }
  score = 0;
}
if (reset == 1) {
  CircuitPlayground.playTone(300, 100);
  CircuitPlayground.playTone(300, 100);
  for(int i = 0; i < 10; i++) {
  CircuitPlayground.setPixelColor(i, 150, 150, 150);
  delay(300);
  score = 0;
  speed = 0;
  reset = 0;
  }
}
lose = 0;
correct = 0;

int time = random() % 6000 + 1000;


for(int i = 0; i < 10; i++) {
 CircuitPlayground.setPixelColor(i, 150, 0, 0);
 }
 delay(time);

for(int i = 0; i < 10; i++) {
  CircuitPlayground.setPixelColor(i, 0, 150, 0);
}
 green = 1;
 delay(1200-speed);
Serial.println(speed);
} // loop


void check() {
  if (green == 1) {
    correct = 1;
}
  else if (green == 0) {
    lose = 1;
    score = 0;
  }
  }

void resetbutton() {
  reset = 1;
}
