#include <bits/stdc++.h>
using namespace std;

int solve(int i, int s, vector<int>& a, int S){
    
    if(s == S) return 1;        
    if(i == a.size() || s > S) return 0;

    int pick = solve(i+1, s + a[i], a, S);
    int notPick = solve(i+1, s, a, S);

    return pick + notPick;
}

int main(){

    vector<int> a = {1,2,3};
    int S = 3;

    cout << solve(0,0,a,S);
}
