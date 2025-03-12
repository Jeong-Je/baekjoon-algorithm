#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int arr[9];

	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	int diff = sum - 100;

	bool end = false;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (arr[i] + arr[j] == diff) {
				arr[i] = 0; 
				arr[j] = 0;
				end = true;
				break;
			}
		}
		if (end)break;
	}

	sort(arr, arr + 9);

	for (int i = 2; i < 9; i++) {
		cout << arr[i] << "\n";
	}

}