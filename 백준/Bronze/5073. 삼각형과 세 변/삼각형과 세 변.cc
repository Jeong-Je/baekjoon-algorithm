// 5073

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int s1, s2, s3;
	while (true) {
		cin >> s1 >> s2 >> s3;
		int sum = s1 + s2 + s3;
		if (s1 == 0 && s2 == 0 && s3 == 0)
			break;
		else if (sum  <= 2*max({ s1, s2, s3 }))
			cout << "Invalid" << "\n";
		else if (s1 == s2 && s2 == s3)
			cout << "Equilateral" << "\n";
		else if (s1 != s2 && s2 != s3 && s3 != s1)
			cout << "Scalene" << "\n";
		else
			cout << "Isosceles" << "\n";
	}

	return 0;
}