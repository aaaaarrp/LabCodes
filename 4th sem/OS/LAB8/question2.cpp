
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int first_in_first_out(vector<int>& pages, int frames) {
    queue<int> indexes;
    unordered_set<int> set;

    int page_faults = 0;

    for (int i = 0; i < pages.size(); ++i) {
        if (set.size() < frames) {
            if (set.find(pages[i]) != set.end()) continue;
            set.insert(pages[i]);
            page_faults += 1;

            indexes.push(pages[i]);
        } else {
            if (set.find(pages[i]) != set.end()) continue;

            int val = indexes.front();
            indexes.pop();

            set.erase(val);
            set.insert(pages[i]);

            indexes.push(pages[i]);
            page_faults += 1;
        }
    }


    return page_faults;
}

int main(void) {
    vector<int> pages = {4, 7, 2, 0, 1, 3, 2, 3, 4, 2, 1, 5, 7, 6, 2, 6, 3, 2, 1, 2, 3, 6};

    int frames = 4;

    cout << "Page fault: " << first_in_first_out(pages, frames) << endl;
}