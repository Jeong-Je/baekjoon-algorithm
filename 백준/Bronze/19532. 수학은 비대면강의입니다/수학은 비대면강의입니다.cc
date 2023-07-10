// 19532

#include <iostream>
using namespace std;


class equ {
public:
	int x;
	int y;
	int sum;
};


int main() {
	equ eq1, eq2;
	cin >> eq1.x >> eq1.y >> eq1.sum;
	cin >> eq2.x >> eq2.y >> eq2.sum;

	for (int i = -999; i <= 999; i++) {
		for (int j = -999; j <= 999; j++) {
			if (i * eq1.x + j * eq1.y == eq1.sum &&
				i * eq2.x + j * eq2.y == eq2.sum) {
				cout << i << " " << j;
				return 0;
			}
		}
	}

	return 0;
}