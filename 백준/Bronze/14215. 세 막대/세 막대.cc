// 5073

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int sum = a + b + c;
	if (a == b && b == c)
		cout << 3 * a;
	else if (sum > 2 * max({ a,b,c, }))
		cout << a + b + c;
	else
		cout<< 2 * (sum - max({ a,b,c })) - 1;

	return 0;
}