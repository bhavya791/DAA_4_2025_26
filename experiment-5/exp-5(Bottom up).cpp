#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={1,2,3};
    int S=3;
    
    int n=arr.size();
    
    vector<vector<int>> dp(n+1, vector<int>(S+1,0));

    dp[0][0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=S;j++){
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    cout<<dp[n][S];
}
