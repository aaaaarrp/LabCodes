#include<iostream>
using namespace std;

class s
{
    private:
        int n1, n2;
    public:
        void insert(int a, int b)
        {
            n1=a;
            n2=b;
        }
        
        void swap()
        {
            int temp;
            temp = n1;
            n1=n2;
            n2=temp;
        }
        
        void display()
        {
            cout<<"n1 = "<<n1<<endl;
            cout<<"n2 = "<<n2<<endl;
            
        }
};
int main()
{
    s s1;
    s1.insert(2,8);
    s1.display();
    s1.swap();
    cout<<"AFter swapping:\n";
    s1.display();
    return 0;
}