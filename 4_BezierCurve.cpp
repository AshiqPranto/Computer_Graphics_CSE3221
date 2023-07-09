#include<graphics.h>
#include<stdio.h>
#include<conio.h>

int fact(int n)
{
    if(n==0) return 1;
    return n*fact(n-1);
}
double ncr(int n,int r)
{
    return (fact(n)/(fact(r)*fact(n-r)));
}
double power(double a,int b)
{
    double res = 1.0;
    while(b--)
    {
        res *= a;
    }
    return res;
}
double BEZ(int k,int n,double u)
{
    return ncr(n,k)*power(u,k)*power((1-u),(n-k));
}
void drawBezierCurve(int x[],int y[],int n)
{
    for(double u = 0.0;u<=1;u+=0.005)
    {
        double xPixel = 0.0, yPixel = 0.0;
        for(int k = 0;k<=n;k++)
        {
            xPixel += x[k]*BEZ(k,n,u);
            yPixel += y[k]*BEZ(k,n,u);
        }
        putpixel(xPixel,yPixel,WHITE);
    }
    for(int k = 0;k<=n;k++)
    {
        char xy[50];
        sprintf(xy,"(%d,%d)",x[k],y[k]);
        outtextxy(x[k]+10,y[k]+10,xy);
        //outtext(x[k]+20,y[k]+20,YELLOW);
        putpixel(x[k],y[k],YELLOW);
    }
    return;
}

int main()
{

    int gd = DETECT;
    int gm;
    initgraph(&gd,&gm,"");

    freopen("input.txt","r",stdin);

    int n;
    printf("Enter number of Control Points: ");
    scanf("%d",&n);
    int x[50],y[50];
    for(int i = 0;i<n;i++)
    {
        printf("\nEnter the %d point: (x,y) = ",i+1);
        scanf("%d %d",&x[i],&y[i]);
    }
    drawBezierCurve(x,y,n-1);

    getch();
    return 0;
}
/*
Input:
5
10 10
50 100
100 30
140 120
190 70
*/
