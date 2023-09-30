// 1377

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a.begin(), a.end());

	int result = 0;
	for (int i = 0; i < n; i++) {
		if (result < a[i].second - i) // 정렬 전 index - 정렬 후 index
			result = a[i].second - i;
	}

	cout << result + 1;
	return 0;
}