#include <iostream>
#include <set>

using namespace std;

int arr[101];
int parent[101];

void funion(int, int);
int find(int);

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		int N, M;
		cin >> N >> M;

		for (int i = 1; i <= N; i++)
		{
			parent[i] = i;
		}


		for (int i = 1; i <= M; i++)
		{
			int a, b;
			cin >> a >> b;

			funion(a, b);
		}

		for (int i = 1; i <= N; i++)
		{
			find(i);
		}

		set<int> s;
		for (int i = 1; i <= N; i++)
		{
			s.insert(parent[i]);
		}

		cout << "#" << test_case << " " << s.size() << "\n";
	}
}

void funion(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
	{
		parent[b] = a;
	}
}


int find(int a)
{
	if (parent[a] == a) return a;
	else return parent[a] = find(parent[a]);
}