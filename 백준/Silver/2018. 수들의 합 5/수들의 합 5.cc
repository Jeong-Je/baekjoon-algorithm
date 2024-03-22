#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, count = 1;
	cin >> n;

	int start = 1, end = 1;

	int sum = 0;
	
	while (start != n) {
		if (sum == n) {
			count++;
			start++;
			end = start;
			sum = 0;
		}
		else if (sum > n) {
			start++;
			end = start;
			sum = 0;
		}
		else {
			sum += end;
			end++;
		}
	}
	
	cout << count;


}