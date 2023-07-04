// 24313
#include <iostream>
using namespace std;

int main() {
	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;
	(a1 * n0 + a0 <= c * n0 && a1 <= c) ? cout << 1 : cout << 0;
} 