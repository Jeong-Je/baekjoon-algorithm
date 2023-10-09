// 11729

#include <iostream>

using namespace std;

void hanoi(int n, int start, int mid, int end);

int main() {
	int n;
	cin >> n;
	cout << (1 << n) - 1 << "\n";
	hanoi(n, 1, 2, 3);
	return 0;
}

void hanoi(int n, int start, int mid, int end) {
	if (n == 1) {
		cout << start << " " << end << "\n";
		return;
	}
	hanoi(n - 1, start, end, mid);
	cout << start << " " << end << "\n";
	hanoi(n - 1, mid, start, end);
}