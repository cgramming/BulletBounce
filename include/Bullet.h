#ifndef BULLET_H
#define BULLET_H

class Bullet
{
public:
    Bullet();
    Bullet(int,int);
    ~Bullet(){}

    void randumStartingPoint();
    void moveToCenter();
    void moveToCenterT();
    void restWhenBlocked();
    void drawBullet();

    inline int getSpeed(){     return speed; }
    inline int getx(){     return x;}
    inline int gety(){     return y;}
    inline void setSpeed(int val){     speed = val;}
    static int bnumber;
private:
    int speed;
    int side;
    int x;
    int y;
    float xLeft; // number of x pixels left to get to the center to give direction to the bullet towards the center of the screen
    float yLeft; // number of y pixels left to get to the center to give direction to the bullet towards the center of the screen
    int midx;
    int midy;
    int counter;
};

#endif // BULLET_H
