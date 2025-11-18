#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

int n, turn_count, ans = -1;
string n_str;

unordered_set<string> visited[11];

void dfs(int cnt);
void swap();
int main(int argc, char** argv)
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ans = -1;
		cin >> n >> turn_count;

		n_str = to_string(n);
		
		for (int i = 0; i <= 10; i++) visited[i].clear();
		
		dfs(0);


		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;

}

void swap(int idx1, int idx2)
{
	char a = n_str[idx1];
	n_str[idx1] = n_str[idx2];
	n_str[idx2] = a;
}


void dfs(int cnt)
{
	if (cnt == turn_count)
	{
		ans = ans > stoi(n_str) ? ans : stoi(n_str);
		return;
	}
	
	if (visited[cnt].count(n_str)) return;
	visited[cnt].insert(n_str);


	for (int i = 0; i < n_str.size(); i++)
	{
		for (int j = i + 1; j < n_str.size(); j++)
		{
			swap(i, j);
			dfs(cnt + 1);
			swap(i, j);
		}
	}
}