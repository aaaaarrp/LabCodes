#include <iostream>
#include<string>
using namespace std;


class Inventory
{
  private:
    int prodID, qtyinStock;
    string description;
  public:
    
    Inventory(int ID = 100, int q = 1000, string s = "important product")
    {
        prodID = ID;
        description=s;
        qtyinStock=q;
    }
    
    int remove(int tbr)
    {
        if(tbr<=qtyinStock)
        {    qtyinStock-=tbr;
            return qtyinStock;
        }
        else
         return -1;
    }
    
    
    
};
int main() {

    Inventory i1(120,1500,"used in cleaning");
    cout<<i1.remove(100);
    cout<<endl;
    cout<<i1.remove(5000);
    
}