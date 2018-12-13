#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "game.h"

TEST_CASE("Does the Game exists","[score]")
{
    // Arrange
    Game *g = new Game;
    // Act
    // Assert
    REQUIRE(g != NULL);
}

TEST_CASE("Gutter Game Return 0","[score]")
{
    // Arrange
    Game g;
    int pins = 0;
    // Act
    for(int frame = 0; frame < 20; frame++)
    {
        g.roll(pins);
    }
    // Assert
    REQUIRE(0 == g.scoreGame());
}

TEST_CASE("Single Pin Game Return 20","[score]")
{
    // Arrange
    Game g;
    int pins = 1;
    // Act
    for(int frame = 0; frame < 20; frame++)
    {
        g.roll(pins);
    }
    // Assert
    REQUIRE(g.scoreGame() == 20);
}

TEST_CASE("One Spare followed by 3 pin frame Game Return 16","[score]") {
    // Arrange
    Game g;
    int pins = 0;
    // Act
    g.roll(5);
    g.roll(5);
    g.roll(3);

    for (int frame = 0; frame < 17; frame++) {
        g.roll(pins);
    }
    // Assert
    REQUIRE(g.scoreGame() == 16);
}

