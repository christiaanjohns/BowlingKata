//
// Created by sprocket89 on 12/12/2018.
//

#include "game.h"

void Game::roll(int frame) {
/*  James Solution
    if(count%2==0)
    {
        if(firstFrame+frame == 10)
        {
            isSpare = true;
        }

    }
    else
    {
        firstFrame = frame;
        if(isSpare)
        {
            score+=frame;
            isSpare = false;
        }
    }
    score+=frame;
    count++;*/

rolls[currentRoll] = frame;
currentRoll++;

}
/**
 * Returns final game score
 */
int Game::scoreGame()
{
    int score = 0;
    int rollNum = 0;
    for (int frame=0; frame < 10; frame++)
    {
        if(isSpare(rollNum)) // spare
        {
            score += 10 + rolls[rollNum + 2];
        }
        else
        {
            score += rolls[rollNum] + rolls[rollNum + 1];
        }
        //Scoring per game
        rollNum += 2;
    }
    return score;
}

bool Game::isSpare(int frameIndex)
{
    return rolls[frameIndex] + rolls[frameIndex + 1] == 10;

}
