
// Time: O(N*W)

#include <bits/stdc++.h>
using namespace std;

int maximum(int a, int b){
    return (a > b) ? a : b;
}

int knapsack(int W, int val[], int wt[], int n){
    int i, w;
    vector<vector<int> > K(n+1, vector<int>(W+1));

    for(int i=0; i<=n; i++){
        for(int w=0; w<=W; w++){
            if(i == 0 || w == 0)
                K[i][w] = 0;
            else if(wt[i-1] <= w)
                K[i][w] = maximum(val[i-1]+K[i-1][w-wt[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    return K[n][W];
}

int main(){
    int W = 50;
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int n = sizeof(val)/sizeof(val[0]);
    cout << knapsack(W, val, wt, n) << endl;
    return 0;
}