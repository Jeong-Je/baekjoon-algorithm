#include <iostream>
#include <cstring>

using namespace std;

int arr[10][10];
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };
int N;

// 시계 방향으로 움직이기 때문에 움직임의 순서는
// 1. 오른쪽
// 2. 아래쪽
// 3. 왼쪽
// 4. 위쪽
// 5. 오른쪽
enum move
{
	m_right, // 0
	m_down,	 // 1
	m_left,  // 2
	m_up,    // 3
};

void move(int row, int col, int dir, int num);

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		memset(arr, 0, sizeof(arr));

		cin >> N;

		move(0, 0, m_right, 1);

		cout << "#" << test_case << "\n";
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
	}
}


void move(int row, int col, int dir, int num)
{
	arr[row][col] = num;

	// 다 채워졌으면 끝 
	if (num == N * N)
	{
		return;
	}

	int next_r = row + dr[dir];
	int next_c = col + dc[dir];

	// 다음 칸이 유효 인덱스 범위를 넘어서거나 이미 채워진 칸에 접근하려고 할 때 
	if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= N || arr[next_r][next_c])
	{
		// 기존 오른쪽 방향은 아래쪽으로 변경 
		if (dir == m_right)
		{
			next_r = row + dr[m_down];
			next_c = col + dc[m_down];

			dir = m_down;
		}

		else if (dir == m_down)
		{
			next_r = row + dr[m_left];
			next_c = col + dc[m_left];

			dir = m_left;
		}

		else if (dir == m_up)
		{
			next_r = row + dr[m_right];
			next_c = col + dc[m_right];

			dir = m_right;
		}
		
		else if (dir == m_left)
		{
			next_r = row + dr[m_up];
			next_c = col + dc[m_up];

			dir = m_up;
		}
		move(next_r, next_c, dir, num + 1);
	}

	// 다음 칸이 유효하고 비어있을 때 
	else
	{
		move(next_r, next_c, dir, num + 1);
	}
	
}