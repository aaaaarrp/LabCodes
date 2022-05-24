
#include <iostream>
using namespace std;

// Base class (parent)
class MyClass {
  public:
    void myFunction() {
      cout << "This is my classes."<<endl;
    }
};

// Derived class (child)
class MyChild: public MyClass {
};

// Derived class (grandchild)
class MyGrandChild: public MyChild {
};

int main() {
  MyGrandChild myObj;
  myObj.myFunction();
  return 0;
}
