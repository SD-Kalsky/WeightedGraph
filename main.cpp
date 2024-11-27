
#include "weighted.h"
#include <iostream>
using namespace std;

int main() {
  Weighted w(6);
  w.print();
  w.add(3);
  w.print();
  w.add(3);
  w.print();
  w.add(7);
  w.print();
  w.pop();
  w.print();
  return 0;
}
