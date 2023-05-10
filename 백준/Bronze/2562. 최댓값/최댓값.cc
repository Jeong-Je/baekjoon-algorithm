//2562
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int max=0;
	int n,cnt;

	for (int i = 0; i < 9; i++) {
		cin >> n;

		if (max < n) {
			max = n; 
			cnt = i+1;
		}
	}

	cout << max << "\n" << cnt;

	return 0;
}