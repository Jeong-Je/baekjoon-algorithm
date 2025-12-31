#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;

int arr[1000001];
int dis[1000001];

void bfs(int start);

int main()
{
	cin >> F >> S >> G >> U >> D;

	bfs(S);

	return 0;
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);

	dis[start] = 1;


	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		if (x == G)
		{
			cout << dis[x] - 1;
			return;
		}

		for (int i = 0; i < 2; i++)
		{
			int nx;
			if (i == 0) nx = x + U;
			else nx = x - D;

			if (nx <= 0 || nx > F) continue;
			if (dis[nx]) continue;

			dis[nx] = dis[x] + 1;
			q.push(nx);
		}
	}

	cout << "use the stairs";
}