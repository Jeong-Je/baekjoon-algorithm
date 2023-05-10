//10810
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	int* basket = new int[N]();

	int i, j, k;
	for (int z = 0; z < M; z++) {
		cin >> i >> j >> k;
		for (int u = i - 1; u <= j - 1; u++) {
			if (basket[u] != 0)basket[u] = 0;
			basket[u] = k;
		}
	}

	for (int i = 0; i < N; i++)
		cout << basket[i]<<" ";

	delete[] basket;

	return 0;
}