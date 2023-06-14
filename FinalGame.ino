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
correct = 0;        // setup sets all variables to 0
score = 0;
reset = 0;
}

void loop() {
speed = 100*score;    // muiltiplies score by 100 to later reduce duration of "green"
green = 0;

if (lose == 1) {
  CircuitPlayground.playTone(400, 200);  // check if the player misinputted,
  CircuitPlayground.playTone(300, 200);  // if they did, play this tune
  CircuitPlayground.playTone(200, 200);
  CircuitPlayground.playTone(100, 200);
  speed = 0;                            //if they lose, also set speed back to 0 so they can keep playing
}
if (correct == 1) {                    // if correct, play a beep
   CircuitPlayground.playTone(440, 100);
   ++score;                            // and add 1 to score
   
}
if (score == 10) {
  CircuitPlayground.playTone(100, 100);
  CircuitPlayground.playTone(100, 100);      // if score = 10, play this tune
  CircuitPlayground.playTone(200, 100);
  CircuitPlayground.playTone(300, 200);
  CircuitPlayground.playTone(200, 200);
  CircuitPlayground.playTone(400, 400);
  for(int i = 0; i < 10; i++) {
  CircuitPlayground.setPixelColor(i, 150, 0, 150);    // and play this animation
  delay(300);
  }
  score = 0;                                   // then set score back to 0 to play again
}
if (reset == 1) {                            // if the player hit the reset button, 
  CircuitPlayground.playTone(300, 100);      // play this tune
  CircuitPlayground.playTone(300, 100);
  for(int i = 0; i < 10; i++) {
  CircuitPlayground.setPixelColor(i, 150, 150, 150);    // play this animation
  delay(300);
  score = 0;
  speed = 0;        // set variables back to 0
  reset = 0;
  }
}
lose = 0;
correct = 0;

int time = random() % 6000 + 1000;          // set the time that the board will stay red for, randomly
                                            // between 1 and 6 seconds

for(int i = 0; i < 10; i++) {
 CircuitPlayground.setPixelColor(i, 150, 0, 0);    // set board red for (time)
 }
 delay(time);

for(int i = 0; i < 10; i++) {
  CircuitPlayground.setPixelColor(i, 0, 150, 0);    // set board to green for 1200 - speed
}
 green = 1;
 delay(1200-speed);
Serial.println(speed);
} // loop


void check() {
  if (green == 1) {                                  // player hits button,
    correct = 1;                                      // board green? add 1 to correct
}
  else if (green == 0) {                              // not green? add 1 to lose
    lose = 1;
    score = 0;
  }
  }

void resetbutton() {                                // if player hits reset, add 1 to reset variable
  reset = 1;
}
