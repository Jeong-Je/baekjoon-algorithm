// 1931

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, start, end, result=1;
	vector<pair<int, int>> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		v.push_back(make_pair(end, start));
	}

	sort(v.begin(), v.end());

	int time = v[0].first;
	for (int i = 1; i < n; i++) {
		if (time <= v[i].second) {
			result++;
			time = v[i].first;
		}
	}

	cout << result;

}