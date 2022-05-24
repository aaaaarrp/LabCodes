
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int least_recently_used(vector<int>& pages, int frames) {
    unordered_map<int, int> indexes;
    unordered_set<int> set;

    int page_faults = 0;

    for (int i = 0; i < pages.size(); ++i) {
        if (set.size() < frames) {

            if (set.find(pages[i]) == set.end()) {
                set.insert(pages[i]);
                page_faults += 1;
            }

        } else {
            if (set.find(pages[i]) == set.end()) {
                int lru = INT32_MAX;
                int val;
                
                for (auto i: set) {
                    if (indexes[i] < lru) {
                        lru = indexes[i];
                        val = i;
                    }
                }

                set.erase(val);
                set.insert(pages[i]);

                page_faults += 1;
            }

        }

        indexes[pages[i]] = i;
    }


    return page_faults;
}

int main(void) {
    vector<int> pages = {2, 3, 4, 2, 1, 5, 7, 6, 2, 6, 3, 2, 1, 2, 3, 6, 4, 7 ,2, 2, 3, 3};

    int frames = 4;

    cout << "Page fault: " << least_recently_used(pages, frames) << endl;
}