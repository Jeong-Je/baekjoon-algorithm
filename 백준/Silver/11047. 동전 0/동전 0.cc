// 11047

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, coin, result=0;
	vector<int> v;
	cin >> n >> k;
	while (n--) {
		cin >> coin;
		if (coin > k)
			continue;
		v.push_back(coin);
	}
	for (int i = v.size()-1; i>-1; i--) {
		if (v.at(i) > k)continue;
		result += k / v.at(i);
		k %= v.at(i);
		if (k == 0)break;
	}

	cout << result;
	return 0;
}