//10809
#include <string>
#include <iostream>

using namespace std;

int main() {
	string S;
	cin >> S;

	char alpabet[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int index[26];
	fill_n(index, 26, -1);


	for (int i = 0; i < S.length(); i++) {
		for (int j = 0; j < 26; j++) {
			if (S[i] == alpabet[j] && index[j] == -1) {
					index[j] = i;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << index[i] << " ";
	}
}