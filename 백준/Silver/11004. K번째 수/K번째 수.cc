// 11004
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k,data;
	cin >> n >> k;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> data;
		v.push_back(data);
	}
	sort(v.begin(), v.end());

	cout << v.at(k-1);
	return 0;
}