// 10101

#include <iostream>

using namespace std;

int main() {
	int a1, a2, a3;
	cin >> a1 >> a2 >> a3;
	int sum = a1 + a2 + a3;
	if (a1 == 60 && a2 == 60 && a3 == 60)
		cout << "Equilateral";
	else if (sum == 180 && a1 != a2 && a2 != a3 && a3 != a1)
		cout << "Scalene";
	else if (sum == 180)
		cout << "Isosceles";
	else
		cout << "Error";

	return 0;
}