#include<stdlib.h>
#include<ctime>
#include<graphics.h>
#include"Bullet.h"
int maxX;
int maxY;
int Bullet::bnumber;

    Bullet::Bullet(){
        bnumber++;
        maxX = getmaxx();   midx = maxX/2;
        maxY = getmaxy();   midy = maxY/2;
        randumStartingPoint();
    }

    void Bullet::randumStartingPoint()
    {
        srand ( time(NULL) + bnumber );
        // 4 sides top, right, bottom , and left
        // first picking sides then picking coordinates accordingly
        side=rand() % 4+1;
        x = rand() % (midx*2) + 1;
        y = rand() % (midy*2) + 1;

        switch (side)
        {
            case 1: y = 0;  break;
            case 2: x = midx*2;   break;
            case 3: y = midy*2; break;
            case 4: x = 0;  break;
        }
    }
    void Bullet::moveToCenterT()
    {   /*  For the Point through line (a,b), (c,d) you can use the equation
        (b-d)x + (c-a)y = bc - ad   OR  y = ((d-b)/(c-a))x + (bc-ad)/(c-a)  */
        //Y = ( (bc - ad) - (b-d)x ) / (c - a)
        //First find the quadrant increase or decrease x accordingly.
        xLeft = x;
        yLeft = y;
        switch (side)
        {
        case 1: (x>midx)? xLeft -= 4: xLeft +=4; break;
        case 2:  xLeft -= 4;    break;
        case 3: (x>midx)? xLeft -= 4: xLeft +=4; break;
        case 4: xLeft +=4; break;
        };
        // before putting into formula make all ys negative. because screen is in 4th quadrant.

         //yLeft   = ((-1*y-(-1*midy))/(x-midx))*xLeft + ((-1*midy)*x-midx*(-1)*y)/(x-midx);
         //yLeft   = ((y-(midy))/(x-midx))*xLeft + ((midy)*x-midx*y)/(x-midx);
         yLeft= ( (midy*x - midx*y) - (midy-y)* xLeft) / (x - midx);


         x=(int)xLeft;
         y=(int)abs(yLeft);
         setcolor(YELLOW);
         circle(x,y,5);


    }

    Bullet::Bullet(int mx, int my)
    {
        midx = mx;
        midy = my;
       randumStartingPoint();
        xLeft = abs(midx-x);
        yLeft = abs(midy-y);

        xLeft = (midx/xLeft);
        yLeft = (midy/yLeft);
        bnumber++;

    }

    void Bullet::moveToCenter()
    {
        int oldx = x;
        int oldy = y;
        switch (side)
        {
        case 1:
            (x>midx)? x -= xLeft: x += xLeft;
            y += yLeft;
            break;
        case 2:
            x -= xLeft;
            (y>midy)? y-=yLeft :y +=yLeft ;
            break;
        case 3:
            (x>midx)? x -= xLeft: x += xLeft;
            y-=yLeft;
            break;
        case 4:
            x += xLeft;
            (y>midy)? y-=yLeft :y +=yLeft ;
            break;
        }
        setcolor(YELLOW);
        //line(oldx,oldy,x,y);
        drawBullet();
    }
    void Bullet::restWhenBlocked()
    {
        randumStartingPoint();
        counter =  1;
    }
    void Bullet::drawBullet()
    {
        switch (side)
        {   case 1: (x>midx)? x -= xLeft: x += xLeft; y += yLeft; break;
            case 2: x -= xLeft; (y>midy)? y-=yLeft :y +=yLeft ; break;
            case 3: (x>midx)? x -= xLeft: x += xLeft; y-=yLeft; break;
            case 4: x += xLeft; (y>midy)? y-=yLeft :y +=yLeft ; break;
        }
        //line(xLeft-x,yLeft-y,x,y);
        circle(x,y,5);
    }

