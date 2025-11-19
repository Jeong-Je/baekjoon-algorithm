#include <iostream>
#include <unordered_map>

using namespace std;


int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		int t_num, ans_count = -1, ans_num = -1;
		cin >> t_num;

		unordered_map<int, int> um;

		// 1000명 학생의 점수 입력 받기
		for (int i = 1; i <= 1000; i++)
		{
			int score;
			cin >> score;

			// 숫자가 map에 존재하는 경우 
			if (um.find(score) != um.end())
			{
				// 빈도 수 증가 
				um[score]++;
			}

			// 숫자가 map에 존재하지 않는 경우
			else
			{
				um[score] = 1;
			}
		}

		for (auto elem : um)
		{
			if (elem.second > ans_count)
			{
				ans_num = elem.first;
				ans_count = elem.second;
				
			}
			if (elem.second == ans_count && elem.first > ans_num)
			{
				ans_num = elem.first;
				ans_count = elem.second;
			}
		}

		cout << "#" << t_num << " " << ans_num << "\n";
	}
}