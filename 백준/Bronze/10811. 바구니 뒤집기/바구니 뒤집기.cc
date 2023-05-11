//10811
#include <iostream>
#include <string>

void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}




int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int N, M;
	std::cin >> N >> M;
	int* basket = new int[N];

	for (int i = 0; i < N; i++) {
		basket[i] = i+1;
	}

	int i, j, cnt;
	for (int u = 0; u < M; u++) {
		std::cin >> i >> j;
		cnt = (j - i + 1) / 2;
		for (int x = 0; x < cnt;x++) {
			swap(basket[i-1], basket[j-1]);
			i++, j--;
		}
	}

	for (int i = 0; i < N; i++) {
		std::cout << basket[i] << " ";
	}




	return 0;
}