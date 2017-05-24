#include "brick.h"
#include "ofMain.h"

#include <stdio.h>

Brick::Brick() {

}

Brick::Brick(int kind, int row, int col) {
    this->kind = kind;
    this->row = row;
    this->col = col;
    this->visible = true;
}

void Brick::draw(int cols) {
    if(visible) {
        float x = (col - 1)* ofGetWidth() / cols;
        float y = 50 + row * 20;
        float w = ofGetWidth() / cols;
        float h = 20.0;

        ofSetColor(kind*24, kind*8, kind * 12);
        ofFill();
        ofDrawRectangle(x,y,w,h);

        ofSetColor(255, 255, 255);
        ofNoFill();
        ofDrawRectangle(x,y,w,h);

    }

}
