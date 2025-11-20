#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int check[10][2];
int cnt[10];

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		// 배열 0으로 초기화 
		memset(check, 0, sizeof(check));
		memset(cnt, 0, sizeof(cnt));

		bool ok = true;

		string n_str;
		cin >> n_str;

		for (int i = 0; i < n_str.size(); i++)
		{
			int n = n_str[i] - '0';

			// 처음 등장하는 숫자라면 
			if (cnt[n] == 0)
			{
				check[n][0] = i;
				cnt[n]++;
			}

			// 처음 등장하는 숫자가 아니라면
			else
			{
				// 이미 두 번 등장한 숫자라면
				if (cnt[n] >= 2)
				{
					cout << "no\n";
					ok = false;
					break;
				}


				// 사이에 있는 숫자 개수가 n이 아니라면
				if (i - check[n][0] - 1 != n)
				{
					cout << "no\n";
					ok = false;
					break;
				}
				else
				{
					check[n][1] = i;
					cnt[n]++;
				}
			}
		}

		// 숫자가 1개만 등장한 경우가 있는지 확인 
		if (ok)
		{
			for (int i = 0; i < 10; i++)
			{
				if (cnt[i] != 0 && cnt[i] != 2)
				{
					ok = false;
					cout << "no\n";
					break;
				}
			}
		}


		if (ok)
		{
			cout << "yes\n";
		}
	}
}