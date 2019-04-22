#ifndef SHIELD_H
#define SHIELD_H
class Shield
{
public:
    Shield();
    Shield(int , int , int , int , int );
    void setSpeed(int);
    void setStP(int);
    void fixStAngle(int);
    void moveR();
    void moveL();
    int getStP();
    void drawShield(int,int);
    void fixStAngle();
    void setSizeOfArc(int);

    ~Shield();

private:
    int speed;
    int startP;
    int sizeOfArc;
    int thickness;
    int radius;
};
#endif // SHIELD_H

