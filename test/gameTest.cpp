#include "game.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

void doRolls(int, int);
void bowlSpare();
void bowlStrike();

std::unique_ptr<game> bg(new game);

TEST_CASE("gutter game", "[game]")
{
  bg->resetScore();
  REQUIRE(bg->score() == 0);
}

TEST_CASE("a score of 1s", "[game]")
{
  bg->resetScore();
  doRolls(20, 1);
  REQUIRE(bg->score() == 20);
  bg->resetScore();
}

TEST_CASE("test spare", "[game]")
{
  bg->resetScore();
  bowlSpare();
  bg->pinstruck(3);
  doRolls(17,0);
  REQUIRE(bg->score() == 16);
}

TEST_CASE("bowl a strike", "[game]")
{
  bg->resetScore();
  bowlStrike();
  doRolls(16, 0);
  REQUIRE(bg->score() == 48);
}

TEST_CASE("bowl perfect game", "[game]")
{
  bg->resetScore();
  doRolls(12, 10);
  REQUIRE(bg->score() == 300);
}

void bowlSpare()
{
  bg->pinstruck(5);
  bg->pinstruck(5);
}

void bowlStrike()
{
  bg->pinstruck(10);
  bg->pinstruck(7);
  bg->pinstruck(3);
  bg->pinstruck(9);
  bg->pinstruck(0);
}

void doRolls(int numRolls, int pins)
{
  for(int i = 0; i < numRolls; i++)
  {
    bg->pinstruck(pins);
  }
}
