#ifndef BRICK_H
#define BRICK_H

class Brick
{
public:
    int kind;
    int row;
    int col;
    bool visible;

    Brick();
    Brick(int kind, int row, int col);

    void draw(int cols);
};

#endif // BRICK_H
