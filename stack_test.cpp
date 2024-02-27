#include "stack.h"
#include <iostream>

using namespace std;

int main() {
  Stack<int> s1;
  s1.push(1);
  s1.push(2);
  s1.push(3);
  cout << "Top: " << s1.top() << endl;
  cout << "Stack size: " << s1.size() << endl;
  s1.pop();
  cout << "Top after pop: " << s1.top() << endl;
  cout << "Stack size after pop: " << s1.size() << endl;
  s1.pop();
  s1.pop();
  cout << "Stack emptiness: " << boolalpha << s1.empty() << endl;

  // testing pop on empty stack
  try {
    s1.pop();
  } catch (const underflow_error& e) {
    cout << "Error: " << e.what() << endl;
  }

  return 0;
}