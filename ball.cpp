#include "ball.h"
#include "game.h"

const int RADIUS = 14;

Ball::Ball()
{
    reset();
}

void Ball::draw() {
    ofSetColor(64,128,64);
    ofFill();
    ofDrawCircle(position.x, position.y, 15);

}


void Ball::reset() {

    position.set( (0.5 + ofRandom(-0.25, 0.25) )* ofGetWidth(),
                  (0.5 + ofRandom(-0.25, 0.25) )* ofGetHeight() );

    velocity.set(ofRandom(-2.0,2.0), -2.0);

}

void Ball::move(float multiplier) {
    position += velocity.getScaled(multiplier);

}

bool Ball::paddleHit(Paddle paddle) {
    return (position.x > paddle.x) && (position.x < paddle.x + paddle.width);

}

void Ball::checkCollision(Paddle paddle, vector<vector<Brick>> bricks) {
    if (position.x < RADIUS)
        velocity.x = - velocity.x;
    else if (position.x > ofGetWidth() - RADIUS)
        velocity.x = - velocity.x;

    if (position.y > ofGetHeight() - RADIUS - 30) {
        if (paddleHit(paddle))
            velocity.y = - velocity.y;
        else {
            //miss
            reset();
        }
    }

    if (position.y < RADIUS + 50 + 20 * (bricks.size() + 1 ) ) {
        int row = bricks.size()-1;
        bool hit = false;
        while (! hit) {
           float xpct = position.x / ofGetWidth();
           int col = floor(xpct * bricks[row].size());
           if( bricks[row][col].visible ) {
               hit = true;
               bricks[row][col].visible = false;
               velocity.y = - velocity.y;
           }
        }

    }
}
