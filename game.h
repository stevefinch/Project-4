#ifndef GAME_H
#define GAME_H

#include "paddle.h"
#include "ball.h"
#include "brick.h"
#include <vector>

class Game
{
public:
    Paddle paddle;
    Ball ball;
    int level;
    float multiplier;
    vector<vector<Brick>> bricks;

    Game();

    void draw();
    void update();
    void load(int level);

};

#endif // GAME_H
