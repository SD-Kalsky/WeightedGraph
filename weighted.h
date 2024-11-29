#include <iostream>
#include <queue>
#include <stack>
#include <time.h>

using namespace std;

queue<int> uniteQueue(queue<int> a, queue<int> b) {
  while (!b.empty()) {
    a.push(b.front());
    b.pop();
  }
  return a;
}


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



class PriorityQueue {
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
PriorityQueue() {
  size=3;
  init();
}
PriorityQueue(int n) {
  size=n;
  init();
}
~PriorityQueue(){
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
        if(a <= b) {
          m = a;
          a = b;
          b = m;
        }
        if(c <= a) {
          m = a;
          a = c;
          c = m;
        }
        if(a <= b) {
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
        if(a > b) {
          m = a;
          a = b;
          b = m;
        }
        if(c > b) {
          m = b;
          b = c;
          c = m;
        }
        if(a > b) {
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

void sort(){
  int *arr=new int[size];
  int i=0, n=size;
  while(i<n){
    arr[i]=this->getFirst();
    this->pop();
    i++;
  }
  delete vertices;
  vertices = nullptr;
  vertices=arr;
  size=n;
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

class Weighted{
private:
  int size;
  int **vertices;
  int *weights;
  void destroy() {
    int i = 0;
    while (i < size) {
      delete[] vertices[i];
      vertices[i] = nullptr;
      i++;
    }
    delete[] vertices;
    vertices = nullptr;
    delete[] weights;
    weights = nullptr;
  }
  void destroy_vertice(int i) {
    delete vertices[i];
    vertices[i] = nullptr;
  }
  void init() {
    int i = 0;
    vertices = new int *[size];
    weights = new int [size];
    while (i < size) {
      vertices[i] = new int[3];
      vertices[i][0] = 3;     // Bas massiv iene
      vertices[i][1] = i + 1; // Systar bas nyomere
      vertices[i][2] = i - 1; //
      weights[i]=i;
      i++;
    }
  }

public:
  Weighted() {
    size = 3;
    init();
    vertices[size - 1][1] = 0;
    vertices[0][2] = size - 1;
  }
  Weighted(int n) {
    size = n;
    init();
    vertices[size - 1][1] = 0;
    vertices[0][2] = size - 1;
  }
  int get_size(){
    return size;
  }
  int *get_vertice(int i){
    return vertices[i];
  }
  int get_weight(int i){
    return weights[i];
  }
  int **get_vertices(){
    return vertices;
  }
  void set_vertice(int i, int *v){
    vertices[i]=v;
  }
  void set_weight(int i, int w){
    weights[i]=w;
  }
  void set_vertices(int **v){
    vertices=v;
  }
  void printOLD() //
  {
    int i = 0;
    while (i < size) {
      cout << i << " -> ";
      int j = 1;
      while (vertices[i][0] > j) {
        cout << vertices[i][j] << ' ';
        j++;
      }
      cout << endl;
      i++;
    }
  }
  void randomize() {
    int i = 0, j, k, s, r;
    destroy();
    srand(time(0));
    vertices = new int *[size];
    while (i < size) {
      r = rand() % (size + 1 - i);
      vertices[i] = new int[r];
      vertices[i][0] = r;
      j = 1;
      while (j < r) {
        vertices[i][j] = j + i;
        j++;
      }
      i++;
    }
    k = size - 1;
    while (k > 0) {
      stack<int> q;

      i = 0;
      while (i < size) {
        j = 1;
        while (j < vertices[i][0]) {
          if (vertices[i][j] == k) {
            q.push(i);
            break;
          }
          j++;
        }
        i++;
      }
      int *newvertices = new int[q.size() + 1];
      newvertices[0] = q.size() + 1;
      s = 0;
      while (!q.empty()) {
        s++;
        newvertices[s] = q.top();
        q.pop();
      }
      delete[] vertices[k];
      vertices[k] = newvertices;
      k--;
    }
  }
  void def() {
    size = 8;
    init();
    delete[] vertices;
    vertices = new int *[7];
    vertices[0] = new int[2];
    vertices[0][0] = 2;
    vertices[0][1] = 2;
    vertices[1] = new int[4];
    vertices[1][0] = 4;
    vertices[1][1] = 5;
    vertices[1][2] = 6;
    vertices[1][3] = 7;
    vertices[2] = new int[4];
    vertices[2][0] = 4;
    vertices[2][1] = 0;
    vertices[2][2] = 3;
    vertices[2][3] = 4;
    vertices[3] = new int[3];
    vertices[3][0] = 3;
    vertices[3][1] = 2;
    vertices[3][2] = 5;
    vertices[4] = new int[3];
    vertices[4][0] = 3;
    vertices[4][1] = 2;
    vertices[4][2] = 7;
    vertices[5] = new int[3];
    vertices[5][0] = 3;
    vertices[5][1] = 1;
    vertices[5][2] = 3;
    vertices[6] = new int[3];
    vertices[6][0] = 3;
    vertices[6][1] = 1;
    vertices[6][2] = 2;
    vertices[7] = new int[3];
    vertices[7][0] = 3;
    vertices[7][1] = 1;
    vertices[7][2] = 4;
  }
  void BFS(int v) {
    int i = 0, j = 0, **a = new int *[size - 1], c=0;
    queue<int> q;
    bool *b = new bool[size - 1];
    while (i < size - 1) {
      b[i] = false;
      a[i] = new int[2];
      i++;
    }
    q.push(v);
    b[v] = true;
      while (!q.empty()) {
        i = 1;
        while (i < vertices[v][0]) {
          if (!b[vertices[v][i]]) {
            a[j][0] = v;
            a[j][1] = vertices[v][i];
            q.push(vertices[v][i]);
            b[vertices[v][i]] = true;
            c++;
            j++;
          }
          i++;
        }
        q.pop();
        v = q.front();
      }
      cout << endl << endl;
      i = 0;
      while (i < c) {
        cout << a[i][0] << ' ' << a[i][1] << endl;
        i++;
      }
  }
  

  int** iBFS(int v) {
    int i = 0, j = 0, **a = new int *[size - 1], c=0;
    queue<int> q;
    bool *b = new bool[size - 1];
    while (i < size - 1) {
      b[i] = false;
      a[i] = new int[2];
      i++;
    }
    q.push(v);
    b[v] = true;
    if (vertices[v][0]!=0)
      while (!q.empty()) {
        i = 1;
        while (i < vertices[v][0]) {
          if (!b[vertices[v][i]]) {
            a[j][0] = v;
            a[j][1] = vertices[v][i];
            q.push(vertices[v][i]);
            b[vertices[v][i]] = true;
            c++;
            j++;
          }
          i++;
        }
        q.pop();
        v = q.front();
      }
    else{
        printf("There is no way from this vertice");
        a=new int *[1];
        a[0]=new int[1];
        a[0][0]=0;
      }


    // int **newa=new int*[c];
    // i = 0;
    // while (i < c) {
    //   newa[i][0] = a[i][0];
    //   newa[i][1] = a[i][1];
    //   i++;
    // }

    return a;
  }


  void DFS(int v) {
    int i = 0, j = 0, **a = new int *[size - 1], c=0;
    stack<int> q;
    bool *b = new bool[size - 1];
    while (i < size - 1) {
      b[i] = false;
      a[i] = new int[2];
      i++;
    }
    q.push(v);
    b[v]=true;
    if (vertices[v][0]!=0)
    while (!q.empty()){
      i=0;
      while (vertices[v][0]>i){
        i++;

        if(!b[vertices[v][i]]){
          a[j][0]=v;
          v=vertices[v][i];
          a[j][1]=v;
          q.push(v);
          b[v]=true;
          i=0;
          c++;
          j++;
          };
        }
      q.pop();
      v=q.top();
    }
    j=0;
    while (j<c)
    {
      cout<<a[j][0]<<' '<<a[j][1]<<endl;
      j++;
    }
  }

  int** iDFS(int v) {
    int i = 0, j = 0, **a = new int *[size - 1];
    stack<int> q, q1;
    bool *b = new bool[size - 1];
    while (i < size - 1) {
      b[i] = false;
      a[i] = new int[2];
      i++;
    }
  q.push(v);
  q1.push(v);
  b[v]=true;
  if (vertices[v][0]!=0)
  while (!q.empty()){
    i=0;
    while (vertices[v][0]>i){
      i++;
      if(!b[vertices[v][i]]){
        a[j][0]=v;
        v=vertices[v][i];
        a[j][1]=v;
        q.push(v);
        b[v]=true;
        i=0;
        j++;
        };
      }
    q.pop();
    v=q.top();
  }
  else{
        printf("There is no way from this vertice");
        a=new int *[1];
        a[0]=new int[1];
        a[0][0]=0;
  }
  return a;
  }


  bool isThereWay(int a, int b) // Биирис өрүт иккискэ түhүү уhунун биэрэр
  {
    bool c{false};
    int j = 1;
    while (j < vertices[a][0]) {
      if (vertices[a][j] == b) {
        c = true;
        goto exit;
      }
      j++;
    }
    j = 1;
    while (j < vertices[a][0]) {

      if (isThereWay(vertices[a][j], b)) {
        c = true;
        goto exit;
      } else
        j++;
    }
  exit:
    return c;
  }
  void print()
  {
    int i=0, j;
    while(i<size)
    {
      cout<<i<<"-> ";
      j=1;
      switch (vertices[i][0])
      {
        case 0:
          cout<<"...";
          break;
        case 1:
          cout<<vertices[i][1];
          break;
        default:
          while(vertices[i][0]-1>j)
          {
            cout<<vertices[i][j]<<',';
            j++;
          }
          cout<<vertices[i][j];
          break;
      }
      
      cout<<endl;
      i++;
    }
  }
  PriorityQueue toPyramid(){
    PriorityQueue pq(0);
    int i=0;
    while(i<size){
      int j=1;
      int min;
      if(vertices[i][0]>1){
        min=1;
      while(j<vertices[i][0]){
        if(weights[vertices[i][j]]>weights[vertices[i][min]]) min=j;
        j++;
        }
        pq.add(j);
      }
       i++;
    }
   return pq;
  }
};