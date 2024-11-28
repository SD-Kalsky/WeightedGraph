#include "raylib.h"
#include <iostream>
#include <math.h>
#include "draw.h"
#include "weighted.h"
using namespace std;

#define screenWidth 900
#define screenHeight 600
#define TargetFPS 60

int main() {
  char *motherchar = new char[2];
  int x0 = 450, y0 = 150;
  PriorityQueue w(12);
  w.print();

  
  int i = 0, n=w.getSize();
  int *arr=w.getVertices();
  SetTargetFPS(TargetFPS);
  InitWindow(screenWidth, screenHeight, "Прога");
  while (!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(RAYWHITE);

    makeTree(x0, y0, n, motherchar, arr);

    EndDrawing();
  }
  CloseWindow();

  return 0;
}

