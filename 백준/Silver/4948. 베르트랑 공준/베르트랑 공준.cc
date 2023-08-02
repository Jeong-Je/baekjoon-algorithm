// 4948

#include <iostream>
#include <cmath>
using namespace std;

int arr[246913];



int main() {
	int n,cnt;
	while (true) {
		cnt = 0;
		cin >> n;
		if (n == 0)break;
		for (int i = n+1; i <= 2 * n; i++) {
			arr[i] = 1;
		}

		// n+1 ~ 2n
		for (int i = 2; i <= 2 * n; i++) {
			for (int j = 2; i*j <= 2 * n; j++) {
				arr[i * j] = 0;
			}
		}

		for (int i = n + 1; i <= 2 * n; i++)
			if (arr[i])cnt += 1;
		cout << cnt<<"\n";
	}
	return 0;
}