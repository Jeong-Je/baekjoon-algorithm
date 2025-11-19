#include <iostream>
#include <cstring>
using namespace std;

char map[50][50] = { 0, };

int main()
{
	int T;
	cin >> T;


	for (int test_case = 1; test_case <= T; test_case++)
	{
		int H, W, row_count = 0, column_count = 0;
		cin >> H >> W;

		memset(map, 0, sizeof(map));


		bool is_all_black = true;
		for (int i = 0; i < H; i++)
		{
			bool check = true;
			for (int j = 0; j < W; j++)
			{
				cin >> map[i][j];
				
				if (map[i][j] == '.') { check = false; is_all_black = false; }
			}

			if (check) row_count++;
		}



		// 세로 줄 확인하기
		for (int i = 0; i < W; i++)
		{
			bool check = true;
			for (int j = 0; j < H; j++)
			{
				if (map[j][i] == '.') check = false;
			}

			if (check)column_count++;
		}
		
		if (is_all_black)
		{
			if (row_count > column_count) cout << column_count << "\n";
			else cout << row_count << "\n";
		}
		else
		{
			cout << row_count + column_count << "\n";
		}
	}
}