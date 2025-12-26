/*
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

*/
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N;
	cin >> N;

	queue<int> q;

	for (int i = 0; i < N; i++)
	{
		string cmd;
		cin >> cmd;

		if (cmd == "push")
		{
			int x;
			cin >> x;
			q.push(x);
		}
		else if (cmd == "pop")
		{
			if (q.empty()) cout << "-1\n";
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (cmd == "size")
		{
			cout << q.size() << '\n';
		}
		else if (cmd == "empty")
		{
			if (q.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (cmd == "front")
		{
			if (q.empty()) cout << "-1\n";
			else cout << q.front() << "\n";
		}
		else if (cmd == "back")
		{
			if (q.empty()) cout << "-1\n";
			else cout << q.back() << "\n";
		}
	}
}