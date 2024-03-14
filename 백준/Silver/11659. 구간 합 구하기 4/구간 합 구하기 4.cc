#include <iostream>

using namespace std;

int s[100001] = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, m, data;
	cin >> n >> m;


	s[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> data;
		s[i] = s[i - 1] + data;
	}

	int left, right;
	for (int i = 0; i < m; i++) {
		cin >> left >> right;
		cout << s[right] - s[left-1] << "\n";
	}

}