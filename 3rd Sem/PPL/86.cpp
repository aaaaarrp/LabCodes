#include <iostream>
#include<string>
using namespace std;


class ChangeNum
{
  private:
    int a, b;
  public:
    
    ChangeNum()
    {
        a = 0;
        b = 0;
    }
    
    void display()
    {
        cout<<"a = "<<a<<endl<<"b = "<<b;
    }
    
    ~ChangeNum()
    {
        a = 100;
        b = 100;
        cout<<"\nAfter destructor function - a = "<<a<<" || b = "<<b;
    }
    
    
};
int main() {
    ChangeNum a;
    a.display();
   return 0;
}