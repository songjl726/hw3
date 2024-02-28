#include "heap.h"
#include <string>
#include <iostream>

using namespace std;

int main(){
  // int heap (default min comp)
  Heap<int> h1;
  h1.push(5);
  h1.push(4);
  h1.push(9);
  h1.push(2);
  h1.push(7);
  while (!h1.empty()){
    cout << h1.top() << " ";
    h1.pop();
  }
  cout << endl;

  // trying to pop an empty heap
  try {
    h1.pop();
  } catch (const out_of_range& e) {
    cout << "Error: " << e.what() << endl;
  }

  // trying to top an empty heap (0-0)
  try {
    h1.top();
  } catch (const out_of_range& e) {
    cout << "Error: " << e.what() << endl;
  }

  // double heap (max comp)
  Heap<double, std::greater<int>> h2;
  h2.push(5.4);
  h2.push(3.1);
  h2.push(0.8);
  h2.push(2.2);
  h2.push(12.9);
  h2.push(7.0);
  while (!h2.empty()){
    cout << h2.top() << " ";
    h2.pop();
  }
  cout << endl;

  // string heap (min comp)
  Heap<string> h3;
  h3.push("carrot");
  h3.push("cucumber");
  h3.push("arugula");
  h3.push("zucchini");
  h3.push("tomato");
  while (!h3.empty()){
    cout << h3.top() << " ";
    h3.pop();
  }
  cout << endl;

  return 0;
}