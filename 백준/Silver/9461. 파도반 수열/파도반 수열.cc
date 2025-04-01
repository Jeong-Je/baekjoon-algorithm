#include <iostream>

using namespace std;
using ll = long long;

static ll dp[101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    
    for(int i=6;i<=100;i++){
        dp[i] = dp[i-1] + dp[i-5];
    }
    
    int T;
    cin >> T;
    
    for(int i=0;i<T;i++){
        int P;
        cin >> P;
        cout << dp[P] << "\n";
    }
}