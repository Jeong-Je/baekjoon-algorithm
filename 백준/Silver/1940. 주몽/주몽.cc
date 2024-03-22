#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int start = 0, end = n - 1;
	int sum;
	int count = 0;

	while (start < end) {
		sum = v[start] + v[end];
		if (sum == m) {
			count++;
			start++; end--;
		}
		else if (sum < m) {
			start++;
		}
		else {
			end--;
		}
	}

	cout << count;

}