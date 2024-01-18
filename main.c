#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"

size_t WIDTH =  500;
size_t HEIGHT =  500;
typedef struct coordinate{
    size_t x;
    size_t y;
}COORD;

COORD * pattern(size_t stepsize){
    SetRandomSeed(GetTime());
    COORD * c = malloc(sizeof(COORD)*stepsize);
    c[0] =(COORD) {0,0};
    for (size_t i=1; i<stepsize; i++) {
        COORD n = c[i-1];
        int r = GetRandomValue(0,3);
        switch (r) {
            case 0:
                n.x+=1;
                break;
            case 1:
                n.x-=1;
                break;
            case 2:
                n.y+=1;
                break;
            case 3:
                n.y-=1;
                break;
        }
        c[i] = n;
    }
    return c;
}

int main(int argc, char *argv[])
{
    size_t num = 1000000;
    COORD* coord = pattern(num);
    //for (int i = 0;i<100;i++) {
    //    printf("%d %d\n",coord[i].x,coord[i].y);
    //}
    InitWindow(WIDTH, HEIGHT, "Pathfinder");
    while (!WindowShouldClose()) {
        BeginDrawing();
            Color color = { 51, 51, 51, 255};
            ClearBackground(color);
            for (size_t i = 0; i<num; i++) {
                COORD pt1 = coord[i];
                COORD pt2 = coord[i+1];
                DrawLine(WIDTH/2+5* pt1.x, HEIGHT/2+5*pt1.y, WIDTH/2+5*pt2.x, HEIGHT/2+5*pt2.y, WHITE);

            }
        EndDrawing();
    }
    CloseWindow();
}
