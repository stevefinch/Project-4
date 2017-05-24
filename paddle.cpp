#include "paddle.h"
#include "ofMain.h"
#include "game.h"

const int HEIGHT = 10;
const int WIDTH = 80;
const int PADDLESPEED = 6;

Paddle::Paddle()
{
    height = HEIGHT;
    width = WIDTH;
    x = ofGetWidth()/2-width/2;;
}

void Paddle::draw() {
    ofSetColor(255,0,0);
    ofFill();
    ofDrawRectangle(x, ofGetHeight() - 30, width, height);
}

void Paddle::move(int mousex) {
    x = min(mousex, ofGetWidth() - width);

}
