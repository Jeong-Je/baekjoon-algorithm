//3003
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;



int main() {
	int N, M;
	cin >> N >> M;
	vector<int> v;
	for (int idx = 0; idx < N; idx++) {
		v.push_back(idx + 1);
	}

	int i, j, k;
	for (int idx = 0; idx < M; idx++) {
		cin >> i >> j >> k;
		rotate(v.begin() + i - 1, v.begin() + k - 1, v.begin() + j);
	}
	for (int i = 0; i < N; i++) {
		cout << v[i] << " ";
	}
}



