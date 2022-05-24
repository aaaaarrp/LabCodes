/*
-> Calculate ratio value/weight for each item
-> sort the item on the basis of this ratio
-> Then take the item with the highest ratio
-> and add them until we can’t add the next item as a whole 
-> and at the end add the next item as much as we can.
-> Time: O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value, weight;
    Item(int value, int weight){
        this->value = value;
        this->weight = weight;
    }
};

bool comp(struct Item a, struct Item b){
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int w, struct Item arr[], int n){
    sort(arr, arr+n, comp);
    int curWeight = 0;
    double finalvalue = 0.0;

    for(int i; i<n; i++){
        if(curWeight+arr[i].weight <= w){
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }
        else{
            int remain = w - curWeight;
            finalvalue += arr[i].value * ((double)remain/(double)arr[i].weight);
        }
    }
    return finalvalue;
}

int main(){
    int W = 50;
    Item arr[] = {{60,10}, {100,20}, {120,30}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << fractionalKnapsack(W, arr, n) << endl;

    return 0;
}