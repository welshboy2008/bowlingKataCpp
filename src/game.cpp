#include "game.hpp"
#include <iostream>

game::game()
{
  resetScore();
}

game::~game()
{}

void game::resetScore()
{
  for(int i = 0; i < 21; i++)
  {
    rolls[i] = 0;
  }
  currentRoll = 0;
}

int game::score()
{
  int score = 0;
  int frameIndex = 0;
  for(int frame = 0; frame < 10; frame++)
  {
    if(isStrike(frameIndex))
    {
      // we have a strike...
      score += 10 + strikeBonus(frameIndex);
      frameIndex++;
    }
    else if(isSpare(frameIndex))
    {
      score += 10 + spareBonus(frameIndex);
      frameIndex += 2;
    }
    else
    {
      score += sumOfBallsInFrame(frameIndex);
      frameIndex += 2;
    }
  }
  return score;
}

void game::pinstruck(int pins)
{
  rolls[currentRoll++] = pins;
}

int game::sumOfBallsInFrame(int frameIndex)
{
  return rolls[frameIndex] + rolls[frameIndex + 1];
}

bool game::isSpare(int frameIndex)
{
  return rolls[frameIndex] + rolls[frameIndex+1] == 10;
}

int game::spareBonus(int frameIndex)
{
  return rolls[frameIndex + 2];
}

bool game::isStrike(int frameIndex)
{
  return rolls[frameIndex] == 10;
}

int game::strikeBonus(int frameIndex)
{
  return rolls[frameIndex + 1] + rolls[frameIndex + 2];
}
