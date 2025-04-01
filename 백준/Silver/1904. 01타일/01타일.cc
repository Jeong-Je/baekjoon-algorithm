#include <iostream>

using namespace std;

using ll = long long;

static ll dp[1000001];

int main(){
    int N;
    cin >> N;
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    
    
    for(int i=3;i<=N;i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }
    
    cout << dp[N];
    
}