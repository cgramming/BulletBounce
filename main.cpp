#include <iostream>
#include<sstream>
#include <graphics.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<conio.h>

const int ARC_SPEED=4;
const int ARC_RADIUS=100;
const int ARC_SIZE=40;
const int ARC_THICKNESS=9;
const int BULET_SPEED=1;
const int SHIP_RADIUS=50;
const int MAX_BLOCK_IN_ONE_STAGE=10;
const int BULLETS_ADDED_EACH_STAGE=3;
int midx,midy;
#include"Shield.h"
#include"Bullet.h"

using namespace std;
stringstream st1, st2;
string s1,s2;
bool checkPoint(int radius, int x, int y, float endAngle, float startAngle)
{

    // Calculate polar co-ordinates
    x = midx -x;
    y = midy - y;



    float polarradius = sqrt(x*x+y*y);
    //float Angle = atan(y/x);
    float Angle = atan2(y,x);
    //Angle = Angle;
    float degAngle= (Angle * 180) / 3.14159265;
    degAngle = 180 - degAngle;
    // Check whether polarradius is less then radius of circle
    // or not and Angle is between startAngle and endAngle
    // or not
    //-----------------------------
//st1.clear();
//st2.clear();
//    st1<<"degAngle >=  startAngle && degAngle <=  endAngle   &&  polarradius  <=  radius                                                                      ";
//    st2<<degAngle<< "  >= ("<<startAngle<<")       &&  "<<degAngle<<" <= (" <<endAngle<<")       &&  "<<polarradius<<"     <= ("<<radius<<") -----> bx("<<x<<") by("<<y<<")                                                                 ";
//    s1=st1.str();
//    s2=st2.str();
//    char c1[s1.length()+1];
//    char c2[s2.length()+1];
//    strcpy(c1, s1.c_str());
//    strcpy(c2, s2.c_str());
//    outtextxy(50,50,c1);
//    outtextxy(50,80,c2);

    //-----------------------------
    if (degAngle>=startAngle && degAngle<=endAngle && polarradius<=radius+10)
        return true;
    else
        return false;
}

bool isInside(int circle_x, int circle_y, int rad, int x, int y)
{
    // Compare radius of circle with distance
    // of its center from given point
    if ((x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad)
        return true;
    else
        return false;
}

using namespace std;

int main()
{
    DWORD x = GetSystemMetrics(0);
    DWORD y = GetSystemMetrics(1);
    initwindow(x,y,"B B", -2,-2);

    int page =0;
    midx = getmaxx()/2, midy= getmaxy()/2;

    Bullet b1;


    Shield sh(ARC_SPEED,0,ARC_SIZE,ARC_THICKNESS,ARC_RADIUS);

    int loopFlag = 100;

    while(loopFlag>1)
    {
        loopFlag++;
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();

        setcolor(YELLOW);

        b1.moveToCenterT();

        if(isInside(midx, midy, ARC_RADIUS + ARC_THICKNESS, b1.getx(), b1.gety()))
        {
            if(checkPoint(ARC_RADIUS, b1.getx(),abs(b1.gety()), sh.getStP()+ ARC_SIZE, sh.getStP())) {cout<<" #######IN######## "; b1.restWhenBlocked();}
        }
        if(isInside(midx, midy, SHIP_RADIUS, b1.getx(), b1.gety())) {cout<<"\a\a\a\a you rr dead  "; _getch(); return 0;}

        //readimagefile("ship.bmp",midx-50,midy-50,midx+50,midy+50);

        setcolor(WHITE);
        circle(midx,midy,SHIP_RADIUS);
        setcolor(COLOR(0,255,255));

        sh.drawShield(midx,midy);

        if(GetAsyncKeyState(VK_LEFT)) {sh.moveL();}
        else if (GetAsyncKeyState(VK_RIGHT)) {sh.moveR();}
        else if (GetAsyncKeyState(VK_ESCAPE)) {return 0;}

        page = 1- page;
        delay(10);

    }

    getch();
    closegraph();
    return 0;
}
