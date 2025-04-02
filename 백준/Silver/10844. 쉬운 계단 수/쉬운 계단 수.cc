#include <iostream>

using namespace std;

static int dp[101][10];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][0] = dp[i - 1][1];
			}
			else if (j == 9) {
				dp[i][9] = dp[i - 1][8];
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			}
			dp[i][j] %= 1000000000;
		}
	}

	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		cnt = (cnt + dp[N][i]) % 1000000000;
	}
	cout << cnt;
}


