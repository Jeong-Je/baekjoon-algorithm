#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quickSort(vector<int>& v, int s, int e, int k);
int partition(vector<int>& v, int s, int e);
void swap(vector<int>& v, int s, int e);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<int> v(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	quickSort(v, 0, n - 1, k - 1);
	cout << v[k - 1];
}

void quickSort(vector<int>&v, int s, int e, int k) {
	int pivot = partition(v, s, e);
	if (pivot == k) {
		return;
	}
	else if (k < pivot) {
		quickSort(v, s, pivot - 1, k);
	}
	else {
		quickSort(v, pivot + 1, e, k);
	}
}

int partition(vector<int>& v, int s, int e) {
	if (s + 1 == e) {
		if (v[s] > v[e])swap(v, s, e);
		return e;
	}

	int m = (s + e) / 2;
	swap(v, s, m);
	int pivot = v[s];
	int i = s + 1;
	int j = e;

	while (i <= j) {
		while (pivot < v[j] && j>0)j--;
		while (pivot > v[i] && i < v.size()-1)i++;
		if (i <= j)swap(v, i++, j--);
	}
	v[s] = v[j];
	v[j] = pivot;

	return j;
}

void swap(vector<int>& v, int s, int e) {
	int temp = v[s];
	v[s] = v[e];
	v[e] = temp;
}