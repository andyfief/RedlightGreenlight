# RedlightGreenlight
Rules
The rules are simple:
The board will start solid red. After a random amount of time between 1 and 6 seconds, the board will flash green.
To score a point, press the right button while the board is green.
Each point you score will decrease the time for which the green is shown by 100ms
Pressing the button when the lights are not green is an automatic game over.
Score 10 points to win!

Inputs
The left button will reset the game to level 1
The right button serves as your input to try and score points

Outputs
When you lose, a sad order of tones will play
When you win, a happy set of sounds will play, and the board will slowly turn purple while it chimes
When you reset the board, it will slowly turn white before it resets to level 1.

The code works by setting the board to red for a random duration between 1 and 6 seconds. Next, when running through the loop, it will set the board color to green for a certain duration. Using a boolean variable "green", during that duration, the variable green will = 1. Next, there is an interrupt monitoring the right button. If the player presses the button while the board is green (green = 1) it will set boolean variable "correct" to 1. If the player presses the button when the board is not green, it will add 1 to variable "lose". On the next loop through of the code, if lose = 1, it will play the losing animation. It will play a short beep if "correct" = 1 to signify scoring a point, and add 1 to "score". It will then adjust the duration for which green = 1, by muiltiplying 100*score and subtracting that (in ms) from the duration that the board stays green. If the player manages to reach 10 points, the winning sound and animation will play.
Additionally, there is an interrupt monitoring the left button. If it is pressed, it will set variable "reset" to one, which tells the game on the next loop to set all the variables back to 0 to start over.
