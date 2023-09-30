// 1253

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,data;
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		cin >> data;
		v.push_back(data);
	}

	sort(v.begin(), v.end());

	int cnt = 0;

	for (int k = 0; k < n; k++) {
		long find = v.at(k);
		int i = 0;
		int j = n - 1;

		while (i < j) {
			if (v.at(i) + v.at(j) == find) {
				if (i != k && j != k) {
					cnt++; break;
				}
				else if (i == k) {
					i++;
				}
				else if (j == k) {
					j--;
				}
			}
			else if (v.at(i) + v.at(j) < find) {
				i++;
			}
			else {
				j--;
			}
		}
	}
	

	cout << cnt;
	return 0;
}