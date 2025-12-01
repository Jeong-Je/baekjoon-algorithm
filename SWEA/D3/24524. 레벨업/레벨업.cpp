#include <iostream>
#include <climits>

using namespace std;

int check_point[50];

int abs(int a)
{
	if (a < 0) return -a;
	return a;
}

int min(int a, int b)
{
	if (a < b) return a;
	return b;
}

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		int N, ans = INT_MAX;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> check_point[i];
		}

		
		for (int pass = 1; pass < N - 1; pass++)
		{
			int dis = 0;
			for (int i = 1; i < N; i++)
			{
				if (i == pass) continue;

				int now = i;
				int pre = i - 1;

				if (i - 1 == pass)
				{
					pre = i - 2;
				}

				dis += abs(check_point[now] - check_point[pre]);
			}

			ans = min(dis, ans);
		}

		cout << ans << "\n";
	}
}