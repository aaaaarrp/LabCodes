#include <iostream>
using namespace std;

struct date
{
    int date, year, month;
};

class Patient
{
  private:
    char name[50];
    date admis, disch;
    char disease[50];
    
  public:
    void enter()
    {
        cout<<"Enter name - \n";
        cin>>name;
        cout<<"Enter date of admission -\n";
        cin>>admis.date;
        cout<<"Enter month of admission -\n";
        cin>>admis.month;
        
        cout<<"Enter year of admission -\n";
        cin>>admis.year;
        
        cout<<"Enter date of discharge -\n";
        cin>>disch.date;
        cout<<"Enter month of discharge -\n";
        cin>>disch.month;
        
        cout<<"Enter year of discharge -\n";
        cin>>disch.year;
        cout<<"Enter disease - \n";
        cin>>disease;
    }
    
    void display()
    {
        cout<<"\nDetails\n";
        cout<<"Name - "<<name<<"\nDate of Admission - "<<admis.date<<"/"<<admis.month<<"/"<<admis.year<<"\nDate of discharge - "<<disch.date<<"/"<<disch.month<<"/"<<disch.year<<"\n";
        cout<<"Disease - "<<disease;
    }
};
int main() {
Patient P1;
P1.enter();
P1.display();
}