#include <iostream>
#include <deque>

using namespace std;

typedef pair<int, int> node;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l;
    cin >> n >> l;
    deque<node> dq;

    for (int i = 0; i < n; i++) {
        int now;
        cin >> now;

        // 제일 작은 수를 앞에 두겠어
        while (dq.size() && dq.back().first >= now)
            dq.pop_back();

        dq.push_back(node(now, i));

        if (dq.front().second <= i - l)
            dq.pop_front();

        cout << dq.front().first << " ";
    }

}