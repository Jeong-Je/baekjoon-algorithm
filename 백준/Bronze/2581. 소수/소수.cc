// 2581

#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
	if (n == 1)return false;
	for (int i = 2; i < n; i++) 
		if (n % i == 0)return false;
	return true;
	
}

int main() {
	int n, m,sum=0;
	cin >> m >> n;
	vector<int> v;
	for (int i=m; i <= n; i++) {
		if (isPrime(i))v.push_back(i);
	}
	if (v.size() == 0)
		cout << "-1";
	else {
		for (int i = 0; i < v.size(); i++)
			sum += v.at(i);
		cout << sum<<"\n";
		cout << v.at(0);
	}


	return 0;
}