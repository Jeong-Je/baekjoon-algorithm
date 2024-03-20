#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	long count = 0;	
	cin >> n >> m;

	vector<long> a(n + 1, 0);
	vector<long> s(n + 1, 0);
	vector<long> c(m, 0);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		int temp = s[i] % m;
		if (temp == 0) {
			count++;
		}
		c[temp]++;
	}


	for (int i = 0; i < m; i++) {
		if (c[i] > 1) {
			count += (c[i] * (c[i]-1) / 2);
		}
	}

	cout << count;
}