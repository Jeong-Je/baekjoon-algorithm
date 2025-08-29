#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int a[1001][1001];
int dp[1001][1001];
int leftdp[1001], rightdp[1001];

int main() {
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> a[i][j];
        }
    }

    // 첫 번째 행은 단순 누적
    dp[1][1] = a[1][1];
    for (int j=2; j<=M; j++) dp[1][j] = dp[1][j-1] + a[1][j];

    // 두 번째 행부터
    for (int i=2; i<=N; i++) {
        // 왼쪽 -> 오른쪽
        leftdp[1] = dp[i-1][1] + a[i][1];
        for (int j=2; j<=M; j++) {
            leftdp[j] = max(leftdp[j-1], dp[i-1][j]) + a[i][j];
        }

        // 오른쪽 -> 왼쪽
        rightdp[M] = dp[i-1][M] + a[i][M];
        for (int j=M-1; j>=1; j--) {
            rightdp[j] = max(rightdp[j+1], dp[i-1][j]) + a[i][j];
        }

        // 합치기
        for (int j=1; j<=M; j++) {
            dp[i][j] = max(leftdp[j], rightdp[j]);
        }
    }

    cout << dp[N][M];
}
