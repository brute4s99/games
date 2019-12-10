// fidget spinner made on BGI that starts at specified speed and slows down @ 40 degree/sec !
#include <iostream.h>
#include <stdio.h>
#include <dos.h>
#include <math.h>
#include <conio.h>
#include <graphics.h>
#define pi 22 / 7.0

// Prototypes
void drawing(float a);
void naming();
void lineangle(int x, int y, float angle, int l);

// Main program
void main()
{
    clrscr();
    float x;
    int gd = DETECT, gm;
    cout << "enter the speed of fidget spinner (rounds/sec) : ";
    cin >> x;
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
    float av = x * 3.6;

    //FOR BETTER REALISM -- FRICTION
    //for(int i=0;av<x*3.6;i+=(av+=0.5))  // angular acceleration = 0.5 degree/sec^2
    //{drawing(i%360);
    //delay(10);
    //cleardevice();}
    //for(i;i<x*360;i+=av)	// rotate at the angular velocity for some rounds
    //{drawing(i%360);
    //delay(10);
    //cleardevice();}
    outtextxy(100, 100, "Press any key to spin !");
    getch();
    for (long int i = 0; av > 0; i += (av -= 0.4)) {
        drawing(i % 360);
        //char msg[100];
        //sprintf(msg,"ANGULAR VELOCITY %f",av*100.0);
        //outtextxy(440,320,msg);
        //outtextxy(500,330,"Rad/SEC");
        delay(5);
        //getch();
        cleardevice();
    }
    drawing(i % 360);
    setcolor(WHITE);
    char msg[30];
    sprintf(msg, "Rounds Completed : %d", i / 360);
    outtextxy(330, 20, msg);
    sprintf(msg, "Time : %f", i * 5.0 / 1000);
    outtextxy(320, 40, msg);
    outtextxy(450, 40, "seconds");
    getch();
    closegraph();
    //cout<<"Rounds Covered : "<<i/360<<"\nTime Of Rotation : "<<i*5.0/1000<<" seconds";
    //getch();
}
void drawing(float theta)
{
    float a = theta * 22 / 7.0 / 180;
    setcolor(12);
    setfillstyle(1, 12);
    // main wheels
    for (int i = 35; i < 50; i++) {
        circle(getmaxx() / 2 + 100 * cos(a + pi / 2),
            getmaxy() / 2 - 100 * sin(a + pi / 2), i);
        circle(getmaxx() / 2 + 100 * cos(-pi / 6 + a),
            getmaxy() / 2 - 100 * sin(-pi / 6 + a), i);
        circle(getmaxx() / 2 + 100 * cos(pi + pi / 6 + a),
            getmaxy() / 2 - 100 * sin(pi + pi / 6 + a), i);
    }
    // inner wheels
    for (i = 0; i < 24; i++) {
        circle(getmaxx() / 2, getmaxy() / 2, i / 5 + 11);
        circle(getmaxx() / 2 + 100 * cos(a + pi / 2), getmaxy() / 2 - 100 * sin(pi / 2 + a), i);
        circle(getmaxx() / 2 + 100 * cos(-pi / 6 + a), getmaxy() / 2 - 100 * sin(-pi / 6 + a), i);
        circle(getmaxx() / 2 + 100 * cos(pi + pi / 6 + a), getmaxy() / 2 - 100 * sin(pi + pi / 6 + a), i);
    }

    // border completion
    arc(getmaxx() / 2 + 80 * cos(a - pi / 2), getmaxy() / 2 - 80 * sin(a - pi / 2),
        (theta + 90) - 155 / 2.0, (theta + 90) + 145 / 2.0, 42);
    arc(getmaxx() / 2 + 80 * cos(a + pi / 6), getmaxy() / 2 - 80 * sin(a + pi / 6),
        theta + 120 + 90 - 155 / 2.0, theta + 120 + 90 + 145 / 2.0, 42);
    arc(getmaxx() / 2 + 80 * cos(a + pi - pi / 6), getmaxy() / 2 - 80 * sin(a + pi - pi / 6),
        theta + 240 + 90 - 155 / 2.0, theta + 240 + 90 + 145 / 2.0, 42);

    // filling areas of border
    arc(getmaxx() / 2, getmaxy() / 2, theta + 90 - 85 / 2.0, theta + 90 + 85 / 2.0, 42);
    floodfill(getmaxx() / 2 + 45 * cos(pi / 2 + a), getmaxy() / 2 - 45 * sin(pi / 2 + a), 12);
    arc(getmaxx() / 2, getmaxy() / 2, theta + 120 + 90 - 85 / 2.0, theta + 120 + 90 + 85 / 2.0, 42);
    floodfill(getmaxx() / 2 + 45 * cos(pi + pi / 6 + a), getmaxy() / 2 - 45 * sin(pi + pi / 6 + a), 12);
    arc(getmaxx() / 2, getmaxy() / 2, theta + 240 + 90 - 85 / 2.0, theta + 240 + 90 + 85 / 2.0, 42);
    floodfill(getmaxx() / 2 + 45 * cos(-pi / 6 + a), getmaxy() / 2 - 45 * sin(-pi / 6 + a), 12);

    // connections                        // for every 3 lines
    for (i = 0; i < 3; i++)
        for (int j = -1; j < 2; j++) // for every line
            for (int k = -3; k < 4; k++) { // for every strand
                lineangle(getmaxx() / 2 + 100 * cos(a + pi / 2), getmaxy() / 2 - 100 * sin(pi / 2 + a),
			  theta + 90 + 120 * i + k + 10 * j, 49);
                lineangle(getmaxx() / 2 + 100 * cos(a - pi / 6), getmaxy() / 2 - 100 * sin(a - pi / 6),
			  theta + 90 + 120 * i + k + 10 * j, 49);
                lineangle(getmaxx() / 2 + 100 * cos(pi + pi / 6 + a), getmaxy() / 2 - 100 * sin(a + pi + pi / 6),
			  theta + 90 + 120 * i + k + 10 * j, 49);
            }
}

void naming()
{
    settextstyle(4, 0, 4);
    outtextxy(50, 16, "Piyush Aggarwal");
    settextstyle(7, 0, 3);
    outtextxy(50, 57, "06914802716");
    outtextxy(450, 40, "2 August 2017");
}
void lineangle(int x, int y, float angle, int l)
{
    angle = angle * (22 / 7.0) / 180;
    line(x, y, x + l * cos(angle), y - l * sin(angle));
}
