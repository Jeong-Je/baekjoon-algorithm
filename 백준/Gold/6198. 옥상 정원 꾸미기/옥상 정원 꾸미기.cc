#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int N;
	long long ans = 0;
	cin >> N;

	vector<int> height(N);

	stack<pair<int,int>> stk;

	for (int i = 0; i < N; i++)
	{
		cin >> height[i];		
	}

	// height 배열의 뒤부터 처리 
	for (int i = N - 1; i > -1; i--)
	{
		int cnt = 0;
		if (stk.empty())
		{
			stk.push({ height[i], 0 });
		}

		else
		{
			while (stk.empty() == false)
			{
				if (stk.top().first < height[i])
				{
					cnt++;
					cnt += stk.top().second;

					stk.pop();
				}
				else
				{
					break;
				}
			}
		
			stk.push({ height[i], cnt });
			ans += cnt;
		}
	}


	cout << ans;

}