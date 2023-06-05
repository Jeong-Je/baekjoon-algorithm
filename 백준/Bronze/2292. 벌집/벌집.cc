//2292

#include <iostream>

using namespace std;

int main() {
	int n, dis = 1;
	int dmp = 1;
	cin >> n;
	for (int i = 1; dmp < n;i++) {
		dmp += i * 6;
		dis++;
	}
	cout << dis;
}

// 1 -> 6 -> 12 -> 18 -> 24 -> 30 -> 36
// 1 -> 7 -> 19 -> 37 -> 61