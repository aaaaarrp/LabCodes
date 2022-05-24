

// A dynamic programming based solution for 0-1 Knapsack problem : Time O(N*W) : Space O(N*W)

#include <bits/stdc++.h>
using namespace std;

int maximum(int a, int b){
    return (a > b) ? a : b ;
}
// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapsack(int value[], int weight[], int W, int n){
    int i, w;
    vector<vector<int> > K (n+1, vector<int>(W+1));

    for(i = 0; i <= n; i++){
        for(w = 0; w <= W; w++){
            if(i == 0 || w == 0)
                K[i][w] = 0;
            else if(weight[i-1] <= w)
                K[i][w] = maximum(value[i-1]+K[i-1][w-weight[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];   
        }
    }
    return K[n][W];
}


int main(){
    int value[] = { 60, 100, 120};
    int weight[] = { 10, 20, 30}; 
    int w = 50;
    int size = sizeof(value)/sizeof(value[0]);
    cout << knapsack(value, weight, w, size);
}