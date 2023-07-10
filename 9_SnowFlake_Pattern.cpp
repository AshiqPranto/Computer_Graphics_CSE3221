#include <graphics.h>
#include <math.h>

void drawKochCurve(int x1, int y1, int x2, int y2, int iteration) {
    if (iteration == 0) {
        line(x1, y1, x2, y2);
    }
    else {
        int deltaX = x2 - x1;
        int deltaY = y2 - y1;

        int xA = x1 + deltaX / 3;
        int yA = y1 + deltaY / 3;

        int xB = x1 + 2 * deltaX / 3;
        int yB = y1 + 2 * deltaY / 3;

        int xC = xA + (int)(cos(M_PI / 3) * (xB - xA)) - (int)(sin(M_PI / 3) * (yB - yA));
        int yC = yA + (int)(sin(M_PI / 3) * (xB - xA)) + (int)(cos(M_PI / 3) * (yB - yA));

        drawKochCurve(x1, y1, xA, yA, iteration - 1);
        drawKochCurve(xA, yA, xC, yC, iteration - 1);
        drawKochCurve(xC, yC, xB, yB, iteration - 1);
        drawKochCurve(xB, yB, x2, y2, iteration - 1);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    //int x1 = 100, y1 = 300;
    //int x2 = 500, y2 = 300;

    int iteration = 3;

    drawKochCurve(20, 280, 280, 280, iteration);
    drawKochCurve(280, 280, 150, 20, iteration);
    drawKochCurve(150, 20, 20,280, iteration);

    getch();
    closegraph();
    return 0;
}
