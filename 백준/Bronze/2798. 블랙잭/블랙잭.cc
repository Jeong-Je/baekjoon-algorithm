// 2798

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	int goal;
	int max = 0;
	int sum = 0;

	cin >> n >> goal;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v.at(i);
	}

	for(int i=0;i<n-2;i++)
		for(int j=i+1;j<n-1;j++)
			for (int k = j + 1; k < n; k++) {
				sum = v[i] + v[j] + v[k];
				if (sum <= goal && sum > max)max = sum;
			}

	cout << max;
}