#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++) {
		int s1, s2, e1, e2;
		cin >> s1 >> s2 >> e1 >> e2;
		v[i] = { s1 * 100 + s2, e1 * 100 + e2 };
	}

	sort(v.begin(), v.end()); // 시작일이 빠른 순으로 정렬

	int count = 0;
	int cur = 301;
	int end = 0;
	
	int i = 0;
	while (cur <= 1130) {
		bool found = false;
		while (i < N && v[i].first <= cur) {
			if (v[i].second > end) {
				end = v[i].second;
				found = true;
			}
			i++;
		}

		if (!found) {
			cout << 0;
			return 0;
		}

		count++;
		cur = end;
	}

	cout << count;
}