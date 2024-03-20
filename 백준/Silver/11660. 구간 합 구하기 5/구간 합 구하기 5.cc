#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> matrix(n+1, vector<int>(n+1,0));
	vector<vector<int>> prefixSum(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> matrix[i][j];
			prefixSum[i][j] = prefixSum[i][j - 1] + prefixSum[i - 1][j] - prefixSum[i - 1][j - 1] + matrix[i][j];
		}
	}


	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << prefixSum[x2][y2] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1] + prefixSum[x1 - 1][y1 - 1]<<"\n";
	}
}