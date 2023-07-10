// 2750

#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &v, int n) {
	int i,j,key;

	for (i = 1; i < n; i++) {
		key = v[i];

		for (j = i - 1; j >= 0 && v[j] > key; j--) {
			v[j + 1] = v[j];
		}

		v[j + 1] = key;
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v.at(i);
	}

	insertion_sort(v, n);

	for (int i = 0; i < n; i++) {
		cout << v.at(i) << "\n";
	}

}