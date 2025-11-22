#include <iostream>
#include <cstring>

using namespace std;

int dp[13];

int min(int a, int b)
{
	if (a < b)return a;
	else return b;
}

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		memset(dp, 0, sizeof(dp));

		int day_cost, month_cost, three_month_cost, year_cost;
		cin >> day_cost >> month_cost >> three_month_cost >> year_cost;

		for (int i = 1; i <= 12; i++)
		{
			int use;
			cin >> use;

			dp[i] = min(day_cost * use + dp[i-1], month_cost + dp[i-1]);

			if (i >= 3)
			{
				dp[i] = min(dp[i], dp[i - 3] + three_month_cost);
			}
		}

		int ans = dp[12];

		if (dp[12] > year_cost) ans = year_cost;

		cout << "#" << test_case << " " << ans << "\n";
	}
}