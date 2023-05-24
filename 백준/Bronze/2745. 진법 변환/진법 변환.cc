//2745

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	string n;
	int b;
	cin >> n >> b;

	int result = 0;
	for (int i = 0; i < n.length(); i++) {
		if(int(n[i] < 58))
			result += int(n[i] - 48) * pow(b, n.length() - 1 - i);
		else
			result += int(n[i] - 55) * pow(b, n.length() - 1 - i);
	}

	cout << result;
}