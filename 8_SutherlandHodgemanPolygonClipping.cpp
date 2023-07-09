    #include<graphics.h>
    #include<stdio.h>
    #include<conio.h>
    #include<iostream>

    #define round(a) ((int)(a+0.5))
    int k;
    double arr[50],m;
    int xmin,ymin,xmax,ymax;

    void clipLeft(double x1,double y1,double x2,double y2)
    {
        if(x2-x1)
            m = (y2-y1)/(x2-x1);
        else
            m = 100000;
        if(x1>=xmin && x2>=xmin)
        {
            arr[k] = x2;
            arr[k+1] = y2;
            k+=2;
        }
        if(x1<xmin && x2>=xmin)
        {
            arr[k] = xmin;
            arr[k+1] = y1 + m*(xmin-x1);
            arr[k+2] = x2;
            arr[k+3] = y2;
            k+=4;
        }
        if(x1>=xmin && x2 < xmin)
        {
            arr[k] = xmin;
            arr[k+1] = y1 + m*(xmin-x1);
            k+=2;
        }
    }
    void clipTop(double x1, double y1, double x2, double y2)
    {
        if(y2-y1)
            m = (x2-x1)/(y2-y1);
        else
            m = 1000000;
        if(y1<=ymax && y2<=ymax)
        {
            arr[k] = x2;
            arr[k+1] = y2;
            k+=2;
        }
        if(y1 > ymax && y2 <= ymax)
        {
            arr[k] = x1 + m*(ymax-y1);
            arr[k+1] = ymax;
            arr[k+2] = x2;
            arr[k+3] = y2;
            k+=4;
        }
        if(y1<=ymax && y2>ymax)
        {
            arr[k] = x1 + m*(ymax-y1);
            arr[k+1] = ymax;
            k+=2;
        }
    }
    void clipRight(double x1,double y1,double x2,double y2)
    {
        if(x2-x1)
            m = (y2-y1)/(x2-x1);
        else
            m = 100000;
        if(x1<=xmax && x2<=xmax)
        {
            arr[k] = x2;
            arr[k+1] = y2;
            k+=2;
        }
        if(x1<=xmax && x2>xmax)
        {
            arr[k] = xmax;
            arr[k+1] = y1 + m*(xmax-x1);
            k+=2;
        }
        if(x1>xmax && x2<=xmax)
        {
            arr[k] = xmax;
            arr[k+1] = y1 + m*(xmax-x1);
            arr[k+2] = x2;
            arr[k+3] = y2;
            k+=4;
        }
    }
    void clipBottom(double x1,double y1,double x2,double y2)
    {
        if(y2-y1)
            m = (x2-x1)/(y2-y1);
        else
            m = 100000;
        if(y1>=ymin && y2>=ymin)
        {
            arr[k] = x2;
            arr[k+1] = y2;
            k+=2;
        }
        if(y1>=ymin && y2<ymin)
        {
            arr[k] = x1 + m*(ymin-y1);
            arr[k+1] = ymin;
            k+=2;
        }
        if(y1<ymin && y2>=ymin)
        {
            arr[k] = x1 + m*(ymin-y1);
            arr[k+1] = ymin;
            arr[k+2] = x2;
            arr[k+3] = y2;
            k+=4;
        }
    }


    int main()
    {

        int gd = DETECT;
        int gm;
        initgraph(&gd,&gm,"");
        freopen("input.txt","r",stdin);

        int n,polyy[50],poly[50];

        printf("Enter the coordinate of your rectangular clip window: \nxmin,ymin: ");
        scanf("%d %d",&xmin,&ymin);
        printf("\nxmax ymax: ");
        scanf("%d %d",&xmax,&ymax);
        printf("\nEnter the number of sides of your polygon: ");
        scanf("%d",&n);
        int i;
        for(i = 0;i<2*n;i+=2)
        {
            printf("\nEnter the coordinate number %d: x y = ",i+1);
            scanf("%d %d",&polyy[i],&polyy[i+1]);
        }
        polyy[i] = polyy[0];
        polyy[i+1] = polyy[1];

        setcolor(YELLOW);

        rectangle(xmin,ymax,xmax,ymin);
        char xy[50];
        sprintf(xy,"\t\t UNCLIPPED POLYGON");
        outtextxy(300,50,xy);


        setcolor(WHITE);
        fillpoly(n,polyy);
        getch();
        cleardevice();

        k = 0;
        for(i = 0;i<2*n;i+=2)
            clipLeft(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
        n = k/2;
        //copy latest veritces in polyy from arr
        for(i = 0;i<k;i++) polyy[i] = arr[i];
        polyy[i] = polyy[0];
        polyy[i+1] = polyy[1];

        k = 0;
        for(i = 0;i<2*n;i+=2)
            clipTop(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);

        n = k/2;
        //copy latest veritces in polyy from arr
        for(i = 0;i<k;i++) polyy[i] = arr[i];
        polyy[i] = polyy[0];
        polyy[i+1] = polyy[1];

        k = 0;
        for(i = 0;i<2*n;i+=2)
            clipRight(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);

        n = k/2;
        //copy latest veritces in polyy from arr
        for(i = 0;i<k;i++) polyy[i] = arr[i];
        polyy[i] = polyy[0];
        polyy[i+1] = polyy[1];

        k = 0;
        for(i = 0;i<2*n;i+=2)
            clipBottom(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);

        for(i = 0;i<k;i++)
            poly[i] = round(arr[i]);

        if(k)
            fillpoly(k/2,poly);
        setcolor(YELLOW);
        rectangle(xmin,ymax,xmax,ymin);
        xy[50];
        sprintf(xy,"\t\t CLIPPED POLYGON");
        outtextxy(300,50,xy);


        getch();
        closegraph();
        return 0;
    }

    /*Sample Input
    100 100
    400 400
    6
    50 160
    150 160
    200 60
    450 200
    150 460
    50 460
    */

