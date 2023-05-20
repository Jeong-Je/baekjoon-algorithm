//25206
#include <iostream>
#include <cstring>

using namespace std;

class score {
public:
	char subject[50]; //과목 이름
	float credit; // 과목의 학점
	char grade[2]; // 내가 받은 등급
};

int main() {
	score scores[20];
	float total_credit = 0;
	float total_grade = 0;
	for (int i = 0; i < 20; i++) {
		cin >> scores[i].subject >> scores[i].credit >> scores[i].grade;
		if (strcmp(scores[i].grade, "A+") == 0)
			total_grade += (float)4.5 * scores[i].credit;
		else if (strcmp(scores[i].grade, "A0") == 0)
			total_grade += (float)4.0 * scores[i].credit;
		else if (strcmp(scores[i].grade, "B+") == 0)
			total_grade += (float)3.5 * scores[i].credit;
		else if (strcmp(scores[i].grade, "B0") == 0)
			total_grade += (float)3.0 * scores[i].credit;
		else if (strcmp(scores[i].grade, "C+") == 0)
			total_grade += (float)2.5 * scores[i].credit;
		else if (strcmp(scores[i].grade, "C0") == 0)
			total_grade += (float)2.0 * scores[i].credit;
		else if (strcmp(scores[i].grade, "D+") == 0)
			total_grade += (float)1.5 * scores[i].credit;
		else if (strcmp(scores[i].grade, "D0") == 0)
			total_grade += (float)1.0 * scores[i].credit;
		else if (strcmp(scores[i].grade, "P") == 0)
			continue;
		else
			total_grade += (float)0.0 * scores[i].credit;

		total_credit += scores[i].credit;
	}

	cout <<(float)total_grade / (float)total_credit;

}