// Better Solution - https://www.geeksforgeeks.org/implementation-of-file-allocation-methods-using-vectors/

#include <bits/stdc++.h>
using namespace std;

int disk[50];

int blocksize = 4;

//enum{factorial,calculate,simpleinterest};

//string arr[3] = {"factorial","calculate","simple interest"};

class File{
    public:
        string name;
        int start;
        int end;
        int size;

    File(string name,int start,int end,int size){
        this->name = name;
        this->start = start;
        this->end = end;
        this->size = size;
    }
};

void allocation(File a){
    int numblocks = ceil(a.size/blocksize);
    disk[a.end] = INT_MAX;
    int currblock = a.start;
    int nextblock;
    for(int i=1;i<=numblocks - 1;i++){
        bool flag = false;
        while(!flag){
            int num = rand()%50;
            if(disk[num]==-1 && num!=currblock){
               nextblock = num;
               //cout<<num<<" ";
               disk[currblock] = nextblock;
               currblock = nextblock;
               flag = true;
           }
        }
    }
    disk[currblock] = a.end;


    cout<<endl;
}

void showblocks(File a){
    cout<<a.name<<":"<<endl;
    int currblock = a.start;
    while(currblock!=INT_MAX){
        cout<<currblock<<" ";
        currblock = disk[currblock];
    }
    cout<<endl<<endl;
}

int main()
{

    vector<File> directory;
    File temp1 = File("factorial",12,46,9);
    directory.push_back(temp1);

    File temp2 = File("calculate",5,36,38);
    directory.push_back(temp2);

    File temp3 = File("simpleinterest",8,23,25);
    directory.push_back(temp3);

    for(int i=0;i<50;i++){
        disk[i] = -1;
    }

    for(int i = 0;i<3;i++){
        allocation(directory[i]);
    }

    for(int i = 0;i<3;i++){
        showblocks(directory[i]);
    }




    return 0;
}