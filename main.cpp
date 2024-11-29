
#include "weighted.h"
#include <iostream>
using namespace std;

int main() {
  PriorityQueue w(6);
  w.add(3);
  w.add(7);
  w.print();
  w.sort();
  w.print();

  // Weighted w(5);
  // PriorityQueue pq=w.toPyramid();
  // pq.print();

  return 0;
}
