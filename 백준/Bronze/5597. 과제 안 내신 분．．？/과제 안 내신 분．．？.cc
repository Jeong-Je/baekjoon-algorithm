//5597
#include <iostream>
#include <string>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int student[30];
	std::fill(student, student + 30, 0);
	int submit_student;
	for (int i = 0; i < 28; i++) {
		std::cin >> submit_student;
		student[submit_student - 1] = 1;
	}

	for (int i = 0; i < 30; i++) {
		if (student[i] == 0) {
			std::cout << i + 1<<"\n";
		}
	}

	return 0;
}