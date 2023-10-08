// 2023
#include <iostream>
#include <cmath>

using namespace std;

static int n;

void DFS(int num, int digit);
bool isPrime(int num);


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	DFS(2, 1); // 소수, 해당 소수의 자릿수
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);

	return 0;
}


void DFS(int num, int digit) {
	if (digit == n) {
		if (isPrime(num)) {
			cout << num << "\n";
		}
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (i % 2 == 0 || i == 5)continue;
		if (isPrime(num * 10 + i)) {
			DFS(num * 10 + i, digit + 1);
		}
	}

}

bool isPrime(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}