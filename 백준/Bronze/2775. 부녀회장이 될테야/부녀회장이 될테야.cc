// 2775 부녀회장이 될테야 (https://www.acmicpc.net/problem/2775)
#include <iostream>

using namespace std;

static int D[15][15];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, k, n;
	cin >> T;

	for (int i = 0; i < 15; i++) {
		D[i][1] = 1;
		D[0][i] = i;
	}

	for (int i = 1; i < 15; i++) { // 층
		for (int j = 2; j < 15; j++) { // 호수
			D[i][j] = D[i - 1][j] + D[i][j - 1]; // 점화식
		}
	}

	for (int i = 0; i < T; i++) {
		cin >> k >> n;
		cout << D[k][n] << "\n";
	}
}