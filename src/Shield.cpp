#include<graphics.h>
#include"Shield.h"

    Shield::Shield(){}
    Shield::~Shield(){}
    Shield::Shield(int sp, int stP, int siOA, int th, int r)
    {
            speed = sp;
            startP = stP;
            sizeOfArc= siOA;
            thickness= th;
            radius=r;
    }
    void Shield::drawShield(int midx, int midy)
    {
        setcolor(COLOR(0,255,255));
        for(int i=0; i<=thickness; i++) arc(midx, midy,startP,startP+sizeOfArc,radius+i );
    }
    void Shield::setSpeed(int sp){speed = sp;}
    void Shield::setStP(int st) {startP = st;}
    void Shield::setSizeOfArc(int soa) {sizeOfArc = soa;}
    int Shield::getStP(){return startP;}

    void Shield::moveR(){startP -= speed; fixStAngle();}
    void Shield::moveL(){startP += speed; fixStAngle();}

    //Arc when keep rotating in one direction makes the angles either increase over 360 degrees or will decrease below negative
    //this function sets the Starting angle back to a
    void Shield::fixStAngle()
    {
        if(startP>360) startP -=360;
        else if (startP<0) startP +=360;
        //else if (startP+sizeOfArc<0) startP +=360;
    }
