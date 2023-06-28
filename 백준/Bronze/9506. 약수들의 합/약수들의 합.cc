// 9506
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
	int n;
	for (;;) {
		vector<int> v;
		cin >> n;
		if (n == -1)break;
		for (int i = 1; i <= n; i++)
			if (n % i == 0)v.push_back(i);\
				if (accumulate(v.begin(), v.end(), 0) == 2 * n) {
					cout << n << " = ";
					for (int j = 0; j < v.size()-1; j++) {
						cout << v.at(j);
						if (j < v.size() - 2)cout << " + ";
					}
					cout << "\n";
		}
		else cout << n << " is NOT perfect." << "\n";
	}
	return 0;
}