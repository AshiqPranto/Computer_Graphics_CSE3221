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

    //code for triangle
    //line(50,150,113,150);//Below line
    //line(50,150,100,50);// left line
    //line(100,50,150,113);//right line

    //setcolor(WHITE);
    //arc(170,170,0,270,60);
    //circle(170,170,60);

    // rectangle draw
    //rectangle(170,170,290,290);


    // try new one  by overdrawing

    //code for triangle
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,BLACK);
    line(50,150,150,150);//Below line
    line(50,150,100,50);// left line
    line(100,50,150,150);//right line
    floodfill(80,148,WHITE);
    //circle draw

    setcolor(CYAN);
    circle(170,170,80);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(171,171,CYAN);

    setcolor(WHITE);
    rectangle(170,170,290,290);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(289,289,WHITE);

    getch();
    return 0;
}
