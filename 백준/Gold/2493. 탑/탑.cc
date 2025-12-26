#include <iostream>
#include <stack>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	stack<pair<int,int>> stack;

	for (int i = 1; i <= N; i++)
	{
		int height;
		cin >> height;

		// 스택이 비어 있으면 
		if (stack.empty() == true)
		{
			cout << "0 ";
			stack.push({height, i});
		}

		else
		{
			int s_top_height = stack.top().first;
			int s_top_index = stack.top().second;

			if (s_top_height >= height)
			{
				cout << s_top_index << ' ';
			}

			else
			{
				while (stack.empty() == false && stack.top().first < height)
				{
					stack.pop();
				}

				if (stack.empty())
				{
					cout << "0 ";
				}
				else
				{
					cout << stack.top().second << ' ';
				}
			}

			stack.push({ height, i });
		}
	}
}