// 10814

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class member {
public:
	int age;
	string name;
};

bool compare(member a, member b) {
	return a.age < b.age;
}

int main() {
	int n;
	cin >> n;
	member* m = new member[n];

	for (int i = 0; i < n; i++)
		cin >> m[i].age >> m[i].name;

	stable_sort(m, m + n, compare);

	for (int i = 0; i < n; i++) 
		cout << m[i].age << " " <<m[i].name << "\n";

	return 0;
}