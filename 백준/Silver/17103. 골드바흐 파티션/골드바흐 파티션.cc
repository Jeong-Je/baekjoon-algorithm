// 17103

#include <iostream>
#define MAX 1000001
using namespace std;


bool FalseIsPrimeNum[MAX] = { true, true };

int GoldBachConjecture(int n) {
	int cnt = 0;

	for (int i = 2; i <= n/2; i++)
		if (!FalseIsPrimeNum[i] && !FalseIsPrimeNum[n - i])cnt++;

	return cnt;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t, n;
	cin >> t;

	for (int i = 2; i < MAX; i++) {
		if (!FalseIsPrimeNum[i]) {
			for (int j = i+i; j < MAX; j+=i)
				FalseIsPrimeNum[j] = true;
		}
	}

	while(t--){
		cin >> n;
		cout << GoldBachConjecture(n) << "\n";
	}
	return 0;
}