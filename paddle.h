#ifndef PADDLE_H
#define PADDLE_H


class Paddle
{
public:
    int x;
    int height;
    int width;

    Paddle();

    void draw();
    void move(int mousex);
};

#endif // PADDLE_H
