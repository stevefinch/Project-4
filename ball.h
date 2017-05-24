#ifndef BALL_H
#define BALL_H

#include "ofMain.h"
#include "paddle.h"
#include "brick.h"

class Ball
{
public:
    ofVec2f position;
    ofVec2f velocity;

    Ball();

    void draw();
    void move(float multiplier);
    void reset();
    void checkCollision(Paddle paddle, vector<vector<Brick>> bricks);
    bool paddleHit(Paddle paddle);

};

#endif // BALL_H
