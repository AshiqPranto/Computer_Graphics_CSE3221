//#include <iostream>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
//    cout << "Hello world!" << endl;
    int gd = DETECT;
    int gm;
    initgraph(&gd,&gm,"");

    int xr = 50,yr = 200;// here 'r' means reference coordinate
    int x = 200,y = 100;
    double rotationAngle;
    printf("Enter the clockwise rotation angle: ");
    scanf("%lf",&rotationAngle);

    line(xr,yr,x,y);



    rotationAngle = (rotationAngle*3.1416)/180;

    int xPrime = xr + (x-xr)*cos(rotationAngle) - (y-yr)*sin(rotationAngle);
    int yPrime = yr + (x-xr)*sin(rotationAngle) + (y-yr)*cos(rotationAngle);

    //printf("RotationAngle = %lf\n",rotationAngle);

    setcolor(2);
    line(xr,yr,xPrime,yPrime);
//    printf("xPrime = %d,\t yPrime = %d\n",xPrime,yPrime);

   getch();
    return 0;
}
