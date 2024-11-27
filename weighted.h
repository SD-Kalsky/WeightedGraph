#include <iostream>
#include <queue>
#include <stack>
#include <time.h>

using namespace std;

// 1.  Реализуйте очередь по приоритетам на основе пирамиды (слабо упорядоченного массива):
// - добавление элемента
// - обращение к максимальному/минимальному элементу
// - удаление максимального/минимального элемента
// - вспомогательная функция – вывод пирамиды
// 2. Реализуйте пирамидальную сортировку массива:
// - добавить все элементы массива в пирамиду
// - извлечение и удаление максимального/минимального элемента пока пирамида не опустеет
// 3. Реализуйте алгоритм Крускала или алгоритм Прима для построения каркаса взвешенного графа с использованием пирамиды:
// - добавление ребер в пирамиду
// - извлечение и удаление ребер с минимальным весом



class Weighted {
private:
  bool type=true; //Кирдик махсын эрдин
  int size;
  int *vertices;
  void destroy() {
    delete[] vertices;
    vertices = nullptr;
  }
  void init() {
    int i = 0;
    vertices = new int[size];
    while (i < size) {
      vertices[i] = size-i-1;
      i++;
    }
    this->order();
  }

public: 
Weighted() {
  size=3;
  init();
}
Weighted(int n) {
  size=n;
  init();
}
~Weighted(){
  destroy();
}
void print(){
  int i=0;
  while(i<size-1){
    cout<<vertices[i]<<' ';
    i++;
  }
  cout<<vertices[i]<<endl;
}
void order(){
  int i=size-1;
  int a, b, c, m;
  if(type)
    while((i-2)/2>=0){
      if(i%2==0){    
        a=vertices[i-1];
        b=vertices[i];
        c=vertices[(i-2)/2];
        if(b <= a) {
          m = a;
          a = b;
          b = m;
        }
        if(c <= b) {
          m = b;
          b = c;
          c = m;
        }
        if(b <= a) {
          m = a;
          a = b;
          b = m;
        }
        vertices[i-1]=a;
        vertices[i]=b;
        vertices[(i-2)/2]=c;
        i-=2;
      }
      else{
        b=vertices[i];
        c=vertices[(i-2)/2];
        if(c <= b) {
          m = b;
          b = c;
          c = m;
        }
        vertices[i]=b;
        vertices[(i-2)/2]=c;
        i-=1;
      }
    }
    else
      while((i-2)/2>=0){
      if(i%2==0){    
        a=vertices[i-1];
        b=vertices[i];
        c=vertices[(i-2)/2];
        if(b > a) {
          m = a;
          a = b;
          b = m;
        }
        if(c > b) {
          m = b;
          b = c;
          c = m;
        }
        if(b > a) {
          m = a;
          a = b;
          b = m;
        }
        vertices[i-1]=a;
        vertices[i]=b;
        vertices[(i-2)/2]=c;
        i-=2;
      }
      else{
        b=vertices[i];
        c=vertices[(i-2)/2];
        if(c > b) {
          m = b;
          b = c;
          c = m;
        }
        vertices[i]=b;
        vertices[(i-2)/2]=c;
        i-=1;
      }
    }
}

void setType(bool b){
  type=b;
}
void add(int a) {
  size++;
  int* newvertices=new int[size];
  int i=0;
  while(i<size-1){
    newvertices[i]=vertices[i];
    i++;
  }
  newvertices[i]=a;
  destroy();
  vertices=newvertices;
  this->order();
}
void pop(){
  size--;
  int* newvertices=new int[size];
  int i=1;
  while(i<size+1){
    newvertices[i-1]=vertices[i];
    i++;
  }
  destroy();
  vertices=newvertices;
  this->order();
}
int getFirst(){
  return vertices[0];
}
int getSize(){
  return size;
}
int* getVertices(){
  return vertices;
}
void setVertices(int* arr){
  destroy();
  vertices=arr;
}
};
