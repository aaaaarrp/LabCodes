#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare(Item& A, Item& B) {
    return (double) A.value / (double) A.weight > (double) B.value / (double) B.weight;
}

double fractol_knapsack(vector<Item>& items, int knapsack_capacity) {
    sort(items.begin(), items.end(), compare);
    double total = 0;
    
    cout << "/---------------------------\\" << endl;
    cout << "| Value | Weight | Quantity |" << endl;
    cout << "|---------------------------|" << endl;

    for (int i=0; i <items.size(); i++) {
        Item item = items[i];
        if (knapsack_capacity < item.weight) {
            total += (double) item.value * (double) knapsack_capacity / (double) item.weight;
            cout << "| " << setw(5) << item.value
                << " | " << setw(6) << item.weight
                << " | " << setw(8) << ((double) knapsack_capacity / (double) item.weight)
                << " |" << endl;

            break;
        } else {
            knapsack_capacity -= item.weight;
            total += item.value;
            cout << "| " << setw(5) << item.value
                << " | " << setw(6) << item.weight
                << " | " << setw(8) << 1
                << " |" << endl;;
        }
    }
    
    cout << "\\---------------------------/" << endl;
    return total;
}

void get_input(vector<Item>& items, int& knapsack_capacity) {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << endl;
    items.clear();

    items = {};

    for (int i = 0; i < n; ++i) {
        Item item;
        cout << "Index " << i << endl;
        cout << "Enter the weight: ";
        cin >> item.weight;

        cout << "Enter the value: ";
        cin >> item.value;
        items.push_back(item);
        cout << endl;
    }

    cout << "Enter the capacity of knapsack: ";
    cin >> knapsack_capacity;
    cout << endl;
}

int main(void) {
    int knapsack_capacity = 5;
    vector<Item> items = { {12, 2},
                           {10, 1},
                           {20, 3},
                           {15, 2} };

    //get_input(items, knapsack_capacity);

    int maximum = fractol_knapsack(items, knapsack_capacity);

    cout << endl;
    cout << "Maximum: " << maximum << endl;
    cout << endl;
    return 0;
}