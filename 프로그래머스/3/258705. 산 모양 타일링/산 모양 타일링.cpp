#include <string>
#include <vector>
#define MOD 10007
using namespace std;

long long dp[100001][2];

int solution(int n, vector<int> tops) {
    int answer = 0;

    dp[0][0] = 1; // 아무것도 안 놓은 상태
    dp[0][1] = 0; // 열린 상태는 없음

    if (tops[0] == 1) {
        dp[1][1] = 4 % MOD;
    } else {
        dp[1][0] = 3 % MOD;
    }

    for (int i = 2; i <= n; i++) {
        if (tops[i-1] == 1) {
            dp[i][1] = ( (4 * (dp[i-1][1] + dp[i-1][0])) % MOD 
                        - (dp[i-2][1] + dp[i-2][0]) % MOD + MOD ) % MOD;
        } else {
            dp[i][0] = ( (3 * (dp[i-1][1] + dp[i-1][0])) % MOD 
                        - (dp[i-2][1] + dp[i-2][0]) % MOD + MOD ) % MOD;
        }
    }

    answer = (dp[n][0] + dp[n][1]) % MOD;
    return answer;
}
