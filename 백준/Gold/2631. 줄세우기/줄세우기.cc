#include <iostream>

using namespace std;

int arr[201];
int dp[201];

int main(){
    int N;
    cin >> N;
    
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    
    
    for(int i=1;i<=N;i++){
        dp[i] = 1;
        for(int j=1;j<i;j++){
            if(arr[i] > arr[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    
    
	int maxN = 0;
	for (int i = 1; i <= N; i++) {
		if (dp[i] > maxN) maxN = dp[i];
	}
	
	
	cout << N - maxN;
    
}