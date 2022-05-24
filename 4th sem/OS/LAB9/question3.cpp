
// Optimal Page Replacement Algorithm - replaces the page that will not be used for the longest period of time in future.

#include <bits/stdc++.h>
using namespace std;

// Function to check whether a page exists in a frame or not
bool search(int key, vector<int>& frame)
{
	for (int i = 0; i < frame.size(); i++)
		if (frame[i] == key)
			return true;
	return false;
}

// Function to find the frame that will not be used
// recently in future after given index in pg[0..pn-1]
int predict(int pages[], vector<int>& frame, int page_size, int index)
{
	// Store the index of pages which are going to be used recently in future
	int res = -1, farthest = index;
	for (int i = 0; i < frame.size(); i++) {    // traverse in frame array
		int j;
		for (j = index; j < page_size; j++) {   // traverse in pages array
			if (frame[i] == pages[j]) {	// if same page found
				if (j > farthest) {     // compare new element with previous farthest ement
					farthest = j;       // if an element farther than other one,
					res = i;            // swap the element in both pages array & frames array
				}
				break;
			}
		}

		// If a page is never referenced in future,
		// return it.
		if (j == page_size)
			return i;
	}

	// If all of the frames were not in future,
	// return any of them, we return 0. Otherwise
	// we return res.
	return (res == -1) ? 0 : res;   // res = element in frame_array
}

void optimalPage(int pages[], int page_size, int frames)
{
	// array for given number of frames and initialize it as empty.
	vector<int> frame;

	// Traverse through page reference array and check for miss and hit.
	int hit = 0;
	for (int i = 0; i < page_size; i++) {

		// Page found in a frame : HIT
		if (search(pages[i], frame)) {
			hit++;
			continue;
		}

		// Page not found in a frame : MISS

		// If there is space available in frames.
		if (frame.size() < frames)     // if lesser than 3
			frame.push_back(pages[i]);

		// Find the page to be replaced.
		else {
			int j = predict(pages, frame, page_size, i + 1);    // returning element in frame array to be swapped
			frame[j] = pages[i];
		}
	}
	//cout << "No. of hits = " << hit << endl;
	cout << " Page Faults = " << page_size - hit << endl;
}


int main()
{
	int pages[] = { 3, 2, 1, 2, 3, 6, 4, 7, 2, 3, 4, 2, 1, 5, 7, 6, 2, 6, 2, 2, 3, 3 };
	int page_size = sizeof(pages) / sizeof(pages[0]);
	int frames = 3;
	optimalPage(pages, page_size, frames);
	return 0;
}
