#include<bits/stdc++.h>
#include<graphics.h>
//#include<stdio.h>
#include<conio.h>


void BresenhamLine(int xa,int ya,int xb,int yb)
{
    int dx = abs(xa-xb), dy = abs(ya-yb);
    int p = 2*dy - dx;
    int twoDy = 2*dy;
    int twoDyDx = 2*(dy-dx);
    int x,y,xEnd;
    if(xa>xb)
    {
        x = xb;
        y = yb;
        xEnd = xa;
        //swap(xa,xb), swap(ya,yb);
    }
    else
    {
        x = xa;
        y = ya;
        xEnd = xb;
    }
    putpixel(xa,ya,WHITE);
    while(x < xEnd){
        x++;
        if(p<0){
            p += twoDy;
        }
        else{
            y++;
            p += twoDyDx;
        }
        putpixel(x,y,WHITE);
    }
}

int main()
{
//    cout << "Hello world!" << endl;
    int gd = DETECT;
    int gm;
    initgraph(&gd,&gm,"");
    freopen("input.txt", "r", stdin);
    int xa,xb,ya,yb;
    printf("Enter coordinate value of two end point in your line: \n x y\n");
    scanf("%d %d %d %d",&xa,&ya,&xb,&yb);
    BresenhamLine(xa,ya,xb,yb);

    getch();
    return 0;
}

/*
input
40 40
190 100
*/
