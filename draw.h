#include "raylib.h"
#include <iostream>
#include <math.h>
using namespace std;

void makeVertice(int x0, int y0, int x, int y, char *c);
char *toChar(char *t, int n);
void makeVertices(int x0, int y0, int n, char *c);
void makeLine(int x0, int y0, int n, int a, int b);
void makeLines(int x0, int y0, int n, int **a);
void makeConnections(int x0, int y0, int n, int **a);

void makeVertice(int x, int y, char *c) {

  DrawText(c, x - 2, y - 18, 14, BLACK);
  DrawCircle(x, y, 5, MAROON);
}

void makeVertices(int x0, int y0, int n, char *motherchar) {
  int i = 0;
  while (i < n) {
    makeVertice(x0 + sin(6.28 / n * i) * 100, y0 + cos(6.28 / n * i) * 100,
                toChar(motherchar, i));
    i++;
  }
}

void makeTree(int x, int y, int n, char *motherchar, int *arr){
  int i, j, k, c=0, d=0, m=1;
  int  x0=x, y0=y, ox;
  if(n%2==1) k=(n-1)/2;
  else k=n/2;
  i=0; j=0;
  int dx=k*36, dy=36;
  while (i<n) {
    if(m==i){
      ox=x;
      x=x0 - (dx * m/4);
      m *= 2; 
      m++;
      j=0;
      c=0;
      d=0;
      dx/=2;
      y += dy;
      }
    makeVertice(x+dx*c, y, toChar(motherchar, arr[i]));
    if(i>0){
      if(j==2){
      d++;
      j=0;
      }
      DrawLine(ox+dx*2*d, y-dy, x+dx*c, y, BLACK);
      j++;
    }
    i++;
    c++;
    
  }
}

void makeTree2(int x, int y, int n, char *motherchar, int *arr){
  int i, j, k, c=0, d=0, m=1;
  int  x0=x, y0=y, oy;

  if(n%2==1) k=(n-1)/2;
  else k=n/2;
  i=0; j=0;

  int dy=k*36, dx=36;
  while (i<n) {
    if(m==i){
      oy=y;
      y=y0 + (dy * m/4);
      m *= 2; 
      m++;
      j=0;
      c=0;
      d=0;
      dy/=2;
      x += dx;
      }
    makeVertice(x, y-dy*c, toChar(motherchar, arr[i]));
    if(i>0){
      if(j==2){
      d++;
      j=0;
      }
      DrawLine(x-dx, oy-dy*2*d, x, y-dy*c, BLACK);
      j++;
    }
    i++;
    c++;
    
  }
}



void makeLine(int x0, int y0, int n, int a, int b) {
  int i = 0;
  DrawLine(x0 + sin(6.28 / n * a) * 100, y0 + cos(6.28 / n * a) * 100,
        x0 + sin(6.28 / n * b) * 100, y0 + cos(6.28 / n * b) * 100, BLACK);

}

void makeLines(int x0, int y0, int n, int **a) {
  int i = 0;
  while (i < n-1) {
    makeLine(x0, y0, n,a[i][0],a[i][1]);
    i++;
  }
}

void makeConnections(int x0, int y0, int n, int **a) {
  int i = 0, j;
  while (i < n) {
    j=1;
  while (j < a[i][0]) {
    DrawLine(x0 + sin(6.28 / n * i) * 100, y0 + cos(6.28 / n * i) * 100,
      x0 + sin(6.28 / n * a[i][j]) * 100, y0 + cos(6.28 / n * a[i][j]) * 100, BLACK);
      j++;
  }
  i++;
  }
}

char *toChar(char *c, int n) {
  c[0] = '0';
  if (n >= 0 and n < 10) {
    c[0] = 48 + n;
    c[1] = ' ';
    c[2] = ' ';
    c[3] = ' ';
    c[4] = ' ';
    c[5] = ' ';
  } else if (n > 9 and n < 100) {
    c[0] = 48 + n / 10;
    c[1] = 48 + n % 10;
    c[2] = ' ';
    c[3] = ' ';
    c[4] = ' ';
    c[5] = ' ';
  }
  return c;
}

void drawGraphs(int x0, int y0, int n, char* motherchar, int** a, int** b, int** c)
{
    makeVertices(x0, y0, n, motherchar);
    makeConnections(x0, y0, n, a);
    makeVertices(x0+300, y0, n, motherchar);
    makeLines(x0+300, y0, n, b);
    makeVertices(x0+600, y0, n, motherchar);
    makeLines(x0+600, y0, n, c);
}