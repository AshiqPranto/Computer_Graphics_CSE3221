//#include <iostream>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>

int main()
{
//    cout << "Hello world!" << endl;
    int gd = DETECT;
    int gm;
    initgraph(&gd,&gm,"");

    //circle(100,250,100);

    //setcolor(LIGHTBLUE);
    // draw rectangle without rectangle function
    //line(100,250,200,250);
    //line(100,350,200,350);
    //line(100,250,100,350);
    //line(200,250,200,350);
    //setfillstyle(SOLID_FILL,LIGHTBLUE);
    //floodfill(101,251,LIGHTBLUE);

    //setcolor(YELLOW);
    //rectangle(100,300,300,400);
    //setfillstyle(SOLID_FILL,YELLOW);
    //floodfill(101,301,YELLOW);


    //int topx = 50;
    //int topy = 20;
    //int bottomx = 370;
    //int bottomy = 212;


    //setcolor(WHITE);

    //rectangle(topx,topy,bottomx,bottomy);
    //setfillstyle(SOLID_FILL, GREEN);
    //floodfill(51, 21, WHITE);
    // height:width = 3:5 and the radius = width/5
    //height 192 width 320 radius = 64
    //int centerx = (topx + bottomx) / 2;
    //int centery = (topy + bottomy) / 2;

    // draw bd national flag
    setcolor(GREEN);
    rectangle(50,50,250,170);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(51,51,GREEN);

    setcolor(WHITE);
    rectangle(40,40,50,300);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(41,41,WHITE);

    setcolor(RED);
    circle(150,110,40);
    setfillstyle(SOLID_FILL,RED);
    floodfill(131,101,RED);

    getch();
    //delay(500000);
    closegraph();
    return 0;
}
