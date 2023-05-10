//10810
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
		basket[i] = i;
	}

	int i, j;
	for (int u = 0; u < M; u++) {
		std::cin >> i >> j;
		if(i != j)swap(basket[i-1], basket[j-1]);
	}

	for (int i = 0; i < N; i++)
		std::cout << basket[i]+1<<" ";

	delete[] basket;

	return 0;
}