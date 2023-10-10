// 2470

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) 
		cin >> v[i];

	sort(v.begin(), v.end());

	int start = 0;
	int end = n - 1;

	int min = abs(v.at(start) + v.at(end));

	vector<int> result(2);
	result[0] = v.at(start);
	result[1] = v.at(end);

	while (start < end) {
		int sum = v.at(start) + v.at(end);

		if (abs(sum) < min) {
			min = abs(sum);
			result[0] = v.at(start);
			result[1] = v.at(end);

			if (min == 0)break;
		}

		if (sum < 0)
			start++;
		else
			end--;
	}

	cout << result.at(0) << " " << result.at(1);

	return 0;
}