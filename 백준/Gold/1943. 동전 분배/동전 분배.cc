#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int dp[101][100001];
vector<pair<int, int>> v;

int DP(int idx, int price)
{
    if (price < 0) return 0;
    if (idx == N) return price == 0;

    int &ret = dp[idx][price];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 0; i <= v[idx].second; i++)
    {
        ret = max(ret, DP(idx + 1, price - v[idx].first * i));
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int t = 0; t < 3; t++)
    {
        int ans;
        int sum = 0;
        cin >> N;

        v.resize(N);
        for (int i = 0; i < N; i++)
        {
            cin >> v[i].first >> v[i].second;

            sum += v[i].first * v[i].second;
        }

        if (sum % 2 == 1)
        {
            ans = 0;
        }
        else
        {
            memset(dp, -1, sizeof(dp));
            ans = DP(0, sum / 2);
        }

        cout << ans << "\n";
    }
}