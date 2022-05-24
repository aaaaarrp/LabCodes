#include <bits/stdc++.h>
using namespace std;

int lru(int pages[], int n, int frame){
    unordered_set<int> s;
    unordered_map<int, int> indexes;

    int page_faults = 0;

    for(int i=0; i<n; i++){
        if(s.size() < frame){
            if(s.find(pages[i])==s.end()){
                s.insert(pages[i]);
                page_faults++;
            }
        }
        else{
            if(s.find(pages[i])==s.end()){
                int lru = INT32_MAX;
                int val;
                for(auto i:s){
                    if(indexes[i] < lru){
                        lru = indexes[i];
                        val = i;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                page_faults++;
            }
        }
        indexes[pages[i]] = i;
    }
    return page_faults;
}

int main(){
    int pages[] = {2, 3, 4, 2, 1, 5, 7, 6, 2, 6, 3, 2, 1, 2, 3, 6, 4, 7 ,2, 2, 3, 3};
    int size = sizeof(pages)/sizeof(pages[0]);
    int frame = 4;
    cout << lru(pages, size, frame) << endl;
    return 0;
}