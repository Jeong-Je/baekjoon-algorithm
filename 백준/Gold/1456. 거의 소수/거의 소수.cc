#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long a, b;
	long count = 0;
	cin >> a >> b;

	long maxPrimeNumber = sqrt(b);
	vector<bool> v(maxPrimeNumber+1, true);


	for (long i = 2; i <= maxPrimeNumber; i++) {
		if (v[i] == true) {
			for (long j = i + i; j <= maxPrimeNumber; j = j + i) {
				if (j > maxPrimeNumber)break;
				v[j] = false;
			}
		}
	}


	for (long i = 2; i <= maxPrimeNumber; i++) {
		if (v[i]) {
			long temp = i;
			while ((double)i <= (double)b / (double)temp) {
				if ((double)i >= (double)a / (double)temp) {
					count++;
				}
				temp = temp * i;
			}
		}
	}


	cout << count;
	return 0;
}
