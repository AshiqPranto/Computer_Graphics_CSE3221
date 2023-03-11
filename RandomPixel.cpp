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

    int i,j,x,y=rand()%6,cn=0;
    y = 1000;
    while(1){
        cn++;
        putpixel (rand()%400,rand()%400,rand()%16);;
        delay(10);
        //if(cn>=y){
        //    cleardevice();
        //    y=rand()%6;
        //}
    }

    getch();
    return 0;
}
