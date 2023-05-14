//11718
#include <iostream>
#include <string>

using namespace std;

int main() {
	string input;
	int i = 0;
	while (i<100) {
		getline(cin, input);
		if (input == "")break;
		cout << input<<"\n";
	}
	i++;

}