#include <iostream>

using namespace std;

char board[20][20];

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		int N;
		cin >> N;

		bool bingo = false;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> board[i][j];
			}
		}

		for (int i = 0; i < N; i++)
		{
			if (bingo) break;
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] == 'o')
				{
					// 오른쪽 5개 검사
					if (j + 4 < N)
					{
						if (board[i][j + 1] == 'o' && board[i][j + 2] == 'o'
							&& board[i][j + 3] == 'o' && board[i][j + 4] == 'o')
						{
							bingo = true;
							break;
						}
					}

					// 아래쪽 5개 검사 
					if (i + 4 < N)
					{
						if (board[i+1][j] == 'o' && board[i+2][j] == 'o'
							&& board[i+3][j] == 'o' && board[i+4][j] == 'o')
						{
							bingo = true;
							break;
						}
					}

					// '\' 방향 대각선 아래 5개 검사
					if (i + 4 < N && j + 4 < N)
					{
						if (board[i + 1][j+1] == 'o' && board[i + 2][j+2] == 'o'
							&& board[i + 3][j+3] == 'o' && board[i + 4][j+4] == 'o')
						{
							bingo = true;
							break;
						}
					}

					// '/' 방향 대각선 아래 5개 검사
					if (i + 4 < N && j - 4 < N)
					{
						if (board[i + 1][j -1] == 'o' && board[i + 2][j -2] == 'o'
							&& board[i + 3][j -3] == 'o' && board[i + 4][j -4] == 'o')
						{
							bingo = true;
							break;
						}
					}
				}
			}
		}

		if (bingo)
		{
			cout << "#" << test_case << " " << "YES\n";
		}
		else
		{
			cout << "#" << test_case << " " << "NO\n";
		}
	}
}