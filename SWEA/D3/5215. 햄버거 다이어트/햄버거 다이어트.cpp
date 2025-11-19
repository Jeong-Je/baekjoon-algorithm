#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		int N, L;
		cin >> N >> L;

		int score[101] = { 0, };
		int calorie[101] = { 0, };
		int dp[21][10001]= { 0, };

		for (int i = 1; i <= N; i++)
		{
			cin >> score[i] >> calorie[i];
		}

		for (int limit = 1; limit <= L; limit++)
		{
			for (int j = 1; j <= N; j++)
			{
				// 담을 수 없는 경우 
				if (calorie[j] > limit)
				{
					dp[j][limit] = dp[j - 1][limit];
				}

				// 담을 수 있는 경우
				else
				{
					dp[j][limit] = max(dp[j - 1][limit], dp[j - 1][limit - calorie[j]] + score[j]);
				}
			}
		}

		cout << "#" << test_case << " " << dp[N][L] << "\n";
	}
}