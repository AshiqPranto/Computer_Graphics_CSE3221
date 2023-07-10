//#include <iostream>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>

void pixelPlot(int xc,int yc,int x,int y)
{
    putpixel(xc+x,yc+y,YELLOW);
    putpixel(xc-x,yc+y,YELLOW);
    putpixel(xc+x,yc-y,YELLOW);
    putpixel(xc-x,yc-y,YELLOW);
    putpixel(xc+y,yc+x,YELLOW);
    putpixel(xc-y,yc+x,YELLOW);
    putpixel(xc+y,yc-x,YELLOW);
    putpixel(xc-y,yc-x,YELLOW);

}

void midPointCircleDraw(int xc,int yc,int r)
{
    int p,x,y;
    p = 1-r;
    x = 0;
    y = r;
    pixelPlot(xc,yc,x,y);
    while(x<y)
    {
        x++;

        if(p<0) p += (2*x) + 1;
        else
        {
            y--;
            p += 2*x +1 -2*y;
        }
        pixelPlot(xc,yc,x,y);
        delay(1);
    }
}

int main()
{
//    cout << "Hello world!" << endl;
    int gd = DETECT;
    int gm;
    initgraph(&gd,&gm,"");
    freopen("input.txt", "r", stdin);
    int x,y,r;
    printf("Enter the center coordinates and radius of your circle:\n x y r\n");
    scanf("%d %d %d",&x,&y,&r);

    midPointCircleDraw(x,y,r);

    getch();
    return 0;
}
//input
//150 80 50
