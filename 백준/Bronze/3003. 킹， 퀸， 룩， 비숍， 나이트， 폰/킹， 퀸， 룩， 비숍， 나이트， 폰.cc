//3003
#include <iostream>
#include <vector>


using namespace std;

int main() {
	int chess[6];
	int count[6] = { 1, 1, 2, 2, 2, 8 };

	for (int i = 0; i < 6; i++) {
		cin >> chess[i];
		cout << count[i] - chess[i] << " ";
	}

}



