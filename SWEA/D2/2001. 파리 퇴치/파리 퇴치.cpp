#include<iostream>

using namespace std;

static int arr[15][15];
int N, M;

int max(int a, int b)
{
	if (a < b) return b;
	return a;
}

int catch_fly(int row, int col)
{
	int count = 0;

	if (row + M > N || col + M > N) return -1;

	for (int i = row; i < row + M; i++)
	{
		for (int j = col; j < col + M; j++)
		{
			count += arr[i][j];
		}
	}

	return count;
}

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		int ans = -1;
		cin >> N >> M;
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < N * N; i++)
		{
			int top_left_row = i / N;
			int top_left_col = i % N;

			ans = max(ans, catch_fly(top_left_row, top_left_col));
		}

		cout << "#" << test_case << " " << ans << "\n";
	}
}