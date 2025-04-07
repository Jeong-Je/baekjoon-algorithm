#include <iostream>
#include <algorithm>

using namespace std;

static int dp[101][100001];
static int W[101];
static int V[101];

int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}

	for (int limit = 1; limit <= K; limit++) {
		for (int j = 1; j <= N; j++) {
			if (W[j] > limit) { // 담을 수 없는 경우
				dp[j][limit] = dp[j-1][limit];
			}
			else { // 담을 수 있는 경우
				dp[j][limit] = max(dp[j - 1][limit], dp[j - 1][limit - W[j]] + V[j]);
			}
		}
	}

	cout << dp[N][K];
}