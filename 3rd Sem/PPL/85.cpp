#include<iostream>
#include<cmath>
using namespace std;

class Cartesian{
    float x,y;
    public:
    void read(){
        cout<<"Enter x coordinate:";
        cin>>x;
        cout<<"Enter y coordinate:";
        cin>>y;
        cout<<"\n";
    }
    friend void add(Cartesian, Cartesian);
    friend void sub(Cartesian, Cartesian);
    friend void angle(Cartesian, Cartesian);
    friend double mod(Cartesian);
    
};
     double mod(Cartesian p1)
     {
         return (sqrt(p1.x*p1.x+p1.y*p1.y));
     }

     void add(Cartesian p1,Cartesian p2)
    {   
        cout<<"\nx = "<<p1.x+p2.x;
        cout<<"\ny = "<<p1.y+p2.y<<"\n";

    }

     void sub(Cartesian p1,Cartesian p2)
    {   
        cout<<"\nx = "<<p1.x-p2.x;
        cout<<"\ny = "<<p1.y-p2.y<<"\n";

    }

    void angle(Cartesian p1,Cartesian p2)
    {
        cout<<acos((p1.x*p2.x+p1.y*p2.y)/(mod(p1)*mod(p2)));
    }

int main(){
    Cartesian p1,p2;
    cout<<"Enter Point 1:\n";
    p1.read();
    cout<<"Enter Point 2:\n";
    p2.read();
    cout<<"Sum of Point 1 and Point 2:";
    add(p1,p2);
    cout<<"\nDifference of Point 1 and Point 2:";
    sub(p1,p2);
    cout<<"\nAngle between Point 1 and Point 2:";
    angle(p1,p2);
    cout<<"\n";
    return 0;
}