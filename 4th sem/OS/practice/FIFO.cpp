#include <bits/stdc++.h>
using namespace std;

int fifo(int pages[], int n, int frame){
    unordered_set<int> s;
    queue<int> indexes;

    int page_faults = 0;

    for(int i=0; i<n; i++){
        if(s.size() < frame){
            if(s.find(pages[i])==s.end()){
                s.insert(pages[i]);
                page_faults++;
                indexes.push(pages[i]);
            }
        }
        else{
            if(s.find(pages[i])==s.end()){
                int var = indexes.front();
                indexes.pop();
                s.erase(var);
                s.insert(pages[i]);
                indexes.push(pages[i]);
                page_faults++;
            }
        }
    }
    return page_faults;
}

int main(){
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int size = sizeof(pages)/sizeof(pages[0]);
    int frame = 4;
    cout << fifo(pages, size, frame) << endl;
    return 0;
}