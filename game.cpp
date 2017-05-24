#include <string>
#include <stdio.h>

#include "game.h"

Game::Game()
{
    level = 1;
    paddle.width = 100 - level * 15;
    multiplier = 2 + level * 1.25;
    load(level);
}

void Game::draw() {
    paddle.draw();
    ball.draw();
    for(auto row : bricks)
        for(auto brick : row) {
            brick.draw(row.size());
        }

}

void Game::update() {
    ball.move(multiplier);
    ball.checkCollision(paddle, bricks);

}

void Game::load(int level) {
    string fn = "L" + to_string(level) + ".txt";

    ofBuffer buffer = ofBufferFromFile(fn);

    int row = 0;
    for (auto line : buffer.getLines()){
        vector<Brick> v;
        ++row;
        int col = 0;
        for (auto brickchar : line)
            v.push_back(Brick(brickchar & 0x07, row, ++col));

        if(v.size()) bricks.push_back(v);
    }
}
