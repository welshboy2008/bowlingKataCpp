#ifndef __GAME_H_
#define __GAME_H_

class game
{
public:
  game();
  ~game();
  int score();
  void pinstruck(int pins);
  void resetScore();
private:
  int rolls[21];
  int currentRoll;
  int sumOfBallsInFrame(int frameIndex);
  bool isSpare(int frameIndex);
  bool isStrike(int frameIndex);
  int spareBonus(int frameIndex);
  int strikeBonus(int frameIndex);  
};

#endif
