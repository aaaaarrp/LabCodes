#include<iostream>
#include<cmath>
using namespace std;

class Polar{
    float radius,theta;
    public:
    void read(){
        cout<<"Enter radius:";
        cin>>radius;
        cout<<"Enter theta:";
        cin>>theta;
        cout<<"\n";
    }  
friend void add(Polar,Polar);
friend void sub(Polar,Polar);
friend void angle(Polar,Polar); 
};

 void add(Polar p1,Polar p2)
    {   
        float x1 = p1.radius* cos(p1.theta);
        float y1 = p1.radius* sin(p1.theta);

        float x2 = p2.radius* cos(p2.theta);
        float y2 = p2.radius* sin(p2.theta);

        float x3 = x1+x2;
        float y3 = y1+y2;

        cout<<"\nradius = "<<sqrt(x3*x3+y3*y3);
        cout<<"\ntheta = "<<atan(y3/x3)<<"\n";
    }

  void angle(Polar p1,Polar p2)
    {
            cout<<abs(p1.theta-p2.theta);
    }

  void sub(Polar p1,Polar p2)
    {   
        float x1 = p1.radius* cos(p1.theta);
        float y1 = p1.radius* sin(p1.theta);

        float x2 = p2.radius* cos(p2.theta);
        float y2 = p2.radius* sin(p2.theta);

        float x3 = x1-x2;
        float y3 = y1-y2;

        cout<<"\nradius = "<<sqrt(x3*x3+y3*y3);
        cout<<"\ntheta = "<<atan(y3/x3)<<"\n";
    }

int main(){
    Polar p1,p2;
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